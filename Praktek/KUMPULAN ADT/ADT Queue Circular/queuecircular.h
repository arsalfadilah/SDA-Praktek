/*---------------------------------------------
	Program		: queuecircular.h
	Author 		: Asri Maspupah
	Deskripsi	: Fronter file queue circular
	Tanggal		: 26/04/2017
---------------------------------------------*/


#ifndef queuecircular_h
#define queuecircular_h
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

typedef int infotype;
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





