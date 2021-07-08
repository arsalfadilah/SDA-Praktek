/****** Include guard ******/
#ifndef DynamicQueue_H
#define DynamicQueue_H

#include "DynamicLinkedList.h"
#include "boolean.h"
#include <stdlib.h>

typedef List Queue;

//----------------------Prototype ADT Queue Circular------------------------//
//---------- Konstruktor --------------//
/* I.S : Q terdefinisi tidak diketahui isinya
   F.S : Q diinisialisasi dengan Front(Q)=nil, Rear(Q)=nil
*/
void createQueue(Queue *Q);

//---------- Operasi pengecekan --------------//
/* Mengirim true jika Queue kosong: lihat definisi di atas */
boolean isQueueEmpty(Queue Q);

/* Mengirim true jika tabel penampung nilai elemen stack penuh yaitu jumlah elemen sudah mencapa MaxEl*/
boolean isQueueFull(Queue Q);

//---------- Operasi Penambahan dan Pengurangan --------------//
/* Proses L Memasukkan info baru ke dalam Queue dengan aturan FIFO */
/* I.S. : Q mungkin kosong atau Q mungkin berisi antrian tidak penuh atau sudah penuh
   F.S : X menjadi Rear yang baru, Rear "maju"
         Jika Rear(Q)=MaxE1+1 maka Rear(Q) diset =1
*/
void enQueue(Queue *Q, infotype x);

/* Proses: Mengambil info pada Front(Q) dan mengeluarkannya dari Queue dengan aturan FIFO */
/* I.S : Q mungkin kosong atau Q mungkin berisi antrian penuh atau tidak penuh
   F.S : Q berkurang satu elemen didepan disimpan pada X
         Front(Q) "maju" selama Front(Q) < Rear dimana Rear <= MaxEl,
         Tetapi Jika Front(Q)=MaxE1+1 dan masih ada antrian maka Front(Q) diset =1
*/
void deQueue(Queue *Q, infotype *x);

//---------- Operasi I/O --------------//
/* Menampilkan antrian ke layar dengan mengakses setiap info mulai dari Front s.d. rear */
/* I.S : mungkin kosong atau Q mungkin berisi antrian
   F.S : Jika Queue tidak kosong, semua info yang disimpan pada elemen queue diprint.
*/
void printQueueInfo(Queue Q);

//---------- Operasi Pendukung --------------//
/* Mengirimkan banyaknya elemen queue melalui taging pada Front & Rear. Mengirimkan 0 jika Q kosong
   Perhitungannya :
     Jika Front berada pada index pertama atau Front < Real, maka Jml Elemen = Rear - Front + 1
     Jika Front > Rear, maka Jml Elemen = ..... {silahkan pahami algoritma circular}
*/
int NBElmt(Queue Q);

#endif

/****** Function definition ******/
void createQueue(Queue *Q){
    CreateList(&(*Q));
}

boolean isQueueEmpty(Queue Q){
    return ListEmpty(Q);
}

boolean isQueueFull(Queue Q){
    infotype Y;

    return (Alokasi(Y) == Nil);
}

void enQueue(Queue *Q, infotype x){
    if(!isQueueFull(*Q)){
        InsVLast(&(*Q), x);
    }
}

void deQueue(Queue *Q, infotype *x){
    if(!isQueueEmpty(*Q)){
        DelVFirst(&(*Q), &(*x));
    }
}

void printQueueInfo(Queue Q){
    PrintInfo(Q);
}

int NBElmt(Queue Q){
    NbElmt(Q);
}
