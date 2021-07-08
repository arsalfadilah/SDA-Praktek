#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "queuecircular.h"

int main(){

    //kamus
	Queue Q;
	int i,menu,x;
	float avg;

	//algoritma

	createQueue(&Q);

	while (menu != 3) {
		system("cls");
		printf("\n\n");
		printQueueInfo(Q);
		printf("\nJumlah elemen = %d \n", NBElmt(Q));
		printf("\nHead = %d \n", Front(Q));
		printf("\nTail elemen = %d \n", Rear(Q));
		printf("-------- Menu --------\n");
		printf("1. Add	\n");
		printf("2. Delete	\n");
		printf("3. Exit\n");

		printf("\nPilihan : ");scanf("%d",&menu);
		switch(menu) {
			case 1 :
				printf("\n-------- Add --------\n");
				printf("masukan angka : ");scanf("%d",&x);
				enQueue(&Q,x);
				break;
			case 2 :
				printf("\n-------- Delete --------\n");
				deQueue(&Q,&x);
				break;
			case 3 :
				printf("\n");
				printQueueInfo(Q);
				break;
			case 4 :
				break;
		}

		getchar();
	}

	printf("selesai..");

    return 0;
}
