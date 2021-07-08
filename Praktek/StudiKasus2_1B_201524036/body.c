#include <stdio.h>
#include <math.h>
#include "header.h"

// CREATOR
//Membuat Vektor 3D
void MakeVector(VECTOR3D *v, int x, int y, int z){
	v -> i = x;
	v -> j = y;
	v -> k = z;
}

//Mengkonversi 2 integer menjadi Vektor
VECTOR3D CreateVector(int x, int y, int z){
	VECTOR3D v;
	v.i = x;
	v.j = y;
	v.k = z;
	return v;
}

//Menampilkan Vektor 3D
void PrintVector(VECTOR3D v){
	printf ("%d %d %d", v.i, v.j, v.k);
}

//GETTER
//Get (untuk mendapatkan nilai sumbu dari sebuah vektor
int GetX (VECTOR3D v){
	return v.i;
}

int GetY (VECTOR3D v){
	return v.j;
}

int GetZ (VECTOR3D v){
	return v.k;
}

//SETTER
//Set (untuk mengubah nilai sumbu dari sebuah vektor)
void SetX (VECTOR3D *v, int Xbaru){
	v -> i = Xbaru;
}

void SetY (VECTOR3D *v, int Ybaru){
	v -> j = Ybaru;
}

void SetZ (VECTOR3D *v, int Zbaru){
	v -> k = Zbaru;
}

void ResetVector (VECTOR3D *v){
	v -> i = 0;
	v -> j = 0;
	v -> k = 0;
}

//RUMUS-RUMUS
//Menentukan nilai vektor satuan
double VektorSatuan(VECTOR3D v){
	//akar(i^2 + j^2 + k^2)
	double hasil;
	hasil = sqrt(pow(v.i,2) + pow(v.j,2) + pow(v.k,2));
	return hasil;
}

//Penjumlahan Vektor
VECTOR3D PlusVector (VECTOR3D u, VECTOR3D v){
	VECTOR3D w;
	w.i = u.i + v.i;
	w.j = u.j + v.j;
	w.k = u.k + v.k;

	return w;
}

//Pengurangan Vektor
VECTOR3D MinVector (VECTOR3D u, VECTOR3D v){
	VECTOR3D w;
	w.i = u.i - v.i;
	w.j = u.j - v.j;
	w.k = u.k - v.k;

	return w;
}

//Perkalian skalar vektor
void SkalarVector (int x, VECTOR3D *v){
	v -> i = v -> i * x;
	v -> j = v -> j * x;
	v -> k = v -> k * x;
}

//Modul main buat ngetest modul modul
int main (){
    //Test Program Vektor
	int x,y,z;
	int i,j,k;
	int skalar;
	VECTOR3D v,u;
	VECTOR3D penjumlahan,pengurangan;
	double satuanU,satuanV;

    //membuat vektor dengan function
	printf("Masukkan nilai vektor 1\n");
	scanf("%d %d %d", &x, &y, &z);
	u = CreateVector(x, y, z);

    //membuat vektor dengan prosedur
	printf("Masukkan nilai vektor 2\n");
	scanf("%d %d %d", &i, &j, &k);
	MakeVector(&v, i, j, k);

	printf("Masukan nilai skalar = ");
	scanf("%d", &skalar);

	printf ("Hasil pengurangan Vektor 1 oleh Vektor 2 = ");
	pengurangan = MinVector(u,v);
	PrintVector(pengurangan);
	printf ("\n");

	printf ("Hasil penjumlahan kedua Vektor = ");
	penjumlahan = PlusVector(u,v);
	PrintVector(penjumlahan);
	printf ("\n");

	printf ("Hasil perkalian skalar vektor u = ");
	SkalarVector(skalar,&u);
	PrintVector(u);
	printf ("\n");

	printf ("Hasil perkalian skalar vektor v = ");
	SkalarVector(skalar,&v);
	PrintVector(v);
	printf ("\n");

	printf ("Hasil vektor u satuan = ");
	satuanU = VektorSatuan(u);
	printf ("%.2f", satuanU);
	printf ("\n");

	printf ("Hasil vektor v satuan = ");
	satuanV = VektorSatuan(v);
	printf ("%f", satuanV);
	printf ("\n");

	return 0;
}
