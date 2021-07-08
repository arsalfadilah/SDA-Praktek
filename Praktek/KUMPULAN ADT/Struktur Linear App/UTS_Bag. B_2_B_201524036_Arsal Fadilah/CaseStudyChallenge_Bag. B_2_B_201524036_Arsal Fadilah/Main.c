#include"List.h"
#include<string.h>
#include<stdio.h>
#include<Windows.h>

void inputAnggota(List *L){
    char endAnggota;
    Infotype X;

    //pertama kali :
    printf("Input Info Ketua Pramuka\n");
    InputInfo(&X);
    /*** Guard ***/
    X.pos.x = 1;
    X.pos.y = 1;
    InsVLast(&(*L), X);
    
    while (endAnggota != 'y')
    {
        /* code */
        printf("Input Info Anggota Pramuka\n");
        InputInfo(&X);
        InsVLast(&(*L), X);
        printf("TUTUP BARISAN (y/t) ? ");
        fflush(stdin);
        scanf("%c", &endAnggota);
    } 
}

void PrintAnggota(Infotype X){
    printf("Baris %d Kolom %d %s\n", X.pos.x, X.pos.y, X.Nama);
}

void JalankanIntruksi(List L){
    address Penunjuk  = L.First;
    int perintah1;
    char perintah2[10];
    char end;
    Infotype anggotaNext;
    
    while(end !='y'){
        system("cls");
        printf("Berikan Perintahmu !\n");
        fflush(stdin);
        scanf("%d %s", &perintah1, perintah2);
        //printf("perintah 1 : %d", perintah1);
        GetInfotypeByTask(L, perintah1, perintah2, &Penunjuk, &anggotaNext);
        PrintAnggota(Penunjuk->info);
        printf("STOP (y/t) ? ");
        fflush(stdin);
        scanf("%c", &end);
    }

}


int main(){
    
    //printf("Hello");
    
    //Inisialisasi
    List AnggotaPramuka;
    CreateList(&AnggotaPramuka);

    //Input Anggota Pramuka
    system("cls");
    inputAnggota(&AnggotaPramuka);

    //Jalankan Instruksi
    JalankanIntruksi(AnggotaPramuka);


    return 0;
}