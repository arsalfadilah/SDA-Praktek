#include<stdio.h>
#include"stack.h"

int main(){
    stack S;
    createstack(&S);

    int X;

    printf("Mengisi stack . . . .\n");
    for(int i = 1; i<=10 ; i++){
        push(&S, i);
    }

    printf("Print Stack \n\n");
    cetakstack(S);

    printf("\n\nPop Step . . .\n");
    for(int i=1 ; i<=10; i++){
        pop(&S, &X);
        cetakstack(S);
        printf("\n");
    }

    return 0;

}
