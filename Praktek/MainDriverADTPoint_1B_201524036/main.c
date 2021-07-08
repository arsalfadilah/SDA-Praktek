#include "point.h"
#include <stdio.h>

int main(){
    //Dekalarasi dan insialisasi
    POINT titik;

    //Make Point
    printf("Make Point\n");
    MakePoint(&titik, 10, 30);
    printf("Hasilnya :\n");
    PrintPoint(titik);

    //Reset Point
    printf("\n\nReset Point (0, 0)\n");
    ReSet(&titik);
    printf("Hasilnya :\n");
    PrintPoint(titik);

    //Create Point
    printf("\n\nCreate Point\n");
    titik = CreatePoint(20, 1);
    printf("Hasilnya :\n");
    PrintPoint(titik);

    //Get X
    printf("\n\nGet X\n");
    printf("X : %d\n", GetX(titik));

    //Set X
    printf("\nSet X = %d\n", GetX(titik)-8);
    SetX(&titik, GetX(titik)-8);
    printf("Hasilnya :\n");
    PrintPoint(titik);

    //Get Y
    printf("\n\nGet Y\n");
    printf("Y : %d\n", GetY(titik));

    //Set X
    printf("\nSet Y = %d\n", GetY(titik)+23);
    SetY(&titik, GetY(titik)+23);
    printf("Hasilnya :\n");
    PrintPoint(titik);

    //Kuadran
    printf("\n\nKuadran manakah ");PrintPoint(titik);printf(" ?\n");
    printf("Jawab : %d\n", Kuadran(titik));

    //Cek apakah ada di sumbu X
    printf("\nTitik ");PrintPoint(titik);printf(" berada di sumbu X ?\n");
    if(IsOnSumbuX(titik)){
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    //Cek apakah ada di sumbu Y
    printf("\nTitik ");PrintPoint(titik);printf(" berada di sumbu Y ?\n");
    if(IsOnSumbuY(titik)){
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    //Cek apakah ada di Origin (0, 0)
    printf("\nTitik ");PrintPoint(titik);printf(" berada di Origin (0, 0) ?\n");
    if(IsOrigin(titik)){
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    //Next X
    printf("\nNext X (1 satuan ke kanan)\n");
    NextX(&titik);
    printf("Hasilnya :\n");
    PrintPoint(titik);

    //Next X dengan N satuan
    int N = 3;
    printf("\n\nNext X (%d satuan ke kanan)", N);
    NextX_N(&titik, N);
    printf("Hasilnya :\n");
    PrintPoint(titik);

    //Prev X
    printf("\n\nPrev X (1 satuan ke kanan)\n");
    PrevX(&titik);
    printf("Hasilnya :\n");
    PrintPoint(titik);

    //Prev X dengan N satuan
    N = 7;
    printf("\n\nPrev X (%d satuan ke kanan)", N);
    PrevX_N(&titik, N);
    printf("Hasilnya :\n");
    PrintPoint(titik);

    //Jarak antara dua titik
    POINT titik_2;
    MakePoint(&titik_2, 2, 5);
    printf("\n\nJarak antara Titik 1 ");PrintPoint(titik);
    printf(" dan Titik 2 ");PrintPoint(titik_2);
    printf(" = %d satuan\n", Jarak(titik, titik_2));

    return 0;
}
