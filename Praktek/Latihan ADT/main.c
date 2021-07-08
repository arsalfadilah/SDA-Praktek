#include "date.h"
#include<stdio.h>
#include<conio.h>

int main(){
    date Tanggal, input_1, input_2;

    //Deafult :
    CreateDate(&Tanggal);
    printf("Default Create Date :\n");
    printf("Tanggal : "); PrintObj(Tanggal);
    printf("\nTanggal : %d\n", GetTgl(Tanggal));
    printf("Bulan   : %d\n", GetBln(Tanggal));
    printf("Tahun   : %d\n", GetThn(Tanggal));

    //Baca Keyboard
    printf("\nBaca dari Keyboard\n");
    BacaDate(&Tanggal);
    printf("Tanggal : "); PrintObj(Tanggal);
    printf("\nTanggal Sebelumnya  : "); DateBefore(Tanggal);
    printf("\nTanggal Selanjutnya : "); NextDate(Tanggal);
    printf("\nTanggal terakhir bulan ini : %d\n", TglAkhir(Tanggal));

    //Hittung Selisih
    printf("\nHitung Selisih");
    printf("\nDari Tanggal   : \n");
    BacaDate(&input_1);
    printf("Sampai Tanggal : \n");
    BacaDate(&input_2);

    printf("Selisih : "); SelisihDate(input_1, input_2);

    getch();

    return 0;
}
