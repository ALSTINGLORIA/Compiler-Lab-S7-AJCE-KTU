#include<stdio.h>
#include<stdlib.h>
#include<string.h>




int main(){
    int inp_ptr = 0,sta_ptr = 0,temp_ptr = 0;
    char temp[4];
    char input[15], stack[15];
    printf("enter the input string:");
    scanf("%s",input);

    printf("%s\n", input);
    while(inp_ptr < strlen(input)){
        stack[sta_ptr] = input[inp_ptr];
        input[inp_ptr] = ' ';
        printf("Stack: %s \t Input: %s \n",stack,input);
        if(stack[sta_ptr]=='a' || stack[sta_ptr]=='b'){
            stack[sta_ptr] = 'E';
            printf("Stack: %s \t Input: %s \n",stack,input);
            sta_ptr++;
            inp_ptr++;
        }
        else if (stack[sta_ptr]=='*' || stack[sta_ptr]=='+' || stack[sta_ptr]=='/'){
            sta_ptr++;
            inp_ptr++;
            stack[sta_ptr] = input[inp_ptr];
            input[inp_ptr] = ' ';
            printf("Stack: %s \t Input: %s \n",stack,input);
            if(stack[sta_ptr]=='a' || stack[sta_ptr]=='b'){
                stack[sta_ptr] = 'E';
                printf("Stack: %s \t Input: %s \n",stack,input);
                inp_ptr++;
            }
            for(int i=sta_ptr-2;i<=sta_ptr;i++){
                temp[temp_ptr] = stack[i];
                temp_ptr++;
            }
            temp[temp_ptr] = '\0'; 
            temp_ptr = 0;
            if(strcmp(temp,"E+E")==0 || strcmp(temp,"E*E")==0 || strcmp(temp,"E/E")==0){
                stack[sta_ptr-1] = ' ';
                stack[sta_ptr] = ' ';
                sta_ptr = sta_ptr - 1;
            }
            printf("Stack: %s \t Input: %s \n",stack,input);
        }
        else{
            printf("Stack: %s \t Input: %s \n",stack,input);
            sta_ptr++;
            inp_ptr++;
        }
    }
    if(stack[0]=='E'){
        printf("Succesful Parsing \n ");
    }
    else{
        printf("failed Parsing");
    }
}
