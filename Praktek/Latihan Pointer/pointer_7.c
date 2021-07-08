/*
Nama Program : Mysteri.c
Deskripsi : Belum Tahu saya
Programmer : [1B]-[201524036]/[Arsal Fadilah]
Tanggal :
Versi :
*/
#include <stdio.h>
int main() {
    int *intPtr;
    double *dubPtr;

    //deklarasi var integer dan double
    int int1, int2, int3, int4, int5;
    double dub1, dub2, dub3, dub4, dub5;

    /*Inisialisasi nilai variabel*/
    int1=54; int2=10; int3=96; int4=21; int5=88;
    dub1=64.32; dub2=143.3; dub3=79.12; dub4=76.78; dub5=52.5;
    //inisial pointer
    intPtr=&int1;
    dubPtr=&dub1;

    //Output 1
    printf("Output 1 : Variabel bertipe integer dan double \n\n");
    printf("Tipe integer : \n");
    printf("int1 = %d, int2 = %d, int3 = %d, int4 = %d, int5 = %d \n\n", int1, int2, int3, int4, int5);
    printf("Tipe double : \n");
    printf("dub1 = %g, dub2 = %g, dub3 = %g, dub4 = %g, dub5 = %g ", dub1, dub2, dub3, dub4, dub5);

    //Output 2 :
    //Menampilkan alamat (dan pointer) dalam hexa
    printf("\n\nOutput 2 : Alamat dan variabel pointer bertipe integer : \n");
    printf("Alamat memori int1, int2, int3, int4 dan int5 : %x, %x %x %x %x", &int1, &int2, &int3, &int4, &int5);
    printf("\n\n Menampilkan data integer menggunakan pointer (+decrement) : *(intPtr) *(--intPtr) *(--intPtr)\n\n");
    printf("--> *intPtr = %d",*intPtr);
    printf("\n--> *(--intPtr) = %d",*(--intPtr));
    printf("\n--> *(--intPtr) = %d",*(--intPtr));
    printf("\n\n Menampilkan data integer menggunakan pointer (+increment) : *(intPtr) *(++intPtr) *(++intPtr)\n\n");
    printf("--> *intPtr = %d",*intPtr);
    printf("\n--> *(++intPtr) = %d",*(++intPtr));
    printf("\n--> *(++intPtr) = %d",*(++intPtr));
    //Pertanyaan : alamat &int4 dan &int5 ?

    //Output 3 : Alamat dan variabel pointer bertipe double
    printf("\n\nOUTPUT 3 : Alamat dan Variabel Pointer bertipe double ");
    printf("\nAlamat Memori : dub1 = %x, dub2 = %x, dub3 = %x , dub4 = %x , dub5 = %x ", &dub1, &dub2, &dub3,&dub4,&dub5);

    //inisial dari akhir dub;
    dubPtr=&dub5;
    printf("\n\nIsi dari dubPtr : %x", dubPtr);
    printf("\nMenampilkan data double menggunakan pointer (+increment) : *(dubPtr), *(++dubPtr), *(++dubPtr)");
    printf("\n*(dubPtr) : %g", *(dubPtr));
    printf("\n*(++dubPtr) : %g", *(++dubPtr));
    printf("\n*(++dubPtr) : %g", *(++dubPtr));
    printf("\n\nIsi dari dubPtr : %x", dubPtr);
    printf("\n\nMenampilkan data double menggunakan pointer (-decrement) : *(dubPtr), *(--dubPtr), *(--dubPtr)");
    printf("\n*(dubPtr) : %g", *(dubPtr));
    printf("\n*(--dubPtr) : %g", *(--dubPtr));
    printf("\n*(--dubPtr) : %g", *(--dubPtr));
    printf("\nFs isi dari intPtr dan dubPtr : %x %x \n", intPtr, dubPtr);
    printf("Alamat dari intptr : %x\n", &intPtr);
    printf("Alamat dari dubptr : %x\n", &dubPtr);

    return 0;
}
