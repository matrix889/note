%{
	int words = 0;
	int lines = 0;
	int chars = 0;
%}

%%

[a-zA-Z]+ { ++words; chars += strlen(yytext);}
\n       { ++lines; }
.        { ++chars; }

%%

