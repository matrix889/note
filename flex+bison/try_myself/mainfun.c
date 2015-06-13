#include <stdio.h>
int main(){
    yylex();
    printf("%8d%8d%8d\n", words, lines, chars);
    return 0;
}
