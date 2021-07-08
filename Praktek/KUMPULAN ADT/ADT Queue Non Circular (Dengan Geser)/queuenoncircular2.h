/*---------------------------------------------
	Program		: queuenoncircular2.h
	Author 		: Asri Maspupah
	Deskripsi	: header file queue circular
	Tanggal		: 26/04/2017
---------------------------------------------*/


#ifndef queuenoncircular2_h
#define queuenoncircular2_h
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

//------------------- ABSTRACT DATA TYPE QUEUE NON CIRCULAR -------------------------------//
// Queue Non Circular adalah antrian dengan menggunakan metode penggeseran pada saat menghapus elemen queue
// Defnisi Queue :
/* Queue kosong : Front = Nil, Tail = Nil
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

/* Mengirim true jika tabel penampung nilai elemen stack penuh yaitu Rear berada MaxEl*/
boolean isQueueFull(Queue Q);

//---------- Operasi Penambahan dan Pengurangan --------------//
/* Proses L Memasukkan info baru ke dalam Queue dengan aturan FIFO */
/* Prekondisi : Queue dipastikan tidak penuh, yaitu Rear != MaxEl */
/* I.S. : Q mungkin kosong atau Q mungkin berisi antrian tidak penuh
   F.S : X menjadi elemen pada REAR yang baru, REAR "maju"
         Jika Rear(Q)=MaxE1+1 maka tidak bisa melakukan penambahan
*/
void enQueue(Queue *Q, infotype x);

/* Proses: Mengambil info pada Front(Q) dan mengeluarkannya dari Queue dengan aturan FIFO */ 
/* I.S : Q mungkin kosong atau Q mungkin berisi antrian 
   F.S : Q berkurang satu elemen didepan disimpan pada X
         Front(Q) "tetap" 
		  ketika Front(Q) < Rear, maka ada pergeseran elemen setelahnya selama masih ada antrian
          ketika Front = Rear, maka Front = Nil dan Rear = Nil
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
   Perhitungannya : Rear - Front + 1, karena Front tidak mungkin lebih besar dari Rear
*/ 
int NBElmt(Queue Q); 

#endif





