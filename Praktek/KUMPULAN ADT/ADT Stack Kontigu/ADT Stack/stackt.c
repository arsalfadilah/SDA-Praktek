/* File queues.c */
/* implementasi dari file queues.h */
/* HEAD dan TAIL adalah alamat elemen pertama dan terakhir */
/* Kapasitas Queue=MaxEl bush elemen, dan indeks dibuat "sirkuler" */
#include "stackt.h"
#include <stdio.h>
/* Definisi ABSTRACT DATA TYPE POINT *
Stack S;

/******************* Prototype ****************/
/*** Konstruktor/Kreator ***/
void CreateEmpty(Stack *S){
	Top(*S) = Nil;
}
/* T.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosonq berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+l karena O tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
/*********** Predikat Untuk test keadaan KOLEKSI **/
boolean IsEmpty (Stack S){
	return Top(S) == Nil;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S){
	//printf("Top %d Max %d", Top(S),MaxEl);
	return Top(S) == MaxEl;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
/*********** Menambahkan sebuah elemen ke Stack **********/
void Push (Stack *S, infotype X){
	Top(*S) = Top(*S)+1;
	InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* T.S. S mungkin kosong, tabel penampung elemen stack TTDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
/*********** Menqhapus sebuah elemen Stack **********/
void Pop (Stack *S, infotype *X){
	*X = InfoTop(*S);
	Top(*S) = Top(*S)-1;
}
/* Menghapus X dari Stack S. */
/* T.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang l */

/****** Modul Tambahan *********/
void printStack(Stack S){
    infotype X;

    if(!IsEmpty(S)){
        while(!IsEmpty(S)){
            Pop(&S, &X);
            printf(" [ %d ] \n", X);
        }
    } else {
        printf("[ EMPTY ]");
    }
}

int nElem(Stack S){
    return Top(S);
}
