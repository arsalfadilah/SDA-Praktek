#include<stdio.h>
#include"stackt.h"

int main(){
    Stack S;
    CreateEmpty(&S);

    int X;

    printf("Mengisi stack . . . .\n");
    for(int i = 1; i<=10 ; i++){
        Push(&S, i);
    }

    printf("Print Stack \n\n");
    printf("Jumlah ELEMENT = %d\n", nElem(S));
    printStack(S);

    printf("\n\nPop Step . . .\n");
    for(int i=1 ; i<=10; i++){
        Pop(&S, &X);
        printf("Jumlah ELEMENT = %d\n", nElem(S));
        printStack(S);
        printf("\n");
    }

    return 0;

}
