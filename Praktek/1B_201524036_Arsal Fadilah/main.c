#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include "list_queue.h"
#include "stackt.h"

int Menu(){
    int x;
    printf("===================================\n");
    printf("| Program By : Arsal Fadilah V.01 |\n");
    printf("===================================\n");
    printf("||     PENDAFTARAN VAKSINASI     ||\n");
    printf("||  1. Tambah Pendaftar          ||\n");
    printf("||  2. Tampilkan Pendaftar       ||\n");
    printf("||  3. Tampilkan Daftar Tunggu   ||\n");
    printf("||  4. Registrasi Peserta        ||\n");
    printf("||  5. Verifikasi Peserta        ||\n");
    printf("||  6. Exit                      ||\n");
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
    infotype pendaftar = L.First->info;
    char choose1, choose2;

    printf("No. KTP             : ");scanf("%s", &X.ktp);
    fflush(stdin);
    printf("Nama                : ");scanf("%34[^\n]", &X.nama);
    printf("Kategori            : ");scanf("%s", &X.kategori);

    fflush(stdin);
    printf("Foto Copy KTP       : [Y/N] ");scanf("%c", &choose1);
    if(choose1=='Y'){
        X.syarat_1 = true;
    }else{
        X.syarat_1 = false;
    }

    fflush(stdin);
    if(strcmp(X.kategori, "Lansia")==0){
        printf("Kartu Keluarga      : [Y/N] ");scanf("%c", &choose2);
    } else{
        printf("Surat Pengantar     : [Y/N] ");scanf("%c", &choose2);
    }

    if(choose2=='Y'){
        X.syarat_2 = true;
    } else {
        X.syarat_2 = false;
    }

    if(X.syarat_1 && X.syarat_2){
        if(strcmp(pendaftar.NoKtp, X.ktp)==0){
            Push(S, X);
            printf("\nRegistrasi Berhasil\n");
        } else {
            printf("\nData Pendaftar tidak ditemukan\n");
        }
    } else {
        printf("\nRegistrasi Gagal\n");
    }


}

void Verifikasi(Stack *S){
    info X;
    char choose='Y';

    while(choose=='Y' && !IsEmpty(*S)){
      printf("\nPeserta yang sudah Registrasi\n");
      printStack(*S);
        X = InfoTop(*S);
        printf("\nLakukan Verifikasi untuk %s ? [Y/N] ", X.nama);

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
    List pendaftar, queue_list;
    Stack Peserta;
    CreateEmpty(&Peserta);
    CreateList(&pendaftar);

    system("cls");

    int m;
    while((m = Menu()) != 6){
        switch(m){
            case 1:
                printf("\n!!! Isilah data pendaftar di bawah dengan BENAR !!!\n");
                insertPendaftar(&pendaftar);
                break;
            case 2:
                tampilPendaftar(pendaftar);
                break;
            case 3:
                //Melihat daftar antrian seluruhnya
                queue_list = FCopyList(pendaftar);
                sortListQueue(&queue_list);
                tampilPendaftar(queue_list);

                //Melihat antrian per kategori
                printf("Do u want to filter this queue (y/t) ? ");
                fflush(stdin);
                scanf("%c", &ActiveSortCategory);
                if(ActiveSortCategory=='y'){
                    system("cls");
                    MenuSortList(pendaftar);
                }
                break;
            case 4:
                insertPeserta(pendaftar, &Peserta);
                break;
            case 5:
                Verifikasi(&Peserta);
                break;
            default :
                printf("Wrong input menu, please try again . . .\n");
                break;
        }
        system("pause");
        system("cls");
    }

    DelAll(&pendaftar);

    return 0;
}
