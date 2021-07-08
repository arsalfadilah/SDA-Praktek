#include <stdio.h>
#include "DynamicLinkedList.h"

void createInfo(List *Q, int n){
    infotype X, tempInfo;
    int TempWaktuStart, TempWaktuDatang;


    for(int i=0; i<n; i++){
        fflush(stdin);
        printf("CS ke - %d\n", i+1);
        printf("Nama  : ");
        scanf("%30[^\n]s", X.Nama);
        printf("Waktu Datang  : ");
        scanf("%d", &X.waktuDatang);
        printf("Jumlah Lembar : ");
        scanf("%d", &X.jumlahLEbar);
        X.waktuDilayani = 0;
        X.waktuSelesaiDilayani = 0;

        InsVLast(&(*Q), X);

        sortListQueue(&(*Q));

        //sortListList(&(*Q));

//        printf("\nShow Data :\n");
//        PrintInfo(*L);
//        system("pause");
//        system("cls");
    }
}

void proses(List Q, List *Q2){
    int i = 1;
    infotype X, temp;
    address ptr = Q.First;

    while(ptr != Nil){
        X = ptr->info;

        if(i==1){
            X.waktuDilayani = X.waktuDatang + 1;
            i++;
        } else{
            if(temp.waktuSelesaiDilayani > X.waktuDatang)
                X.waktuDilayani = temp.waktuSelesaiDilayani;
            else
                X.waktuDilayani = X.waktuDatang + 1;
        }

        X.waktuSelesaiDilayani = X.waktuDilayani + X.jumlahLEbar - 1;

        InsVLast(&(*Q2), X);

        temp = X;
        ptr = ptr->next;
    }
}

int main(){
    List Q, Q2;
    CreateList(&Q);
    CreateList(&Q2);
    int N;

    printf("Jumlah CS = ");
    scanf("%d", &N);

    system("pause");
    system("cls");

    createInfo(&Q, N);
    proses(Q, &Q2);

    PrintInfo(Q2);

    return 0;
}
