#include "Queue.h"
#include <stdio.h>

int main()
{
    //jumlah perkiraan (input dari user)
    int inputan, tempWaktuSebelumya = 0;
    infotype in;
    //buat antrian kosong
    Queue antrian;
    CreateQueue(&antrian);

    //input data customer grooming kucing
    printf("Jumlah input : ");
    scanf("%d", &inputan);
    for (int i = 0; i < inputan; i++)
    {
        HoldnCls();
        //masukan ke antrian
        //asumsi bahwa waktu daftar cs yang selanjutnya akan selalu lebih besar dari pada
        //waktu daftar cs sebelumnya
        MasukAntrian(&antrian);
    }
    HoldnCls();
    //Hitung estimasi waktu selesai setiap customer
    for (int i = 0; i < inputan; i++)
    {
        MulaiGrooming(&antrian, &in, tempWaktuSebelumya);
        tempWaktuSebelumya = in.estWaktuSelesai;
        printInfotype(in);
    }

    //tahan dan keluar
    HoldnCls();

    return 0;
}