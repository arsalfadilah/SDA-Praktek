/* File             : mrectangle.h
 * Deskripsi        : alur program sesuai dengan kasus ADT Rectangle
 * Dibuat oleh      : kelas, Nim, Nama
 * Dimodifikasi oleh:
 * Tanggal/versi    : 22 April 2021/ 01
 * ================================================================
 */

#include "rectangle.h"
#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	POINT titik, a, b, c, d;
	RECTANGLE kotak;
	int lebar, tinggi;
	int x, y;
	printf("Input Point awal (x,y) : ");
    scanf("%d %d", &x, &y);
    MakePoint(&titik, x, y);
    a = titik;
    d = titik;

    printf("Input lebar  : ");scanf("%d", &lebar);
    printf("Input tinggi : ");scanf("%d", &tinggi);


    d.x += lebar;
    d.y += tinggi;

    MakeRectangle(&kotak, a, d);

    printf("====Output=====\n");
    PrintRectangle(kotak);


    printf("\n\nLuas persegi panjang     : %d\n", LuasRectangle(kotak));
    printf("Keliling persegi panjang : %d\n", KelilingRectangle(kotak));

	return 0;
}
