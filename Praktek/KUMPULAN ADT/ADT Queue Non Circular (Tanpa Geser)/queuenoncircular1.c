/*---------------------------------------------
	Program		: queuenoncircular.c
	Author 		: Fladio Armandika
	Deskripsi	: realisasi file dari queue circular
	Tanggal		: 26/04/2017
	Update		: Asri Maspupah, 7 Mei 2021
---------------------------------------------*/


#include "queuenoncircular1.h"
#include <stdio.h>
#include <conio.h>

//----------------------Prototype ADT Queue Circular------------------------//

//---------- Konstruktor --------------//
/* I.S : Q terdefinisi tidak diketahui isinya
   F.S : Q diinisialisasi dengan Front(Q)=nil, Rear(Q)=nil
*/
void createQueue(Queue *Q) {
	Front(*Q) = Nil;
	Rear(*Q) = Nil;
}

//---------- Operasi pengecekan --------------//
/* Mengirim true jika Queue kosong: lihat definisi di atas */
boolean isQueueEmpty(Queue Q) {
	if (Front(Q) == Nil && Rear(Q) == Nil) {
		return true;
	} else {
		return false;
	}
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh yaitu Rear berada MaxEl*/
boolean isQueueFull(Queue Q) {
	if (Rear(Q) == MaxEl) {
		return true;
	} else {
		return false;
	}
}

//---------- Operasi Penambahan dan Pengurangan --------------//
/* Proses L Memasukkan info baru ke dalam Queue dengan aturan FIFO */
/* I.S. : Q mungkin kosong atau Q mungkin berisi antrian tidak penuh atau Queue penuh
   F.S : X menjadi elemen pada REAR yang baru, REAR "maju"
         Jika Rear(Q)=MaxE1+1 maka tidak bisa melakukan penambahan
*/
void enQueue(Queue *Q, infotype x) {
	if(!isQueueFull(*Q)) {
		if (isQueueEmpty((*Q))) {
			Front(*Q) = 1;
			Rear(*Q) = 1;
			InfoRear(*Q) = x;
		}else{
			Rear(*Q) = Rear(*Q) + 1;
			InfoRear(*Q) = x;
		}
	}else{
		printf("Queue Penuh");
	}
}

/* Proses: Mengambil info pada Front(Q) dan mengeluarkannya dari Queue dengan aturan FIFO */ 
/* I.S : Q mungkin kosong atau Q mungkin berisi antrian 
   F.S : Q berkurang satu elemen didepan disimpan pada X
         Front(Q) "maju" selama Front(Q) < Rear dan 
		 ketika Front = Rear = MaxEl, maka Front = Nil dan Rear = Nil 
*/
void deQueue(Queue *Q, infotype *x) {
	if ( isQueueEmpty((*Q))) {
		printf("queue kosong");
	} else  {
		if (Front(*Q) < Rear(*Q)) {
			(*x) = InfoFront(*Q);
			Front(*Q) = Front(*Q) + 1;	
		}else{
			if(Front(*Q) == Rear(*Q)) {
				(*x) = InfoFront(*Q);
				Front(*Q) = Nil;
				Rear(*Q) = Nil;
			}
		}
	}
}

//---------- Operasi I/O --------------//
/* Menampilkan antrian ke layar dengan mengakses setiap info mulai dari Front s.d. rear */
/* I.S : mungkin kosong atau Q mungkin berisi antrian
   F.S : Jika Queue tidak kosong, semua info yang disimpan pada elemen queue diprint. 
*/
void printQueueInfo(Queue Q) {
	//kamus
	int index;
	
	//algoritma
	if ( !isQueueEmpty(Q)) {
		for (index = Front(Q); index <= Rear(Q); index++) {
			printf(" [ %d ] ", Q.Data[index]);
		}
		printf("\n");			
	}
}

//---------- Operasi Pendukung --------------//
/* Mengirimkan banyaknya elemen queue melalui taging pada Front & Rear. Mengirimkan 0 jika Q kosong 
   Perhitungannya : Rear - Front + 1, karena Front tidak mungkin lebih besar dari Rear
*/
int NBElmt(Queue Q) {
	int jmlElement;
	
	if (isQueueEmpty(Q)){
		jmlElement = 0;
	}else{
		jmlElement = Rear(Q) - Front(Q) + 1;
	}
	
	return jmlElement;
}



