#include <stdio.h>
//hapus include
int main() {
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/ int var_x = 273;
int *ptr1; /* ptr1 adl pointer yang menunjuk ke objek bertipe integer */
/* (Boleh disebut pointer integer saja) */
int **ptr2; /* ptr2 adl pointer yang menunjuk ke pointer yang menunjuk */
/* ke objek bertipe integer (Boleh disebut : pointer menunjuk ke pointer integer saja) */
//ptr 1 di isi oleh alamat dari var x dan ptr 2 diisi oleh alamat dari ptr 1
ptr1 = &var_x; ptr2 = &ptr1;

/* Mengakses nilai var_x melalui ptr1 dan ptr2 */
printf("Nilai var_x = %d\n", *ptr1);
printf("Nilai var_x = %d\n", **ptr2);
return 0;
}
