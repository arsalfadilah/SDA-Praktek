// Program : Line.h
// Deskripsi : Spesifikasi ADT Line
// oleh    : Nuno Alwi Azimah
// Tgl/Version : 0.1

#include "point.h"
#include "boolean.h"
#ifndef  Line_H
#define  Line_H
/* DEFINISI TYPE LINE <POINT_START, POINT_END>  
	RECORD :
  	POINT_START : POINT [integer X, integerY]
	POINT_END   : POINT [integer X, integer Y] 
*/
typedef  struct{  
	POINT pstart;
	POINT pend;
} LINE; // type POINT
	
	

/* Prosedur membuat Line */
void MakeLine(LINE *line, POINT p1, POINT p2);

//Fungsi setter
void setPointStart(LINE *line, POINT p);

//Fungsi setter
void setPointEnd(LINE *line, POINT p);

//Fungsi getter
LINE getLine(LINE line);

/* Fungsi untuk menghasilkan sebuah LINE berdasarkan POINT yang diinput user*/
LINE CreateLine(POINT p1, POINT p2);

/* Prosedur untuk menampilkalkan informasi Line*/
void PrintLine(LINE line);

/* Fungsi untuk menghitung panjang antara 2 point pada sebuah line*/
int PanjangLine(LINE line);

//Fungsi untuk melihat apakah miring
boolean titik(POINT p1, POINT p2);

//Fungsi untuk melihat apakah sejajar sumbu x
boolean sumbux(POINT p1, POINT p2);

//Fungsi untuk melihat apakah sejajar sumbu y
boolean sumbuy(POINT p1, POINT p2);

#endif
