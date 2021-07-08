#include <stdio.h>

int main() {
/*Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    char *pkota = "BANDUNG";

    printf("%c", *(pkota+1));
    //puts(pkota+2);
    return 0;
}
