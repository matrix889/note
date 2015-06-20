%{
#  include <stdio.h>
#  include <stdlib.h>
#  include "work.h"
%}

%union {
  struct ast *a;
  double d;
  struct symbol *s;		/* which symbol */
  struct symlist *sl;
  int fn;			/* which function */
}

/* declare tokens */
%token <d> NUMBER
%token <s> NAME
%token <fn> FUNC
%token EOL

%token IF THEN ELSE WHILE DO FUNCTION
%token AND OR


%nonassoc <fn> CMP
%right '='
%left '+' '-'
%left '*' '/'
%left AND OR
%nonassoc '|' UMINUS

%type <a> exp stmt list explist
%type <sl> symlist

%start calclist

%%

stmt: IF exp THEN '{' list '}'           { $$ = newflow('I', $2, $5, NULL); }
   | IF exp '{' list '}'   {
      yyerror("lack the THEN in the IF-STATEMENT!!!");
      $$ = newflow('I', $2, $4, NULL); 
   }
   | IF exp THEN '{' list '}' ELSE '{' list '}' { $$ = newflow('I', $2, $5, $9); }
   | IF exp '{' list '}' ELSE '{' list '}' { 
        yyerror("lack the THEN in the IF-STATEMENT!!!");
        $$ = newflow('I', $2, $4, $8); 
      }
   | IF exp THEN '{' list '}' '{' list '}' { 
      yyerror("lack the ELSE in the IF-STATEMENT!!!");
      $$ = newflow('I', $2, $5, $8); 
    }
   | WHILE exp DO '{' list '}'      { $$ = newflow('W', $2, $5, NULL); }
   | exp
;

list: /* nothing */ { $$ = NULL; }
   | stmt ';' list 
   			{ if ($3 == NULL)
	                $$ = $1;
                      else
			$$ = newast('L', $1, $3);
                    }
   ;

exp: exp CMP exp          { $$ = newcmp($2, $1, $3); }
   | exp '+' exp          { $$ = newast('+', $1,$3); }
   | exp '-' exp          { $$ = newast('-', $1,$3);}
   | exp '*' exp          { $$ = newast('*', $1,$3); }
   | exp '/' exp          { $$ = newast('/', $1,$3); }
   | exp AND exp        { $$ = newast('A', $1, $3); }
   | exp OR exp         { $$ = newast('O', $1, $3);}
   | '|' exp              { $$ = newast('|', $2, NULL); }
   | '(' exp ')'          { $$ = $2; }
   | '-' exp %prec UMINUS { $$ = newast('M', $2, NULL); }
   | NUMBER               { $$ = newnum($1); }
   | FUNC '(' explist ')' { $$ = newfunc($1, $3); }
   | NAME                 { $$ = newref($1); }
   | NAME '=' exp         { $$ = newasgn($1, $3); }
   | NAME '(' explist ')' { $$ = newcall($1, $3); }
;

explist: exp
 | exp ',' explist  { $$ = newast('L', $1, $3); }
;
symlist: NAME       { $$ = newsymlist($1, NULL); }
 | NAME ',' symlist { $$ = newsymlist($1, $3); }
;

calclist: /* nothing */
  | calclist stmt EOL {
    if(debug) dumpast($2, 0, 0);
     //printf("= %4.4g\n> ", eval($2));
      printf("= %4.4g\n", eval($2));
      printf("\n");
      treefree($2);
    }
  | calclist FUNCTION NAME '(' symlist ')' '{' list '}' EOL {
                       dodef($3, $5, $8);
                       //printf("Defined %s\n> ", $3->name); 
                       printf("Defined %s:\n", $3->name);
                       if (debug) dumpast($8, 1, 1);
                        printf("\n");
                       }

  | calclist error EOL { yyerrok; 
                          //printf("> "); 
                        }
 ;
%%
