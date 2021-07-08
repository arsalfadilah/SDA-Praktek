#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "QueueSpecial.h"

void InputData(infotype *infoData){
    infotype info;
    fflush(stdin);
    printf("Nama : ");
    scanf("%30[^\n]s", info.Nama);
    printf("Waktu Kedatangan : ");
    scanf("%d", &info.waktuDatang);
    printf("Jumlah Lembar : ");
    scanf("%d", &info.jumlahLEbar);

    info.waktuDilayani = 0;
    info.waktuSelesaiDilayani = 0;

    *infoData = info;
}


int main(){
    QueueSpecial q1, q2;
    infotype X;
    address hapus;
    CreateQueueSpecial(&q1);
    CreateQueueSpecial(&q2);


    for(int i = 0; i<1; i++){
        InputData(&X);
        InsVLast(&q1, X);
    }

    printf("Queue Sebelum Di proses");
    PrintInfo(q1);

    //Proses
    hapus = q1.First->next;
    DelP(&q1, hapus);


    printf("Queue Setelah di proses");
    PrintInfo(q1);

}