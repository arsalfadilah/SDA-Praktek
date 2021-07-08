// Program : Line.h
// Deskripsi : Spesifikasi ADT Line
// oleh    : Nuno Alwi Azimah
// Tgl/Version : 0.1

#include "Line.h"
#include <stdio.h>

/* Prosedur membuat Line */
void MakeLine(LINE *line, POINT p1, POINT p2){
    line->pstart = p1;
    line->pend = p2;
}

//Fungsi setter
void setPointStart(LINE *line, POINT p){
	line->pstart = p;
}

//Fungsi setter
void setPointEnd(LINE *line, POINT p){
	line->pend = p;
}

//Fungsi getter
LINE getLine(LINE l){
	return l;
}

/* Fungsi untuk menghasilkan sebuah LINE berdasarkan POINT yang diinput user*/
LINE CreateLine(POINT p1, POINT p2){
	LINE l;
	
	l.pstart = p1;
	l.pend = p2;
	
	return l;
}

/* Prosedur untuk menampilkalkan informasi Line*/
void PrintLine(LINE line){
	printf("===== LINE =====");
	printf("Point 1 : "); PrintPoint(line.pstart);
	printf("Point 2 : "); PrintPoint(line.pend);
	
	printf("Kedua point tersebut membentuk :");
	if(titik(line.pstart,line.pend) == true) printf("titik");
		else if(sumbux(line.pstart,line.pend)== true) printf("garis horizontal");
		else if(sumbuy(line.pstart,line.pend)== true) printf("garis vertikal");
		else printf("garis miring");
				
	printf("\n\n");
	printf("Dengan panjang : ");
	Jarak(line.pstart,line.pend);
		if(titik(line.pstart,line.pend) == true);
	printf("Kedua point tersebut membentuk garis :");
}

/* Fungsi untuk menghitung panjang antara 2 point pada sebuah line*/
int PanjangLine(LINE line){
	if(Jarak(line.pstart,line.pend))return true;
	else return false;
}

//Fungsi untuk melihat titik
boolean titik(POINT p1, POINT p2){
	if (p1.x == p2.x && p1.y == p2.y) return true;
	else return false;
}

//Fungsi untuk melihat apakah sejajar sumbu x
boolean sumbux(POINT p1, POINT p2){
	if (p1.x == p2.x) return true;
	else return false;
}

//Fungsi untuk melihat apakah sejajar sumbu y
boolean sumbuy(POINT p1, POINT p2){    
	if (p1.y == p2.y) return true;
	else return false;
}
