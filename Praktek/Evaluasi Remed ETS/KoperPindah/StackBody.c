#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>

/** Modul -Modul **/
/* Membuat stack bagian top menjadi kosong (Null) */
void CreateEmptyStack(Stack *S)
{
    (*S).top = NULL;
}

/* Mengalokasikan tempat di memori */
addrStk Alokasi(infotype X)
{
    addrStk P = (addrStk)malloc(sizeof(NodeStack));
    if (P != NULL)
    {
        P->next = NULL;
        P->info = X;
    }
    return P;
}

/* membebaskan memeri yang telah dialokasi seblumnya */
void Dealokasi(addrStk *P)
{
    free(*P);
}

/* Mengirim true jika Stack kosong: lihat definisi di atas */
bool isEmpty(Stack S)
{
    return S.top == NULL;
}

/* Mengirim true jika tabel penampung nilai elemen stack penuh */
bool isFull(Stack S);

/* Menambahkan X sebagai elemen Stack S. */
void Push(Stack *S, infotype X)
{
    addrStk P = Alokasi(X);
    if (P != NULL)
    {
        P->next = (*S).top;
        (*S).top = P;
    }
}

/* Menghapus X dari Stack S. */
void Pop(Stack *S, infotype *X)
{
    addrStk P;
    if (!isEmpty(*S))
    {
        *X = (*S).top->info;
        P = (*S).top;
        (*S).top = (*S).top->next;
        P->next = NULL;
        Dealokasi(&P);
    }
}

/* Menghitung jumlah elemen stack S*/
int nElementStack(Stack S)
{
    addrStk P = S.top;
    int count = 0;
    while (P != NULL)
    {
        /* code */
        count++;
        P = P->next;
    }
    return count;
}

//menampilkan seluruh element di stack
void printElemStack(Stack S)
{
    addrStk P = S.top;
    //jika stack kosong tampilkan pesan kosong
    if (P == NULL)
    {
        printf("Stack Kosong");
        return;
    }
    //tampilkan semuan element yg ada
    while (P != NULL)
    {
        /* code */
        printInfotype(P->info);
        P = P->next;
    }
}

//menampilkan seluruh infotype
void printInfotype(infotype X)
{
    printf("|||\t%s\t|||\n", X.nama);
}
//end modul utama

/** Modul Tambahan **/
//Membadingkan infotype berdasarkan nama
bool compareName(infotype n1, infotype n2)
{
    if (strcmp(n1.nama, n2.nama) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Membadingkan infotype berdasarkan ukuran
bool compareUkuran(infotype n1, infotype n2)
{
    if (n1.ukuran == n2.ukuran)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Menginputkan koper yang akan masuk ke stack
void masukStack(Stack *S)
{
    infotype X;
    printf("=====================\n");
    printf("Nama : ");
    //tidak boleh ada spasi
    fflush(stdin);
    scanf("%s", X.nama);
    fflush(stdin);
    printf("Ukuran %c", &X.ukuran);
    printf("=====================\n");
    //masukan ke dalam area parkir/stack
    Push(&(*S), X);
}

//Mengeluarkan koper dari stack
void keluarStack(Stack *S, infotype X)
{

}

//pecah stack jadi stack1 atau stack
//info penyimpanan sementara tidak dihapus
//s1 adalah troli1 atau bagasi lantai 1
//s2 adalah troli 2 atau bagasi lantai 2
void pecahStack(Stack S, Stack *s1, Stack *s2){
    addrStk P;
    if(!isEmpty(S)){
        P=S.top;
        while(P!=NULL){
            switch (P->info.ukuran)
            {
            case 'B':
                /* code */
                Push(&(*s1), P->info);
                break;
            case 'S':
                Push(&(*s2), P->info);
                break;
            default:
                printf("Ops something error");
                break;
            }
            P = P->next;
        }
    }
}

//tahan dan bersihkan layar
void holdNplay()
{
    system("pause");
    system("cls");
}