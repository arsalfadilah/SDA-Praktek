/* File             : rectangle.c
 * Deskripsi        : Implementasi modul interface dari Spesifikasi ADT Rectangle
 * Dibuat oleh      : Team Teaching SDA
 * Dimodifikasi oleh:
 * Tanggal/versi    : 22 April 2021/ 01
 * ================================================================
 */

 #include "rectangle.h"
#include <stdlib.h>
#include <stdio.h>

/* Prosedur membuat Rectangle berdasarkan titik atas dan titik bawah
I.S. Rectangle belum terdefinisi
F.S. Rectangle sudah terdefinisi
*/
void MakeRectangle(RECTANGLE *rect, POINT t_atas, POINT t_bawah){

    rect->titik_atas = t_atas;
    rect->titik_bawah = t_bawah;
}

/* Fungsi untuk menghasilkan sebuah Rectangle berdasarkan titik atas dan titik bawah*/
RECTANGLE CreateRectangle(POINT t_atas, POINT t_bawah){
    RECTANGLE K;
    MakeRectangle(&K, t_atas, t_bawah);
    return K;
}

/* Prosedur untuk menampilkan informasi Rectangle dengan format
   titik_atas (x,y) dan titik_bawah (x,y)
I.S. Informasi Rectangle belum ditampilkan ke layar
F.S. Informasi Rectangle sudah ditampilkan sesuai dengan format yang disebutkan
*/
void PrintRectangle(RECTANGLE rect){
    POINT b, c;
    b = rect.titik_atas;
    c = rect.titik_atas;
    b.x = b.x + getLebar(rect);
    c.y = c.y + getPanjang(rect);
    printf("Rectangle berhasil di buat dengan posisi : \n");
    printf("\nTitik atas  (p1) : ");PrintPoint(rect.titik_atas);
    printf("\nTitik (P2)     : ");PrintPoint(b);
    printf("\nTitik (P3)     : ");PrintPoint(c);
    printf("\nTitik bawah (p4) : ");PrintPoint(rect.titik_bawah);

}

/* Fungsi untuk mengetahui panjang dari rectangle
   p  = titik_bawah.x - titik_atas.x;
*/
int getPanjang(RECTANGLE rect){
    int p;
    p = rect.titik_bawah.x - rect.titik_atas.x;
    return p;
}

/* Fungsi untuk mengetahui lebar dari rectangle
   l  = titik_bawah.y - titik_atas.y;
*/
int getLebar(RECTANGLE rect){
    int l;
    l = rect.titik_bawah.y - rect.titik_atas.y;
    return l;
}

/* Fungsi untuk menghitung luas Rectangle*/
int LuasRectangle(RECTANGLE rect){
    int luas;

    luas = getPanjang(rect) * getLebar(rect);

    return luas;

}

/* Fungsi untuk menghitung keliling Rectangle*/
int KelilingRectangle(RECTANGLE rect){
    int keliling;
    keliling = 2 * (getPanjang(rect) + getLebar(rect));
    return keliling;
}
