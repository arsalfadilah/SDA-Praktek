#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

//attribut data
typedef struct
{
    /* data */
    char nama[10];
    char ukuran;
} infotype;
typedef struct Node *addrStk;
typedef struct Node
{
    /* data */
    infotype info;
    addrStk next;
}NodeStack;
typedef struct
{
    /* data */
    addrStk top;
} Stack;
//end attribut data

/** Modul -Modul **/
/* Membuat stack bagian top menjadi kosong (Null) */
void CreateEmptyStack(Stack *S);

/* Mengalokasikan tempat di memori */
addrStk Alokasi(infotype X);

/* membebaskan memeri yang telah dialokasi seblumnya */
void Dealokasi(addrStk *P);

/* Mengirim true jika Stack kosong: lihat definisi di atas */
bool isEmpty(Stack S);

/* Mengirim true jika tabel penampung nilai elemen stack penuh */
bool isFull(Stack S);

/* Menambahkan X sebagai elemen Stack S. */
void Push(Stack *S, infotype X);

/* Menghapus X dari Stack S. */
void Pop(Stack *S, infotype *X);

/* Menghitung jumlah elemen stack S*/
int nElementStack(Stack S);

//menampilkan seluruh element di stack
void printElemStack(Stack S);

//menampilkan seluruh infotype
void printInfotype(infotype X);
//end modul utama

/** Modul Tambahan **/
//Membadingkan infotype berdasarkan nama
bool compareName(infotype n1, infotype n2);

//Membadingkan infotype berdasarkan ukuran
bool compareUkuran(infotype n1, infotype n2);

//Menginputkan koper yang akan masuk ke stack
void masukStack(Stack *S);

//Mengluarkan koper dari stack
void keluarStack(Stack *S, infotype X);

//pecah stack jadi stack1 atau stack
//info penyimpanan sementara tidak dihapus
void pecahStack(Stack S, Stack *s1, Stack *s2);

//tahan dan bersihkan layar
void holdNplay();

#endif
