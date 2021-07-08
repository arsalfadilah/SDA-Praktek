/* File  : drivlist.c			*/
/* Desk  : Driver list1.c		*/
/*         ANI RAHMANI / 23501007	*/
/* Tgl	 : 25/10/01			*/
/* Tgl modifikasi List1.c : 15/11/01    */

//#include "DynamicLinkedList.h"
#include "DynamicQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{	/* Kamus */
//    List L1, L2, L3;
    Queue Q1;
    infotype TempInfo;
//    address temp;
//    CreateList(&L1);
//    CreateList(&L2);
    createQueue(&Q1);

    int upper = 100;
    int lower = 20;
    int count = 90000;

    srand(time(0));

    for (int i = 0; i < count; i++) {
        infotype num = (rand() % (upper - lower + 1)) + lower;
//        InsVFirst(&L1, num);
        enQueue(&Q1, num);
    }
    printf("Q1 : ");
        printQueueInfo(Q1);

    DelAll(&Q1);
//    L2 = FCopyList(L1);
//
//    DelVFirst(&L1, &TempInfo);
//
//    printf("Infotype = %d Has Been Deleted\n", TempInfo);
//
//    printf("L1 : ");PrintInfo(L1);printf("\n");
//    printf("L2 : ");PrintInfo(L2);printf("\n");
//
//    konkat(L1, L2, &L3);
//    printf("L3 : ");PrintInfo(L3);printf("\n");

	return 0;
}

