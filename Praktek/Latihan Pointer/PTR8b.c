#include <stdio.h>
int main() {
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    char *nama1 = "DEWI SARTIKA";
    char *nama2 = "SULTAN HASANUDDIN";
    char *namaX;
    puts("Nama semula : ");
    printf("Nama 1 --> %s\n", nama1);
    printf("Nama 2 --> %s\n", nama2);
/* Pertukaran string */
    namaX = nama1;
    nama1 = nama2;
    nama2 = namaX;
//    strcpy(namaX, nama1);
//    strcpy(nama1, nama2);
//    strcpy(nama2, namaX);
    puts("Nama sekarang : ");
    printf("Nama 1 --> %s\n", nama1);
    printf("Nama 2 --> %s\n", nama2);
    return 0;
}
