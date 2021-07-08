#include <stdio.h>

int main(){
    int y, x = 87;
    int *px;
    int **ptx;

    px = &x;
    ptx = &px;
    y = *px;

    printf("Alamat x  = %p\n", &x);
    printf("Alamat y  = %p\n", &y);
    printf("Alamat px = %p\n", ptx);
    printf("Isi x   = %d\n", x);
    printf("Isi y   = %d\n", y);
    printf("Isi px  = %p\n", px);
    printf("Isi ptx = %p\n", ptx);

    printf("Nilai yang ditunjuk oleh px  = %d\n", *px);
    printf("Nilai yang ditunjuk oleh ptx = %d\n", **ptx);


    return 0;

}
