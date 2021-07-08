#include "stackt.h"
#include <stdio.h>
#include<string.h>

int main(){
    Stack Peserta;
    infotype a;
    CreateEmpty(&Peserta);
    //inisialisasi peserta
    strcpy(a.info_kategori, "PLN");
    strcpy(a.kategori, "BUMN");
    strcpy(a.nama, "Bcharae");
    strcpy(a.ktp, "202001030200");
    Push(&Peserta, a);
    printStack(Peserta);

    strcpy(a.info_kategori, "PLN");
    strcpy(a.kategori, "BUMN");
    strcpy(a.nama, "anda");
    strcpy(a.ktp, "202001030200");
    Push(&Peserta, a);

    printStack(Peserta);


    return 0;
}

