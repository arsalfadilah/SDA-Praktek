#include "Stack.h"
#include <stdio.h>

int main()
{
    //Menyediakan ruang untuk area parkir mobil
    Stack mobil;
    infotype in;
    CreateEmptyStack(&mobil);
    //Mobil masuk
    int nMobil;
    printf("Init mobil = ");
    scanf("%d", &nMobil);
    for (int i = 0; i < nMobil; i++)
    {
        holdNplay();
        //input mobil yang akan di parkir
        masukParkiran(&mobil);
    }
    holdNplay();
    //proses pengeluaran mobil yang terparkir
    char lanjut = 'y';
    while (lanjut == 'y' && !isEmpty(mobil))
    {
        //print semua element
        printElemStack(mobil);
        //memilih mobil yang akan dikeluarkan
        printf("\nPilih mobil yang keluar = ");
        scanf("%s", in.nama);
        //keluarkan mobil tersebut
        keluarParkir(&mobil, in);
        //print kembali semua element dengan mobil in.nama telah dikeluarkan
        holdNplay();
        printElemStack(mobil);
        //tahan dan tanya
        printf("\nLanjut (y/t) ? ");
        fflush(stdin);
        scanf("%c", &lanjut);
        holdNplay();
    }

    return 0;
}