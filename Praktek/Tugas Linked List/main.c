#include <stdio.h>
#include <conio.h>
#include "list1.h"

int main (){
    int temp;
    List thisList;
    List scLt;
    List baru;

    //inisialisasi
    thisList.First = Nil;
    scLt.First = Nil;
    baru.First = Nil;

    //Algoritma
    //insert di awal :
    printf("Menginisialiasi List menggunakan insert firs with infotype");

    //print semua list
    printf("\nList Pertama\n");
    InsVFirst(&thisList, 10);
    InsVFirst(&thisList, 21);
    InsVFirst(&thisList, 1);
    InsVLast(&thisList, 1023);
    InsVLast(&thisList, 19);
    PrintInfo(thisList);

    printf("\nList Kedua\n");
    InsVFirst(&scLt, 90);
    InsVFirst(&scLt, 31);
    InsVFirst(&scLt, 902);
    PrintInfo(scLt);

    printf("\nList Baru\n");
    InsVLast(&baru, 98);
    InsertLast(&baru, Alokasi(10));
    PrintInfo(baru);

    //invers list
    InversList(&thisList);
    printf("\nReverse list . . .\n");
    PrintInfo(thisList);

    //copy paste list
    printf("\nHasil Copy list Pertama ke Baru");
    //CopyList(thisList, &baru);
    printf("\nIni list pertama (copy)\n");
    PrintInfo(thisList);
    printf("\nIni list baru (paste)\n");
    baru = FCopyList(thisList);
    PrintInfo(baru);

    //invers list dengan mengirimkan list baru
    //CopyList(thisList, &baru);
    baru = FInversList(baru);
    printf("\nReverse list dengan mengirimkan list baru\n");
    PrintInfo(baru);

//
    //Deleting
    DelVFirst(&thisList, &temp);
//
    //print lagi
    printf("\nList dengan element info : %d (has been deleted)\n", temp);
    PrintInfo(thisList);
//
    //Deleting
    DelVLast(&thisList, &temp);

    //print lagi
    printf("\nList dengan element info : %d (has been deleted)\n", temp);
    PrintInfo(thisList);

    //insert with address
    InsertFirst(&thisList, Alokasi(98));
    printf("\nList insert First menggunakan address\n");
    PrintInfo(thisList);

    //insert after element cari;
    int cari = 98;
    printf("\nList insert After %d menggunakan address\n", cari);
    InsertAfter(&thisList, Alokasi(24), Search(thisList, cari));
    PrintInfo(thisList);

    //Insert last with address
    printf("\nInsert last with address\n");
    InsertLast(&thisList, Alokasi(199));
    PrintInfo(thisList);

    //mencari element terbesar
    printf("\nElement maximum di list ini adalah : %d", Max(thisList));
//
//
    //Delete element with address
    address var;
    DelFirst(&thisList, &var);
    printf("\nList element dengan alamat : %x dan info : %d (has been deleted)\n", var, var->info);
    PrintInfo(thisList);

    //Delete with info
    cari =1023;
    DelP(&thisList, cari);
    printf("\nList element info %d (has been deleted)\n", cari);
    PrintInfo(thisList);
//
//    //delete last with address
    DelLast(&thisList, &var);
    printf("\nList element last dengan alamat : %x dan info : %d (has been deleted)\n", var, var->info);
    PrintInfo(thisList);

    //isi ulang
    DelAll(&thisList);
    InsVFirst(&thisList, 10);
    InsVFirst(&thisList, 2);
    InsVFirst(&thisList, 37);
//
//    //delete after with address
    cari = 2;
    DelAfter(&thisList, &var, Search(thisList, cari));
    printf("\nList element dengan alamat: %x dan info : %d (has been deleted\n", var, var->info);
    PrintInfo(thisList);

    //menghitung banaknya list
    printf("\nJumlah list sekarang : %d\n", NbElmt(thisList));

    //mencari elemenet terbesar
    printf("\nElement maximum di list ini adalah : %d\n", Max(thisList));

    //mencari alamat dari element terbesar
    printf("\nElement terbesar di list yaitu alamat %x mempunyai info %d", AdrMax(thisList), AdrMax(thisList)->info);

    //mencari min info
    printf("\nElement terkecil di list ini adalah %d", Min(thisList));

    //mencari min dengan address
    printf("\nElement terkecil di list yaitu alamat %x mempunyai info %d", AdrMin(thisList), AdrMin(thisList)->info);

    //menghitung average
    printf("\nJumlah rata-rata dari list ini adalah %.2f", Average(thisList));
//
    //delete semua element list
    DelAll(&thisList);
    printf("\nElement list delete all\n");
    PrintInfo(thisList);

    return 0;
}
