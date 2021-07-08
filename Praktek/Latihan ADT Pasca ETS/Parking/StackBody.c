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
//end modul utama

/** Modul Tambahan **/
//Menginputkan mobil yang akan masuk ke parkiran
void masukParkiran(Stack *S)
{
    infotype X;
    printf("=====================\n");
    printf("Nama : ");
    //tidak boleh ada spasi
    fflush(stdin);
    scanf("%s", X.nama);
    printf("=====================\n");
    //masukan ke dalam area parkir/stack
    Push(&(*S), X);
}

//Mengeluarkan mobil yang telah terparkir di parkiran
void keluarParkir(Stack *S, infotype X)
{
    infotype tempInfo;
    Stack tempStack;
    bool ketemu = false;
    CreateEmptyStack(&tempStack);
    if (!isEmpty(*S))
    {
        //mencari mobil yang akan keluar
        while (!isEmpty(*S) && !ketemu)
        {
            /* code */
            if (compareName((*S).top->info, X))
            {
                ketemu = true;
            }
            else
            {
                //mengeluarkan mobil yang menghalangi
                Pop(&(*S), &tempInfo);
                //masukan ke dalam antrian temp untuk menunggu agar dimasukan kembali ke area parkir
                Push(&tempStack, tempInfo);
            }
        }
        //cek apakah ada mobil yang mau keluarnya atau tidak
        if (ketemu)
        {
            //keluarkan mobil tersebut dari area parkir
            Pop(&(*S), &tempInfo);
        }
        //kembalikan apa yang ada di tempStack apabila tempStack tidak kosong
        while (!isEmpty(tempStack))
        {
            //keluarkan apa yang ada tempStack
            Pop(&tempStack, &tempInfo);
            //masukan kembali ke area parkir
            Push(&(*S), tempInfo);
        }
    }
}

//tahan dan bersihkan layar
void holdNplay()
{
    system("pause");
    system("cls");
}