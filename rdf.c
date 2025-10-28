#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char inp[20],lookahead;
int len = 0,e=0;

void T();
void E();
void Td();
void Ed();
void F();
void nexttoken();
void match(char a);

void T(){
    F();
    Td();
}

void E(){
    T();
    Ed();
}


void F(){
    if(isalpha(lookahead)){
        len++;
        nexttoken();
    }
    else if(lookahead=='('){
        match('(');
        E();
        if(lookahead==')'){
            match(')');
        }
        else{
            e = 1;
        }
    }
    else{
        e = 1;
    }
}

void Ed(){
    if(lookahead=='+'){
        match('+');
        T();
        Ed();
    }
}

void Td(){
    if(lookahead=='*'){
        match('*');
        F();
        Td();
    }
}

void nexttoken(){
    lookahead = inp[len];
}

void match(char a){
    if(lookahead == a){
        len++;
        nexttoken();
    }
    else{
        e = 1;
    }
}

void main(){

    printf("enter the string:");
    scanf("%s",&inp);
    nexttoken();
    E();
    if(e==0){
        printf("valid \n ");
    }
    else{
        printf("invalid \n");
    }
}
