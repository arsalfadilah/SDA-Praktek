/* File  : drivlist.c			*/
/* Desk  : Driver list1.c		*/
/*         ANI RAHMANI / 23501007	*/
/* Tgl	 : 25/10/01			*/
/* Tgl modifikasi List1.c : 15/11/01    */

#include "listchar.h"
#include <stdlib.h>
#include <stdio.h>



int main()
{	/* Kamus */
	List L,L1,L3;
	infotype cari,X;
	address PS;
	int i,N, idx=1;

	/* Algoritma */
	/* CREATE LIST & MENGISI ELEMEN LIST */
    printf("Create List\n");
    CreateList(&L);
    //insert "u"
    printf("Insert huruf pertama, value 'u'\n");
    InsVFirst(&L, 'u');

    printf("Print List ->> ");
    PrintInfo(L);
    printf("\n");

    //inser "c"
    printf("Insert value 'c' setelah huruf pertama\n");
    InsVLast(&L, 'c');

    printf("Print List ->> ");
    PrintInfo(L);
    printf("\n");

    printf("Insert value 'h' setelah huruf kedua\n");
    InsVLast(&L, 'h');

    printf("Print List ->> ");
    PrintInfo(L);
    printf("\n");

    printf("Insert value 'i' setelah huruf ketiga\n");
    InsVLast(&L, 'i');

    printf("Print List ->> ");
    PrintInfo(L);
    printf("\n");

    printf("Insert value 'n' setelah huruf pertama\n");
    InsertAfter(&L, Alokasi('n'), Search1(L, 'u'));

    printf("Print List ->> ");
    PrintInfo(L);
    printf("\n");

    printf("delete value 'i' pada elemen list\n");
    DelP(&L, 'i');

    printf("Print List ->> ");
    PrintInfo(L);
    printf("\n");

    printf("Insert value 'p' di awal list\n");
    InsVFirst(&L, 'p');

    printf("Print List ->> ");
    PrintInfo(L);
    printf("\n");

    printf("Insert value 'a' setelah huruf 'h'\n");
    InsertAfter(&L, Alokasi('a'), Search1(L, 'h'));

    printf("Print List ->> ");
    PrintInfo(L);
    printf("\n");

    printf("Show semua elemen karakter\n");
    PrintInfo(L);
    printf("\n");

    printf("Cari huruf 'h' pada list");

    if(Search1(L, 'h') != Nil){
        idx = idxNlist(L, 'h');
        printf("\nPosisi ke %d dengan alamat %x\n", idx, Search1(L, 'h'));
    } else {
        printf("tidak ada\n");
    }

    printf("\nDelete semua elemen list karakter\n");
    DelAll(&L);

    printf("Print List ->> ");
    PrintInfo(L);

    return 0;
}

