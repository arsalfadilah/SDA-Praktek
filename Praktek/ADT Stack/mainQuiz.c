#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include "list_queue.h"
#include "stackt.h"

int Menu(){
    int x;
//    printf("===================================\n");
//    printf("| Program By : Arsal Fadilah V.02 |\n");
    printf("===================================\n");
    printf("||     PENDAFTARAN VAKSINASI     ||\n");
    printf("||  1. Tambah Paket              ||\n");
    printf("||  2. Tampilkan Paket           ||\n");
    printf("||  3. Proses Paket              ||\n");
    printf("||  4. Exit                      ||\n");
//    printf("||  5. Verifikasi Peserta        ||\n");
//    printf("||  6. Exit                      ||\n");
    printf("\n  Pilih Menu : ");
    scanf("%d", &x);
    return x;
}

void MenuSortList(List L){
    int fitur;
    List newTipe;

    printf("Filter by category :\n");
    printf("1. Dosen\n");
    printf("2. Guru\n");
    printf("3. BUMN\n");
    printf("4. Lansia\n");

    printf("Choose : ");scanf("%d", &fitur);

    switch(fitur){
        case 1:
            newTipe = FCopyList(L);
            //del semua yang bukan dosen. yg lainnya pun sama
            DelP(&newTipe, "DOSEN");
            sortListQueue(&newTipe);
            PrintInfo(newTipe);
            break;
        case 2:
            newTipe = FCopyList(L);
            DelP(&newTipe, "GURU");
            sortListQueue(&newTipe);
            PrintInfo(newTipe);
            break;
        case 3:
            newTipe = FCopyList(L);
            DelP(&newTipe, "BUMN");
            sortListQueue(&newTipe);
            PrintInfo(newTipe);
            break;
        case 4:
            newTipe = FCopyList(L);
            DelP(&newTipe, "LANSIA");
            sortListQueue(&newTipe);
            PrintInfo(newTipe);
            break;
        default:
            printf("Wrong Input");
            break;
    }

    printf("\n[ Back To Menu ]\n");

}

void insertPeserta(List L, Stack *S){
    info X;

    fflush(stdin);
    printf("Nama Pengirim             : ");scanf("%34[^\n]", &X.NamaPengirim);
    fflush(stdin);
    printf("Alamat Pengirim           : ");scanf("%34[^\n]", &X.AlamatPengirim);
    fflush(stdin);
    printf("No. Hp Pengirim           : ");scanf("%34[^\n]", &X.No_hp_Pengirim);
    fflush(stdin);
    printf("Nama Penerima             : ");scanf("%34[^\n]", &X.NamaPenerima)
    fflush(stdin);
    printf("Alamat Penerima           : ");scanf("%34[^\n]", &X.AlamatPenerima);
    fflush(stdin);
    printf("No. Hp Penerima           : ");scanf("%34[^\n]", &X.No_hp_Penerima);
    fflush(stdin);


    Push(S, X);

    printf("Data berhasil disimpan");
}

void Verifikasi(Stack *S){
    info X;
    char choose='Y';

    while(choose=='Y' && !IsEmpty(*S)){
      printf("\nDaftar Paket Masuk\n");
      printStack(*S);
        X = InfoTop(*S);
        printf("\nLakukan Verifikasi untuk paket %s ? [Y/N] ", X.NamaPengirim);

        fflush(stdin);
        scanf("%c", &choose);

        if(choose=='Y'){
            Pop(S, &X);
        }
        printf("\n====================================\n");
    }

    if(IsEmpty(*S)){
        printf("\nPeserta yang sudah Registrasi\n");
        printf("[Tidak Ada]\n");
    }

}

int main(){
    char ActiveSortCategory;
    Stack Peserta;
    CreateEmpty(&Peserta);

    system("cls");

    int m;
    while((m = Menu()) != 4){
        switch(m){
            case 1:
                insertPeserta(pendaftar, &Peserta);
                break;
            case 2:
                printf("\nDaftar Paket Masuk\n");
                printStack(Peserta);
                break;
            case 3:
                Verifikasi(&Peserta);
                break;
            default :
                printf("Wrong input menu, please try again . . .\n");
                break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}
