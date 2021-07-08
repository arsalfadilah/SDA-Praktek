#include "Line.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
    //Deklarasi dan insialisasi
    LINE l;
    POINT p1, p2;
    int x, y;

    //Algoritma
    printf("===== Program Line =====");
    
    //POINT 1
	printf("POINT 1 : ");
    scanf("%d %d", &x, &y);
    MakePoint(&p1, x, y);
    //POINT 2
    printf("POINT 2 : ");
    scanf("%d %d", &x, &y);
    MakePoint(&p2, x, y);

    //make line
    printf("\n\n");
    MakeLine(&l, p1, p2);

    //print line
    PrintLine(l);

    getch();
    system("cls");

    return 0;
}
