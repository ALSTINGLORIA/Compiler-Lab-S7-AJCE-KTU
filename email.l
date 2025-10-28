%{
#include<stdio.h>
#include<stdlib.h>    
%}

%%
[a-zA-Z0-9_]+@[a-zA-Z0-9]+\.[a-zA-Z]+ {printf("valid email");}
[^\n] {printf("invalid email");}
\n {;}
%%

int main(){
    printf("enter the email:");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}
