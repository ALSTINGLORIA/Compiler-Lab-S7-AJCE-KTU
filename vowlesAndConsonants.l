%{
#include<stdio.h>
#include<stdlib.h>
int v = 0;
int c = 0;
%}

%%

[aeiouAEIOU] {v++;}
[a-zA-Z] {c++;}

%%
 
void main(){
    printf("enter the string:");
    yylex();
    printf("the No of vowels = %d \n no of consonants = %d",v,c);
}

int yywrap(){
    return 1;
}
