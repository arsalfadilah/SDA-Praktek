// / * DEFINISI TYPE LINE <POINT_START, POINT_END>  */
// 	RECORD :
//   POINT_START : POINT [integer X, integerY]
// 	  POINT_END   : POINT [integer X, integer Y]
#include "point.h"
#include "boolean.h"
#ifndef  Line_H
#define  Line_H

typedef struct {
    POINT POINT_START;
    POINT POINT_END;
} LINE;

/* Prosedur membuat Line */
void MakeLine(LINE *line, POINT p1, POINT p2);

/* Fungsi untuk menghasilkan sebuah LINE berdasarkan POINT yang diinput user*/
LINE CreateLine(POINT p1, POINT p2);

/* Prosedur untuk menampilkalkan informasi Line*/
void PrintLine(LINE line);

/* Fungsi untuk menghitung panjang antara 2 point pada sebuah line*/
int PanjangLine(LINE line);

/* Fungsi untuk mengecek apakah garis miring atau tidak */
boolean isMiring(LINE line);

/* Fungsi untuk mengecek apakah garis sejajar sb-x */
boolean isSejajarSbX(LINE line);

/* Fungsi untuk mengecek apakah garis sejajar sb-y */
boolean isSejajarSbY(LINE line);

/*** SETTER/GETTER ***/
/* Prosedur untuk mengatur line*/
void setLine(LINE *line, POINT p1, POINT p2);

/* Function untuk mendapatkan nilai LINE */
LINE getLine();

#endif
