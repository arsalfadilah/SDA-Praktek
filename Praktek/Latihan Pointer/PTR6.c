#include <stdio.h>
int main() {
/* Kamus Data (deklarasi, inisialisasi nilai variabel)*/
    static int tgl_lahir[] = {18, 6, 1989};
    int *ptgl;

    ptgl = tgl_lahir;
    for(int i=0; i<3 ; i++){
        printf("Nilai yang ditunjuk oleh ptgl = %d\n", *(ptgl+i));
        printf("Nilai dari tgl_lahir[0] = %d\n", tgl_lahir[i]);
    }

    return 0;
}
