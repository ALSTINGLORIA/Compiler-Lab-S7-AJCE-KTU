#include<stdio.h>
#include<stdlib.h>
int array[20][20],done[20];
int n = 0, t= 0, i = 0;
int s1 = 0, s2 = 0;
char trans;
void closure(int i){
    done[i] = 1;
    for(int j=0;j<n;j++){
        if(array[i][j]==1 && done[j] != 1){
            printf(",q%d",j);
            closure(j);
        }
    }
}

void main(){
    printf("enter the no of states:");
    scanf("%d",&n);
    printf("enter the number of trans:");
    scanf("%d",&t);
    printf("enter the transitions:");
    for(i=0;i<t;i++){
        scanf("%d %c %d",&s1,&trans,&s2);
        if(trans == 'e'){
            array[s1][s2] = 1;
        }
    }

    printf("Output : \n");
    for(i=0;i<n;i++){
        for(int j=0;j<n;j++){
            done[j] = 0;
        }
        printf("The epshilon closure of %d = {q%d",i,i);
        closure(i);
        printf("}\n");
    }
}
