// Program   : Circle.h
// Deskripsi : Spesifikasi ADTCircle
// Oleh      : Ani Rahmani
// Tanggal / Version :
//
#include<stdio.h>
#include <math.h>
#include "boolean.h"
#include "point.h"
#include "Circle.h"
//
//#ifndef  CIRCLE_H
//#define  CIRCLE_H
//
//
///* definisi type data */
//typedef  struct
//  {  POINT  P;
//     float  r;
//} Circle; // type Circle
//
//
///*  Prototype */
//
///*KELOMPOK CREATOR */

void MakeCircle(Circle *O, POINT P, float r){
/*Prosedur untuk membuat Circle dengan nilai dari user*/
    O->P = P;
    O->r = r;
}


Circle CreateCircle (int XX, int YY, float R){
/*Fungsi untuk menghasilkan sebuah Circle berdasarkan nilai-nilai dari user*/
    Circle O;
    POINT P = CreatePoint(XX, YY);
    O.P = P;
    O.r = R;
    return O;
}

/*KELOMPOK VALIDASI*/

/*KELOMPOK Get/Set */

float GetRadius(Circle C){
/* mengembalikan nilai radius dari sebuah Circle */
    return C.r;
}

void SetRadius(Circle *C1, float R){
/* Mengubah nilai Radius sebuah Circle */
    C1->r = R;
}

/*KELOMPOK PRINT/CETAK*/
void PrintCircle(Circle C){
/* Menampilkan Circle : Titik Pusat & Radius */
    printf("Titik Pusat : ");PrintPoint(C.P);
    printf("\nJari-jari   : ");printf("%.2f", C.r);
}

/*KELOMPOK LAIN */
float Area(Circle C1){
/* menghasilkan nilai Luas dari Circle C1*/
    double phi_1 = 3.14;
    int r = C1.r;

    if(r % 7 == 0)
        return ((22*pow(C1.r, 2))/7);
    else
        return (phi_1*pow(C1.r, 2));

}

float Circumf(Circle C1){
/* menghasilkan nilai Keliling dari Circle */
    double phi_1 = 3.14;
    int r = C1.r;

    if(r % 7 ==0)
        return ((2 * 22 * C1.r)/7);
    else
        return (2 * phi_1* C1.r);
}

boolean CompareCircle(Circle C1, Circle C2){
/* menghasilkan True jika Luas C1 = C2, Gunakan fungsi Luas */
    if(Area(C1) == Area(C2)){
        return true;
    } else {
        return false;
    }
}

Circle CopyCircle(Circle C1){
/*Mengembalikan sebuah Circle */
    return C1;
}

