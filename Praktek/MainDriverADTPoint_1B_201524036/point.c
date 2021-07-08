#include <stdio.h>
#include <math.h>
#include "point.h"

// Program : Point.h
// Deskripsi : Spesifikasi ADT Point
// oleh    : Ani Rahmani
// Tgl/Version
//

/* definisi type data */
//typedef  struct
//  {  int  x;
//		int y;
//} POINT; // type POINT


/*  Prototype */

/*KELOMPOK CREATOR */

void MakePoint(POINT *P, int XX, int YY){
/*Prosedur untuk membuat POINT dengan nilai dari user*/
    P->x = XX;
    P->y = YY;
}


POINT CreatePoint (int XX, int YY){
/*Fungsi untuk menghasilkan sebuah POINT berdasarkan nilai-nilai dari user*/
    POINT P;

    P.x = XX;
    P.y = YY;

    return P;
}

/*KELOMPOK VALIDASI*/

/*KELOMPOK PRINT/CETAK*/
void PrintPoint(POINT P){
/* Menampilkan POINT */
    printf("%d %d", P.x, P.y);
}


/* KELOMPOK GET / SET */

int GetX(POINT P){
/*Mengembalikan nilai x dari sebuah POINT */
    return P.x;
}


void SetX(POINT *P, int newX){
/* Mengubah nilai X dari sebuah POINT */
    P->x = newX;
}


int GetY(POINT P){
/*Mengembalikan nilai y dari sebuah POINT */
    return P.y;
}


void SetY(POINT *P, int newY){
/* Mengubah nilai Y dari sebuah POINT */
    P->y = newY;
}

void ReSet(POINT *P){
/* Mengubah koordinat sebuah POINT menjadi 0,0 */
    P->x = 0;
    P->y = 0;
}

/*KELOMPOK LAIN */
int Kuadran(POINT P){
/* menghasilkan kuadran dari POINT P*/
    if(P.x > 0 && P.y > 0){
        return 1;
    } else if(P.x < 0 && P.y > 0){
        return 2;
    } else if(P.x < 0 && P.y < 0){
        return 3;
    } else if(P.x > 0 && P.y < 0){
        return 4;
    } else {
        return 0;
    }
}

boolean IsOnSumbuX(POINT P){
/* Mengirimkan True jika P ada di sumbu X  */
    if(P.y == 0){
        return true;
    } else {
        return false;
    }
}

boolean IsOnSumbuY(POINT P){
/* Mengirimkan True jika P ada di sumbu Y  */
    if(P.x == 0){
        return true;
    } else {
        return false;
    }
}

boolean IsOrigin(POINT P){
/* Mengirimkan True jika P ada di titik pusat */
    if(P.x == 0 && P.y==0){
        return true;
    } else {
        return false;
    }
}

void NextX(POINT *PP){
/* Menggeser P 1 koordinat ke kanan*/
    PP->x = PP->x + 1;
}

void NextX_N(POINT *PP, int N){
/* Menggeser P, sejauh N koordinat ke kanan*/
    PP->x = PP->x + N;
}

void PrevX(POINT *P){
/* Menggeser P 1 koordinat ke kiri*/
    P->x = P->x - 1;
}

void PrevX_N(POINT *P, int N){
/* Menggeser P, sejauh N koordinat ke kiri */
    P->x = P->x - N;
}

/*MENGHITUNG JARAK DUA POINT */
int Jarak (POINT P1, POINT P2){
/*Menghasilkan jarak P1 dan P2 */
    int hasil = 0;
    hasil = sqrt((pow((P2.x-P1.x), 2) + pow((P2.y-P1.y), 2)));

    return hasil;
}
