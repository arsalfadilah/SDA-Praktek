//Library
#include "list1.h"
#include<stdio.h>
#include<conio.h>
#include<windows.h>

/******* Program List *******/
/**
    Author : Arsal Fadilah
    Versi  : V.01
**/

//Modul
void displayMenu(){
    //Deklarasi dan inisialisasi
    //Algoritma
    printf("---- MENU ----\n");
    printf("1. Inisialisasi List\n");
    printf("2. Insert List\n");
    printf("3. delete List\n");
    printf("4. Search in List\n");
    printf("5. Print List\n");
    printf("6. Exit\n");
    printf("Input your choose : ");
}

int inputInt(){
    //Deklarasi dan inisialisasi
    int x;

    //Algoritma
    scanf("%d", &x);

    return x;
}

void initList(List * L){
    //Deklarasi dan inisialisasi
    int n, x;

    //Algoritma

    DelAll(L);

    printf("Total Element : "); n = inputInt();

    for(int i=0; i<n; i++){
        printf("Element %d : ", i+1);x = inputInt();
        InsVLast(L, x);
    }

}

void insertList(List * L){
    //Deklarasi dan insialisasi
    int f, X, n;
    //Algoritma
    printf("Do u want insert in :\n");
    printf("1. First\n");
    printf("2. After X\n");
    printf("3. Last\n");
    printf("Your choose : ");f = inputInt();

    printf("Add your element : "); n = inputInt();

    switch(f){
        case 1: InsVFirst(L, n);break;
        case 2:
            PrintInfo(*L);
            printf("\nAfter : "); X = inputInt();
            InsertAfter(L, Alokasi(n), Search(*L, X));
            break;
        case 3 : InsVLast(L, n); break;
        default :
            printf("\nOps, Something Wrong\n");
    }

}

void deleteList(List *L){
    //Deklarasi dan inisialisasi
    int n, x;
    address temp;
    //Algoritma
    printf("Do u want delete in :\n");
    printf("1. First\n");
    printf("2. Last\n");
    printf("3. Spesifik element\n");
    printf("4. All\n");
    printf("Your choose : "); n = inputInt();

    switch(n){
        case 1: DelFirst(L, &temp); break;
        case 2: DelLast(L, &temp); break;
        case 3:
            PrintInfo(*L);
            printf("\nElement do u want to delete = ");
            x = inputInt();
            DelP(L, x);
            break;
        case 4: DelAll(L);break;
        default :
            printf("\nOps, Something Wrong\n");
    }

}

void searchList(List L){
    //Deklarasi dan inisialisasi
    int n, x;
    address fsrch;

    //Algoritma
    printf("Search Infotype : ");
    x = inputInt();

    fsrch = Search(L, x);

    if(fsrch == Nil){
        printf("Infotype %d tidak ditemukan\n", x);
    } else {
        printf("Infotype %d ada di alamat : %x\n", fsrch->info, fsrch);
    }

}

//Modul Interface
void clrps(){
    //Deklarasi dan insialiasi
    //Algoritma
    printf("\n");
    system("pause");
    system("cls");
}

//Modul main
int main(){
    //Deklarasi dan insialisasi
    List L1;
    L1.First = Nil;
    int fitur = 0;

    //Algoritma
    while(fitur!=6){
        displayMenu();
        fitur = inputInt();

        //FITUR
        switch(fitur){
            case 1: initList(&L1);break;
            case 2: insertList(&L1);break;
            case 3: deleteList(&L1);break;
            case 4: searchList(L1);break;
            case 5: PrintInfo(L1); break;
            case 6: printf("BYE BYE");break;
            default :
                printf("\nOps, Something Wrong\n");
        }
        clrps();
    }

    return 0;
}
