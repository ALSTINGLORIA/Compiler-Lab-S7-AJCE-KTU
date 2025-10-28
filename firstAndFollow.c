#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int n=0,i=0;
char prod[10][10];

void First(char result[], char c){
    if(!isupper(c)){
        strncat(result,&c,1);
        return;
    }
    for(int i=0;i<n;i++){
        if(prod[i][0] == c){
            if(!isupper(prod[i][2])){
                strncat(result,&prod[i][2],1);
            }
            else{
                First(result,prod[i][2]);
            }
        }
    }
}

void Follow(char result[], char c){
    if(prod[0][0]==c){
        strcat(result,"$");
    }
    for(int i=0;i<n;i++){
        for(int j=2;j<strlen(prod[i]);j++){
            if(prod[i][j]==c){
                if(prod[i][j+1] != '\0'){
                    First(result, prod[i][j+1]);
                }
                else if(prod[i][j+1] != prod[i][0]){
                    Follow(result,prod[i][0]);
                }
            }
        }
    }
}

int main(){
    printf("enter the number of productions: ");
    scanf("%d",&n);
    printf("\n Enter the productions: \n");
    for(i=0;i<n;i++){
        scanf("%s", prod[i]);
    }
    printf("\n First \n ");
    for(i=0;i<n;i++){
        char c = prod[i][0];
        char first[20] = "";
        First(first,c);
        printf("First of %c = {%s} \n",c,first);
    }

    printf("\n Follow \n");
    for(i=0;i<n;i++){
        char c = prod[i][0];
        char follow[20] = "";
        Follow(follow,c);
        printf("Follow of %c = {%s} \n ",c,follow);
    }
}
