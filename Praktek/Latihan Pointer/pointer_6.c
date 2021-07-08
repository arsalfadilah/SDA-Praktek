#include <stdio.h>
int main(){
    int arr[] = {10,11,12};
    int *pp;
    int *p = arr;
    pp = &p;
    int i;

    printf("Alamat dari arr : %p\n", &arr);
    printf("Alamat dari p   : %p\n", pp);
    printf("Alamat dari i   : %p\n", &i);
    printf("isi dari p pertama kali : %p\n\n", p);

    for(i=0; i< 4;i++){
        printf("%d\n", *p++);
        printf("isi dari p : %p\n\n", p);
    }

    return 0;
}
