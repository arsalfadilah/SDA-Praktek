#include "Stack.h"
#include <stdio.h>

int main()
{
    //buat penyimpanan
    Stack stack[5];
    int N;
    for (int i = 0; i < 5; i++)
    {
        /* code */
        CreateEmptyStack(&stack[i]);
        //stack 0 => penyimapanan sementara
        //stack 1 => troli 1
        //stack 2 => troli 3
        //stack 3 => bagasi lantai 1 (koper besar)
        //stack 4 => bagasi lantai 2 (koper kecil)
    }
    //masukan koper ke penyimapanan sementara berjumlah N
    printf("Berapa banyak koper ? "); scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        /* code */
        masukStack(&stack[0]);
    }
    //pemilihan koper besar dan kecil dan dimasukan ke troli 1 dan 2
    pecahStack(stack[0], &stack[1], &stack[2]);
    //pindahkan ke bagasi
    

    return 0;
}