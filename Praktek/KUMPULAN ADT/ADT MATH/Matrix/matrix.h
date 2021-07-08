/*** By PROGUSA ***/
/***
=======================
Maximal Ordo Matrix yang
bisa di proses adalah 100 x 100
=======================
***/

#ifndef matrix_h
#define matrix_h
#define MaxElement 100
#define matrix(M) ((M).matrix[i][j])
#define Ordo(M) ((M).Ordo)

#include<stdio.h>
#include<stdbool.h>

/*** Kamus Data ***/
typedef struct{
    int bar;
    int col;
} Point;

typedef int infotype;

typedef struct {
    infotype matrix[MaxElement+1][MaxElement+1];
    Point Ordo;
} Matrix;

/*** Operasi Primitif Pada Matrix ***/
/*** Konstruktor ***/
void createMatrix(Matrix *M, Point N);

void inputMatrix(Matrix *M);

void inputPoint(Point *X);

/*** Accessors ***/
int getElement(Matrix M, int Bar, int Col);

/*** Destructor ***/
void deleteMatrix(Matrix *M);

/*** Mutator ***/
void setElement(Matrix *M, Point X, infotype Number);

/*** Operasi Pendukung ***/
void printMatrix(Matrix M);

Matrix add(Matrix M1, Matrix M2);

Matrix subtract(Matrix M1, Matrix M2);

/*** Cek-cekan ***/
bool isOrdoValid(Matrix M);

#endif

/*** Body dari Modul-Modul Declaration ***/
/*** Konstruktor ***/
void createMatrix(Matrix *M, Point N){
    //Set Ordo
    Ordo(*M) = N;
    if(isOrdoValid(*M)){
        //Set Isi Matrix Semua Nol
        for(int i = 1; i<=N.bar; i++){
            for(int j = 1; j<=N.col; j++){
                matrix(*M) = 0;
            }
        }
    } else {
        printf("Sorry Your Ordo is out of RANGE :(");
    }
}

void inputPoint(Point *X){
    scanf("%d %d", &(*X).bar, &(*X).col);
}

void inputMatrix(Matrix *M){
    Point X = Ordo(*M);
    Point input;
    int num;
    for(int i = 1; i <= X.bar; i++){
        for(int j = 1; j<= X.col; j++){
            scanf("%d", &num);
            input.bar =  i;
            input.col = j;
            setElement(&(*M), input, num);
        }
    }
}

/*** Accessors ***/
int getElement(Matrix M, int Bar, int Col){
    return M.matrix[Bar][Col];
}

/*** Destructor ***/
void deleteMatrix(Matrix *M){
    Point N = Ordo(*M);
    //Kembalikan Matrix Semuanya jadi Nol
    for(int i = 0; i<N.bar; i++){
        for(int j = 0; j<N.col; j++){
            matrix(*M) = 0;
        }
    }
}

/*** Mutator ***/
void setElement(Matrix *M, Point X, infotype Number){
    ((*M).matrix[X.bar][X.col]) = Number;
}

/*** Operasi Pendukung ***/
void printMatrix(Matrix M){
    for(int i = 1; i<=M.Ordo.bar; i++){
        for(int j = 1; j<=M.Ordo.col; j++){
            printf(" [ %d ] ", matrix(M));
        }
        printf("\n\n");
    }
}

Matrix add(Matrix M1, Matrix M2){
    Matrix M3;
    Point T, input;

    //Syarat harus sama ordo M1 dan M2
    if(M1.Ordo.bar == M2.Ordo.bar && M1.Ordo.col == M2.Ordo.col){
        //M2.ordo atau M1.ordo sama saja
        createMatrix(&M3, M2.Ordo);
        T = Ordo(M2);

        for(int i = 1; i<=T.bar; i++){
            for(int j = 1; j<=T.col; j++){
                input.bar = i;
                input.col = j;
                setElement(&M3, input, (getElement(M1, i, j) + getElement(M2, i, j)));
            }
        }
    } else {
        printf("OPS Ordo Tidak sama");
    }

    return M3;
}

Matrix subtract(Matrix M1, Matrix M2){
    Matrix M3;
    Point T, input;

    //Syarat harus sama ordo M1 dan M2
    if(M1.Ordo.bar == M2.Ordo.bar && M1.Ordo.col == M2.Ordo.col){
        //M2.ordo atau M1.ordo sama saja
        createMatrix(&M3, M2.Ordo);
        T = Ordo(M2);

        for(int i = 1; i<=T.bar; i++){
            for(int j = 1; j<=T.col; j++){
                input.bar = i;
                input.col = j;
                setElement(&M3, input, (getElement(M1, i, j) - getElement(M2, i, j)));
            }
        }
    } else {
        printf("OPS Ordo Tidak sama");
    }

    return M3;
}

/*** Cek-cekan ***/
bool isOrdoValid(Matrix M){
    if(M.Ordo.bar <= MaxElement && M.Ordo.col <= MaxElement)
        return true;
    else
        return false;
}
