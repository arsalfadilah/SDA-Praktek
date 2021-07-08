/****** Include guard ******/

#ifndef QueueSpecial_H
#define QueueSpecial_H

#include "boolean.h"
#include <stdlib.h>

#define Nil  NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

typedef struct{
    char Nama[10];
    int waktuDatang;
    int jumlahLEbar;
    int waktuDilayani;
    int waktuSelesaiDilayani;
} infotype;

typedef struct tElmtQueueSpecial *address;
typedef struct  tElmtQueueSpecial   {
	infotype info;
	address next;
	}ElmtQueueSpecial;

/* Definisi  QueueSpecial                   */
/* QueueSpecial Kosong  :  First(L) = Nil   */
/* Setiap elemen dengan address P dapat diacu Info(P),Next(P)       */
/* Elemen terakhir  QueueSpecial :jika addressnya Last, maka next(Last)=Nil */

typedef struct {
	address First;
}QueueSpecial;

/* ** Prototype   **  */
/* ** Test QueueSpecial Kosong **  */
boolean QueueSpecialEmpty(QueueSpecial  L);
/*  Mengirim true jika QueueSpecial kosong  */

/* Pembuatan  QueueSpecial Kosong  */
void CreateQueueSpecial(QueueSpecial *L);
/* I.S  :  Sembarang    		*/
/* F.S  :  Terbentuk  QueueSpecial kosong  	*/

/* Manajeman  memory  			*/
address Alokasi(infotype  X);
 /* Mengirimkan  address  hasil alokasi    sebuah elemen */
 /* Jika alokasi  berhasil, maka  address tidak nil, dan misalnya  */
 /* menghasilkan   P,  maka info(P)=X,  Nest(P)=Nil;               */
 /* Jika alokasi  gagal,  mengirimkan  Nil 			   */

void Dealokasi(address *P);
/* I.S  :   P  terdefinisi         	*/
/* F.S  :   P dikembalikan ke  sistem 	*/
/*   	    Melakukan  dealokasi, pengembalian address  P */

boolean ListEmpty(QueueSpecial  L);

/*   ** PENCARIAN SEBUAH ELEMEN QueueSpecial **   */

address Search1(QueueSpecial L, infotype  X);
/* Mencari apakah  ada elemen QueueSpecial dengan info(P)=X      */
/* Jika ada, mengirimkan  address elemen tersebut	 */
/* Jika  tidak ada, mengirimkan Nil 			 */

boolean FSearch(QueueSpecial L, address P);
/* Mencari apakah  ada elemen QueueSpecial yang  beralamat   P   */
/* Mengirimkan true jika ada, false jika tidak ada  	 */


address SearchPrec(QueueSpecial L, infotype X);
/* mencari apakah ada elemen QueueSpecial  yang beralamat P 	     */
/* Mnegirimkan address elemen sebelum elemen yang nilainya X */
/* Mencari apakah ada elemen QueueSpecial dengan info(P)=X	     */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P   */

/* ** PRIMITIF BERDASARKAN NILAI ** */

/* ** Penambahan Elemen ** */
void InsVFirst(QueueSpecial *L, infotype X);
/* I.S  : L mungkin kosong          */
/* F.S  : Melakukan alokasi sebuah elemen dan                */
/*        menambahkan elemen pertama dengan nilai X jika     */
/*        Alokasi berhasil 				     */

void InsVLast(QueueSpecial *L, infotype X);
/* I.S  : L mungkin kosong          */
/* F.S  : Melakukan alokasi sebuah elemen dan                */
/*        menambahkan elemen QueueSpecial di akhir; elemen terakhir  */
/*        yang baru bernilai X jika alokasi berhasil, 	     */
/*	  Jika alokasi gagal: I.S = F.S			     */

/**** Penghapusan Elemen ****/
void DeleteByAddres(QueueSpecial *L, address Target);

void DelVFirst(QueueSpecial *L, infotype *X);
  /* I.S    : QueueSpecial tidak kosong  		                 */
  /* F.S    : Elemen pertama QueueSpecial dihapus, nilai info disimpan   */
  /*	      pada X dan alamat elemen pertama  di-dealokasi 	 */


void DelVLast(QueueSpecial *L, infotype *X);
  /* I.S    : QueueSpecial tidak kosong  		                 */
  /* F.S    : Elemen terakhir QueueSpecial dihapus, nilai info disimpan  */
  /*	      pada X dan alamat elemen terakhir di-dealokasi 	 */

/* *******  PRIMITIF BERDASARKAN ALAMAT ********	*/
/* Penambahan Elemen Berdasarkan Alamat 		*/

void InsertFirst(QueueSpecial *L, address P);
/* I.S   : Sembarang, P sudah dialokasi			*/
/* F.S   : Menambahkan elemen ber-address P, sebagai    */
/*         elemen pertama				*/

void InsertAfter(QueueSpecial *L, address P, address Prec);
/* I.S   : Prec pastilah elemen QueueSpecial dan bukan elemen terakhir  */
/*         P sudah dialokasi 					*/
/* F.S   : Insert P sebagai elemen sesudah elemen beralamat Prec*/

void InsertLast(QueueSpecial  *L, address P);
/* I.S   : Sembarang, P sudah dialokasi				*/
/* F.S   : P ditambahkan  sebagai elemen terakhir yang baru	*/

/* ****** PENGHAPUSAN SEBUAH ELEMEN	*********   */
void DelFirst (QueueSpecial *L, address *P);
/* I.S   : QueueSpecial tidak kosong 	*/
/* F.S   : P adalah alamat elemen pertama QueueSpecial sebelum penghapusan */
/*         Elemen QueueSpecial berkurang satu (mungkin menjadi kosong)     */
/* First elemen yang baru adalah suksesor elemen pertama yang lama */

void DelP(QueueSpecial *L, address X);
/* I.S   : Sembarang  */
/* F.S   : Jika ada elemen  QueueSpecial beraddress P,dengan info (P)=X    */
/*         Maka P dihapus dari QueueSpecial dan di-dealokasi		   */
/*	   Jika tidak ada elemen QueueSpecial dengan info(P)=X, maka QueueSpecial  */
/*         tetap. QueueSpecial mungkin menjadi kosomg karena penghapusan   */

void DelLast(QueueSpecial *L, address *P);
/* I.S   : QueueSpecial tidak kosong  */
/* F.S   : P adalah alamat elemen terakhir QueueSpecial sebelum penghapusan */
/*	   Elemen QueueSpecial berkurang 1 (mungkin menjadi kosong)	    */
/*         Last elemen baru adalah predessesor elemen pertama yang  */
/*         jika tidak ada					    */

void DelAfter(QueueSpecial *L, address *Pdel, address Prec);
/* I.S   : QueueSpecial tidak kosong, Prec adalah anggota QueueSpecial		*/
/* F.S   : Menghapus Next(Prec) :				*/
/*         Pdel adalah alamat elemen QueueSpecial yang dihapus		*/

/* *************PROSES SEMUA ELEMEN ****************   */
void PrintInfo(QueueSpecial L);
/* I.S   : QueueSpecial mungkin kosong 	*/
/* F.S   : Jika QueueSpecial tidak kosong, semua info yang disimpan pada */
/*         elemen QueueSpecial di-print					 */
/*         Jika QueueSpecial kosong, hanya menuliskan "QueueSpecial Kosong"	 */

int NbElmt(QueueSpecial L);
/* Mengirimkan banyaknya elemen QueueSpecial, mengirimkan Nol jika kosong */

infotype Max(QueueSpecial L);
/* Mengirimkan nilai info(P) yang maksimum */

address AdrMax(QueueSpecial L);
/* mengirimkan address P, dengan info (P) yang maksimum */

infotype Min(QueueSpecial L);
/* mengirimkan nilai info(P), yang minumum    */

address AdrMin(QueueSpecial L);
/* mengirimkan address P, dengan info(P) yang minimum */

float Average(QueueSpecial L);
/* mengirimkan nilai rata-rata info(P)	*/

/******************************************************/
/***   		PROSES TERHADAP QueueSpecial		    ***/
/******************************************************/
void DelAll(QueueSpecial *L);
/* Delete semua elemen QueueSpecial, dan alamat elemen di-dealokasi */

void InversQueueSpecial(QueueSpecial *L);
/* I.S   : sembarang  			*/
/* F.S   : elemen QueueSpecial  dibalik		*/
/*	   elemen terakhir menjadi elemen pertama, dst    */
/*	   Membalik elemen QueueSpecial, tanpa alokasi/dealokasi  */

QueueSpecial FInversQueueSpecial(QueueSpecial L);
/* mengirimkan QueueSpecial baru, hasil invers dari L 	*/

void CopyQueueSpecial(QueueSpecial L1, QueueSpecial *L2);
/* I.S   : L1 sembarang 				*/
/* F.S   : L1 dan L2 menunjuk ke QueueSpecial yang sama 	*/
/*         tidak ada alokasi/dealokasi yang elemen	*/

QueueSpecial FCopyQueueSpecial(QueueSpecial L);
/* Mengirimkan QueueSpecial yang merupakan salinan L  		*/

void CpAlokQueueSpecial(QueueSpecial Lin, QueueSpecial  *Lout);
/* I.S   : Lin sembarang				    */
/* F.S   : Jika semua alokasi berhasil, maka Lout berisi    */
/*         hasil copy Lin. Jika ada alokasi yang  gagal     */
/*         maka Lout=Nil, dan semua elemen yang terlanjur   */
/*	   dialokasi, didealokasi dengan melakukan alokasi  */
/*	   elemen. Lout adalah QueueSpecial kosong, jika ada alokasi*/
/*	   elemen yang gagal				    */

void konkat(QueueSpecial L1, QueueSpecial L2, QueueSpecial *L3);
/* I.S   : L1 dan L2 sembarang				      */
/* F.S   : L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 &  */
/*	   L2. Jika semua alokasi berhasil, maka L3  adalah   */
/*	   hasil konkatenasi. Jika ada alokasi yang gagal,    */
/*	   semua elemen yang sudah dialokasi, di-dealokasi dan*/
/*	   L3=Nil					      */

void konkat1(QueueSpecial *L1, QueueSpecial *L2, QueueSpecial *L3);
/* I.S  : L1 dan L2 sembarang				*/
/* F.S  : L1 dan L2 kosong,  L3 adalah hasil konkatenasi*/
/*	  L1 & L2, 					*/
/* Konkatenasi 2 buah QueueSpecial : L1 dan L2 menghasilkan L3  */
/* yang baru (dengan elemen QueueSpecial L1 dan L2). Dan L1 dan */
/* L2 menjadi QueueSpecial kosong. Tidak ada alokasi/dealokasi  */

void PecahQueueSpecial(QueueSpecial *L1, QueueSpecial *L2, QueueSpecial L);
/* I.S  : L mungkin kosong  */
/* F.S  : Berdasarkan L, dibentuk 2 buah QueueSpecial L1 dan L2     */
/*        L tidak berubah. Untuk membentuk L1 dan L2 harus  */
/*	  alokasi. L1 berisi separuh elemen  L dan L2 berisi*/
/*	  sisa elemen L. Jika elemen L ganjil, maka separuh */
/* 	  adalah NbElmt(L)div 2				    */

void sortQueueSpecialQueue(QueueSpecial *L);

void swapAddr(address a, address b);

#endif // DynamicQueue_H

/****** Function definition ******/