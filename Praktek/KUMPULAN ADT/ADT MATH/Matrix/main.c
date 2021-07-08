#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int menu(){
    int pilih;

    printf("=================\n");
    printf("PROGRAM MATRIX 2D\n");
    printf("=================\n");
    printf("1. Operasi Aritmetika (+, -, *, /)\n");
    printf("2. Exit\n");

    printf("\nPilih  : ");

    scanf("%d", &pilih);

    system("pause");
    system("cls");

    return pilih;

}

int menuAritmetik(){
    int pilih;

    printf("=================\n");
    printf("PROGRAM MATRIX 2D\n");
    printf("=================\n");
    printf("1. Penjumlahan\n");
    printf("2. Pengurangan\n");
    printf("3. Perkalian\n");
    printf("4. Back\n");

    printf("\nPilih  : ");

    scanf("%d", &pilih);

    system("pause");
    system("cls");

    return pilih;

}

void prosesPenjumlahan(int stat){
        Matrix M1, M2, M3;
        Point T;

        if(stat==1)
            printf("========== PENJUMLAHAN 2 MATRIX ===========\n");
        else
            printf("========== PENGURANGAN 2 MATRIX ===========\n");

        printf("Input Ordo Matrix 1 (M x N) = ");
        inputPoint(&T);
        createMatrix(&M1, T);

        printf("Input Ordo Matrix 2(M x N) = ");
        inputPoint(&T);
        createMatrix(&M2, T);

        if(M1.Ordo.bar == M2.Ordo.bar && M1.Ordo.col == M2.Ordo.col){
            printf("Silahkan Input Matrix 1 : \n");
            inputMatrix(&M1);

            printf("\nSilahkan Input Matrix 2 : \n");
            inputMatrix(&M2);

            //Algoritma
            system("pause");
            system("cls");

            printf("Matrix 1 :\n");
            printMatrix(M1);

            if(stat == 1)
                printf("   +\n\n");
            else
                printf("   -\n\n");

            printf("Matrix 2 :\n");
            printMatrix(M2);

            printf("   =\n\n");

            printf("Result : \n");

            if(stat == 1)
                M3 = add(M1, M2);
            else
                M3 = subtract(M1, M2);

            printMatrix(M3);

        } else {
            printf("Ops Ordo Tidak Sama !");
        }

        printf("\n");
        system("pause");
        system("cls");
}

void prosesPerkalian(){

}

void prosesAritmetik(){
    int fitur = 0;

    while((fitur = menuAritmetik())!=4){
        switch(fitur){
            case 1:
                prosesPenjumlahan(fitur);
                break;
            case 2:
                prosesPenjumlahan(fitur);
                break;
            case 3:
                prosesPerkalian();
                break;
            case 4:
                break;
            default:
                printf("Sorry wrong input menu!\n");
        }
    }
}

int main()
{
    int fitur = 0;

    while((fitur = menu())!=2){
        switch(fitur){
            case 1:
                prosesAritmetik();
                break;
            case 2:
                break;
            default:
                printf("Sorry wrong input menu!\n");
                break;
        }
    }

    return 0;
}
