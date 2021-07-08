/**
ADT untuk mengoperasikan sebuah matrix untuk
mempermudah belajar mata kuliah aljabar linier
**/

#include "Matrix.h"

/**Definisi Tipe Data**/
//typedef int [][] Matrix;
//typedef Cell Ordo;
//typedef struct {
//    int M; //Baris
//    int N; //Kolom
//} Cell;
//
//typedef struct {
//    Matrix X;
//    Ordo O;
//}matrix;

/***PROTOTYPE***/

/**Kelompok Creator**/
void makeMatrix(matrix *M, Ordo A){
//prosedur membuat matrix dengan ordo A (N x M);
    M->X[A.M][A.N];
}

matrix createMatrix(Ordo A){
    matrix Mtrx;
    Mtrx.O = A;

    return Mtrx;
}
//Function membuat matrix dengan orodo A (N x M);

/**Kelompok Setter/Getter**/
void setElementMatrix(matrix *M, Cell cell, int C);
//Function membuat semua element matrix M menjadi C;

void setOrdoMatrix(Ordo *A, int X, int Y);
//Prosedur untuk membuat ordo matrix

int getElementMatrix(matrix M, Ordo RC);
//Mendapatkan element matrix dari baris dan kolom

/**Kelompok Validasi**/
boolean isMatrixPersegi(matrix M);
//Mengecek apakah matrix M isi atau tidak;

boolean isDetMatrix0(matrix M);
//Mengecek apakah determinan dari matrix M = 0

boolean isElementMatrix(matrix M, int E);
//Mencari apakah ada element E di matrix M

/**Kelompok Print/Cetak**/
void printMatrix(matrix M);
//Menampilkan isi dari matrix M

/**Kelompok Lain**/
int detMatrix(matrix M);
//Menghitung determinant dari matrix M

void mltplyMtxByConts(matrix M, int C);
//Menghitung matrix M dikali dengan Konstan

/**cukup sekian dulu**/

#endif // Matrix_H
