#include<stdio.h>
int main(){
    int my_arr[] = {1,23,17,4,-5,100};
    int *ptr;
    int **pa;
    int i;
    ptr = &my_arr[0];
    pa = &ptr;

    printf("Alamat dari i : %p\n", &i);
    printf("Alamat dari ptr : %p\n\n", pa);

    for(i = 0; i< 6;i++){
        printf("my_arr[%d] = %d \n", i, my_arr[i]);
        printf("Alamat my_arr[%d] = %p\n", i, &my_arr[i]);
        printf("Isi dari ptr : %p\n", ptr);
        printf("Nilai yang ditunjuk ptr : %d\n", *ptr);
        printf("ptr + %d = %d\n\n", i, *(ptr + i)); // coba ubah jadi *ptr++ dan *(++ptr)
    }

    return 0;
}
