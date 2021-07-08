#include "Queue.h"
#include <stdio.h>

//modul menu yg tampil di main
int menu()
{
    int fitur;
    printf("======================\n");
    printf("Program Estimasi Antrian Customer Pesawat X\n");
    printf("1. Tambah Antrian\n");
    printf("2. Hapus Antrian\n");
    printf("3. Lihat Semua Antrian\n");
    printf("0. Exit\n");
    printf("\nPilih : ");
    scanf("%d", &fitur);
    return fitur;
}

int main()
{
    //buat menu untuk penginputan penumpang dan looping sampai exit program
    int fitur, waktuSebelumnya = 0;
    Queue antrian;
    //buat antrian menjadi null terlebih dahulu
    CreateQueue(&antrian);
    infotype in;
    while ((fitur = menu()) != 0)
    {
        /* code */
        HoldnCls();
        switch (fitur)
        {
        case 1:
            //inputkan customer yang akan mengantri
            MasukAntrian(&antrian, &waktuSebelumnya);
            break;
        case 2:
            //hapus cs yang pertama mengantri
            HapusAntrian(&antrian, &in);
            break;
        case 3:
            //tampilkan semua orang yang mengantri
            printElemQueue(antrian);
            break;
        default:
            printf("Ops, fitur blom ada");
            break;
        }
        HoldnCls();
    }
    return 0;
}