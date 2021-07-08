#include "Circle.h"
#include <stdio.h>

int main(){
    Circle O [2];
    POINT P;
    float r;

    //Input from user
    for(int i=0; i<2; i++){
        printf("Lingkaran %d\n", i+1);
        printf("Tentukan Titik Pusat : ");scanf("%d %d", &P.x, &P.y);
        printf("Tentukan Jari-Jari   : ");scanf("%f", &r);
        MakeCircle(&O[i], P, r);
    }

    //Cek isSame
    if(Area(O[0]) == Area(O[1])){
        printf("dua buah Circle memiliki luas area yang sama");
    } else if (Area(O[0]) < Area(O[1])){
        printf("Circle 1 memiliki luas area yang lebih kecil dibandingkan Circle 2");
    } else if(Area(O[0]) > Area(O[1])){
        printf("Circle 2 memiliki luas area yang lebih kecil dibandingkan Circle 1");
    }

    return 0;
}

