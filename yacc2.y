%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
void yyerror(char *s);
%}

%token Var

%%
Start:
    Var {printf("valid");}
%%

int main(){
    printf("enter the variable:");
    yyparse();
    return 0;
}

void yyerror(char *msg){
    printf("error");
}
