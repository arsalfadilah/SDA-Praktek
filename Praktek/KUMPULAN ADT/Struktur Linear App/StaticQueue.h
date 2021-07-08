/****** Include guard ******/
#ifndef StaticQueue_h
#define StaticQueue_h
#include "boolean.h"
#include <stdio.h>
#include <conio.h>

#define Nil 0
#define MaxEl 10
#define Front(Q) (Q).Front
#define Rear(Q) (Q).Rear
#define InfoFront(Q) (Q).Data[(Q).Front]
#define InfoRear(Q) (Q).Data[(Q).Rear]

// Nil adalah queue dengan elemen kosong
// karena indeks dalam bahasa c dimulai 0 maka tabel dengan indeks 0
// tidak dipakai

// Jika Q adalah Queeu maka akses elemen :
// Q.T[Q.Front] untuk mengakses elemen pertama
// Q.T[Q.Rear] untuk mengakses elemen terakhir
// Q.Front adalah alamat elemen pertama
// Q.Rear adalah alamat elemen terakhir
// Definisi akses dengan selektor : set dan get

//------------------- ABSTRACT DATA TYPE QUEUE CIRCULAR -------------------------------//
// Defnisi Queue :
/* Queue kosong : Front = Nil, Rear = Nil
				  atau Front = Rear + 1 untuk alternatif 2
	Elemen yang dipakai menyimpan nilai stack T[1]...T[MaxEl]
	Jika Q adalah Queue maka akses elemen
	Q.T[Q.Front] untuk mengakses elemen pertama
	Q.T[Q.Rear] untuk mengakses elemen terakhir
	Q.Front adalah alamat elemen pertama
	Q.Rear adalah alamat elemen terakhir
*/

typedef struct{
    char Nama[10];
    int waktuDatang;
    int jumlahLEbar;
    int waktuDilayani;
    int waktuSelesaiDilayani;
} infotype;
typedef int address;
typedef struct {
	infotype Data[MaxEl+1];
	address Front;
	address Rear;
}Queue;

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
//----------------------Prototype ADT Queue Circular------------------------//

//---------- Konstruktor --------------//
/* I.S : Q terdefinisi tidak diketahui isinya
   F.S : Q diinisialisasi dengan Front(Q)=nil, Rear(Q)=nil
*/
void createQueue(Queue *Q) {
	(*Q).Front = Nil;
	(*Q).Rear = Nil;
}

//---------- Operasi pengecekan --------------//
/* Mengirim true jika Queue kosong: lihat definisi di atas */
boolean isQueueEmpty(Queue Q) {
	if (Q.Front == Nil && Q.Rear == Nil) {
		return true;
	} else {
		return false;
	}
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh yaitu jumlah elemen sudah mencapa MaxEl : lihat definisi diatas */
boolean isQueueFull(Queue Q) {
	if (NBElmt(Q) == MaxEl) {
		return true;
	} else {
		return false;
	}
}

//---------- Operasi Penambahan dan Pengurangan --------------//
/* Proses L Memasukkan info baru ke dalam Queue dengan aturan FIFO */
/* Prekondisi : Queue dipastikan tiak penuh */
/* I.S. : Q mungkin kosong atau Q mungkin berisi antrian tidak penuh
   F.S : X menjadi Rear yang baru, Rear "maju"
         Jika Rear(Q)=MaxE1+1 maka Rear(Q) diset =1
*/
void enQueue(Queue *Q, infotype x) {
	// silahkan pahami algoritma penambahan queue untuk circular
	// silhkan modifikasi sendiri
	if(!isQueueFull(*Q)){
        if(isQueueEmpty(*Q)){
           Front(*Q) = 1;
           Rear(*Q) = 1;
           InfoRear(*Q) = x;
        } else {
            if(Rear(*Q) == MaxEl){
                Rear(*Q) = 1;
            } else {
                Rear(*Q) = Rear(*Q) + 1;
            }
            InfoRear(*Q) = x;
        }
	}
}

/* Proses: Mengambil info pada Front(Q) dan mengeluarkannya dari Queue dengan aturan FIFO */
/* I.S : Q mungkin kosong atau Q mungkin berisi antrian
   F.S : Q berkurang satu elemen didepan disimpan pada X
         Front(Q) "maju" selama Front(Q) < Rear dimana Rear <= MaxEl,
         Tetapi Jika Front(Q)=MaxE1+1 dan masih ada antrian maka Front(Q) diset =1
*/
void deQueue(Queue *Q, infotype *x) {
	// silahkan pahami algoritma removing elemen pertama queue untuk circular
	// silahkan modifikasi sendiri
	if(!isQueueEmpty(*Q)){
        if(Front(*Q) == Rear(*Q)){
            Front(*Q) = Nil;
            Rear(*Q) = Nil;
        } else if(Front(*Q) == MaxEl){
            Front(*Q) = 1;
        } else {
            Front(*Q) = Front(*Q) + 1;
        }
	}
}

//---------- Operasi I/O --------------//
/* Menampilkan antrian ke layar dengan mengakses setiap info mulai dari Front s.d. rear */
/* I.S : mungkin kosong atau Q mungkin berisi antrian
   F.S : Jika Queue tidak kosong, semua info yang disimpan pada elemen queue diprint.
*/
void printQueueInfo(Queue Q) {
	// silahkan modifikasi sendiri
    //kamus
	int index;
	int tempFront;
	int tempRear;

	//algoritma
	if ( !isQueueEmpty(Q)) {
        if(Front(Q) > Rear(Q)){
            for(index = Front(Q); index <= MaxEl; index++){
                printf(" [ %d ] ", Q.Data[index]);
            }

            for(index = 1 ; index <= Rear(Q); index++){
                printf(" [ %d ] ", Q.Data[index]);
            }
        } else {
            for (index = Front(Q); index <= Rear(Q); index++) {
                printf(" [ %d ] ", Q.Data[index]);
            }
        }
         printf("\n");
	}
}

//---------- Operasi Pendukung --------------//
/* Mengirimkan banyaknya elemen queue melalui taging pada Front & Rear. Mengirimkan 0 jika Q kosong
   Perhitungannya :
     Jika Front berada pada index pertama atau Front < Real, maka Jml Elemen = Rear - Front + 1
     Jika Front > Rear, maka Jml Elemen = ..... {silahkan pahami algoritma circular}
*/
int NBElmt(Queue Q) {
    int jumlahElement;

    if(Front(Q)==1 || Front(Q)<Rear(Q)){
        jumlahElement = Rear(Q) - Front(Q) + 1;
    } else if(Front(Q) > Rear(Q)){
        jumlahElement = (MaxEl - Front(Q)) + Rear(Q) + 1;
    } else {
        jumlahElement = 0;
    }

    return jumlahElement;
}
