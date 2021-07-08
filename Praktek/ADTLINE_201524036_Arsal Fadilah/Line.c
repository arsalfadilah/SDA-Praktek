// / * DEFINISI TYPE LINE <POINT_START, POINT_END>  */
// 	RECORD :
//   POINT_START : POINT [integer X, integerY]
// 	  POINT_END   : POINT [integer X, integer Y]
#include "Line.h"
#include <stdio.h>

/* Prosedur membuat Line */
void MakeLine(LINE *line, POINT p1, POINT p2){
    if(!isSamePoint(p1, p2)){
        line->POINT_START = p1;
        line->POINT_END = p2;
    } else {
        printf("Sorry :(");
    }
}

/* Fungsi untuk menghasilkan sebuah LINE berdasarkan POINT yang diinput user*/
LINE CreateLine(POINT p1, POINT p2){
    LINE line;

    scanf("%d %d", &p1.x, &p1.y);
    scanf("%d %d", &p2.x, &p2.y);

    if(!isSamePoint(p1, p2)){
        line.POINT_START = p1;
        line.POINT_END = p2;
    } else {
        printf("Sorry :(");
    }

    return line;
}

/* Prosedur untuk menampilkalkan informasi Line*/
void PrintLine(LINE line){
    int panjang = PanjangLine(line);
    printf("======== INFO LINE ========\n");
    printf("Titik 1 : ");PrintPoint(line.POINT_START);
    printf("\n");
    printf("Titik 2 : ");PrintPoint(line.POINT_END);

    printf("\n\nPanjang : %d\n", panjang);
    printf("Bentuk : ");
    if(isMiring(line)){
        printf("Miring\n");
        if(
           (line.POINT_START.x < line.POINT_END.x && line.POINT_START.y < line.POINT_END.y)
           ||
           (line.POINT_START.x > line.POINT_END.x && line.POINT_START.y > line.POINT_END.y)
           ) {
            for(int i = 1; i<=panjang; i++){
                for(int j = 1; j<=panjang; j++){
                    if((j-1)+i == panjang){
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        } else {
            for(int i = 1; i<=panjang; i++){
                for(int j = 1; j<=panjang; j++){
                    if(i == j){
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
    } else if(isSejajarSbX(line)){
        printf("Sejajar Sumbu - X\n");
        for(int i = 1; i<=panjang; i++){
                for(int j = 1; j<=panjang; j++){
                    if(i == panjang/2){
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
        }
    } else if(isSejajarSbY(line)){
        printf("Sejajar Sumbu - Y\n");
        for(int i = 1; i<=panjang; i++){
                for(int j = 1; j<=panjang; j++){
                    if(j == panjang/2){
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
        }
    }

}

/* Fungsi untuk menghitung panjang antara 2 point pada sebuah line*/
int PanjangLine(LINE line){
    return Jarak(line.POINT_START, line.POINT_END);
}

/* Fungsi untuk mengecek apakah garis miring atau tidak */
boolean isMiring(LINE line){
    if(line.POINT_START.x != line.POINT_END.x && line.POINT_START.y != line.POINT_END.y)
        return true;
    else
        return false;
}

/* Fungsi untuk mengecek apakah garis sejajar sb-x */
boolean isSejajarSbX(LINE line){
    if(line.POINT_START.y == line.POINT_END.y)
        return true;
    else
        return false;
}

/* Fungsi untuk mengecek apakah garis sejajar sb-y */
boolean isSejajarSbY(LINE line){
    if(line.POINT_START.x == line.POINT_END.x)
        return true;
    else
        return false;
}

/*** SETTER/GETTER ***/
/* Prosedur untuk mengatur line*/
void setLine(LINE *line, POINT p1, POINT p2){
    MakeLine(line, p1, p2);
}

/* Function untuk mendapatkan nilai LINE */
LINE getLine(LINE line){
    return line;
}

