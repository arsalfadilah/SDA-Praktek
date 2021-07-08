/***** Header File *****/
#ifndef List_H
#define List_H

#include <stdbool.h>
#include <stdlib.h>


//Struktur Data
typedef struct
{
    /* data */
    int x;
    int y;
}Posisi;

typedef struct
{
    /* data */
    char Nama [10];
    Posisi pos;
}Infotype;

typedef struct node *address;
typedef struct node
{
    /* data */
    Infotype info;
    address next;
}Node;

typedef struct
{
    /* data */
    address First;
}List;

/**** Modul - Modul ****/
/* Test List Kosong */
bool ListEmpty(List  L);
/*  Mengirim true jika List kosong  */

/* Pembuatan  List Kosong  */
void CreateList(List *L);
/* I.S  :  Sembarang    		*/
/* F.S  :  Terbentuk  List kosong  	*/

address Alokasi(Infotype X);
 /* Mengirimkan  address  hasil alokasi    sebuah elemen */
 /* Jika alokasi  berhasil, maka  address tidak nil, dan misalnya  */
 /* menghasilkan   P,  maka info(P)=X,  Nest(P)=Nil;               */
 /* Jika alokasi  gagal,  mengirimkan  Nil 			   */

void Dealokasi(address *P);
/* I.S  :   P  terdefinisi         	*/
/* F.S  :   P dikembalikan ke  sistem 	*/
/*   	    Melakukan  dealokasi, pengembalian address  P */

void InsVLast(List *L, Infotype X);
/* I.S  : L mungkin kosong          */
/* F.S  : Melakukan alokasi sebuah elemen dan                */
/*        menambahkan elemen list di akhir; elemen terakhir  */
/*        yang baru bernilai X jika alokasi berhasil, 	     */
/*	  Jika alokasi gagal: I.S = F.S			     */

/* *************PROSES SEMUA ELEMEN ****************   */
void PrintInfo(List L);
/* I.S   : List mungkin kosong 	*/
/* F.S   : Jika list tidak kosong, semua info yang disimpan pada */
/*         elemen list di-print					 */
/*         Jika list kosong, hanya menuliskan "List Kosong"	 */


/**** Operasi Penunjang ****/
void InputPos(Posisi *Pos);

//Input Infotype Only;
void InputInfo(Infotype *X);

void GetInfotypeByTask(List L, int pos, char task[], address *Now, Infotype *New);

#endif