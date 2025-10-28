%{
#include<stdio.h>
#include<stdlib.h>
int pc = 0;
int sc = 0;
extern FILE *yyin;
%}

%%
"printf" {printf("writef");pc++;}
"scanf" {printf("readf"); sc++;}
. {putchar(yytext[0]);}
%%

void main(){
    FILE *file = fopen("sample.txt","r");
    yyin = file;
    yylex();
    fclose(file);
    printf("%d \t %d\n",pc,sc);
}

int yywrap(){
    return 1;
}
