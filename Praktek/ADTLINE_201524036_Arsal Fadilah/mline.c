#include "Line.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
    //Deklarasi dan insialisasi
    LINE line;
    POINT p1, p2;
    boolean sama = true;
    int x, y;

    //Algoritma
    do{
        printf("==== Program Line ====");
        printf("\nMasukan Titik 1 : ");
        scanf("%d %d", &x, &y);
        MakePoint(&p1, x, y);
        printf("Masukan Titik 2 : ");
        scanf("%d %d", &x, &y);
        MakePoint(&p2, x, y);
        sama = isSamePoint(p1, p2);
        if(sama){
            printf("\nGak bisa buat garis karena kedua titik sama");
            getch();
        }
        //tahan dan hapus
        system("cls");
    } while(sama);

    //Membuat line
    MakeLine(&line, p1, p2);

    //print info line
    PrintLine(line);

    //tahan dan hapus
    getch();
    system("cls");

    return 0;
}
