#include "Circle.h"
#include <stdio.h>

int main(){
    Circle O;
    POINT P;

    //Buat titik pusat
    MakePoint(&P, 0, 2);

    //buat lingkaran
    MakeCircle(&O, P, 11);

    //print lingkaran
    PrintCircle(O);

    //Luas Lingkaran
    printf("\n\nLuas Lingkaran : %.2f", Area(O));

    //keliling lingkran
    printf("\n\nKeliling lingkaran : %.2f", Circumf(O));

}
