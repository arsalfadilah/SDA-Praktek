/*
ADT untuk mempermudah menjawab soal-soal vektor dasar
*/

#include <stdio.h>
#include <math.h>
#ifndef vector_H
#define vector_H

/* definisi type data */
typedef  struct
  {  int  i;
		int j;
		int k;
} VECTOR3D; // type Vektor 3 Dimensi

// CREATOR
//Membuat Vektor 3D
void MakeVector(VECTOR3D *v, int x, int y, int z);

//Mengkonversi 2 integer menjadi Vektor
VECTOR3D CreateVector(int x, int y, int z);

//Menampilkan Vektor 3D
void PrintVector(VECTOR3D v);

//GETTER
//Get (untuk mendapatkan nilai sumbu dari sebuah vektor
int GetX (VECTOR3D v);

int GetY (VECTOR3D v);

int GetZ (VECTOR3D v);

//SETTER
//Set (untuk mengubah nilai sumbu dari sebuah vektor)
void SetX (VECTOR3D *v, int Xbaru);

void SetY (VECTOR3D *v, int Ybaru);

void SetZ (VECTOR3D *v, int Zbaru);

void ResetVector (VECTOR3D *v);

//RUMUS-RUMUS
//Menentukan nilai vektor satuan
double VektorSatuan(VECTOR3D v);

//Penjumlahan Vektor
VECTOR3D PlusVector (VECTOR3D u, VECTOR3D v);

//Pengurangan Vektor
VECTOR3D MinVector (VECTOR3D u, VECTOR3D v);

//Perkalian skalar vektor
void SkalarVector (int x, VECTOR3D *v);

#endif
