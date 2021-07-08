#include <stdio.h>

int main(){
    int x = 6;
    int p = x;
    int q = p;
    p = 10;
    printf("x : %d p : %d, q : %d \n", x,p,q);
    printf("Alama x : %p\n", &x);
    printf("Alama p : %p\n", &p);
    printf("Alama q : %p\n", &q);

    int x1 = 6;
    int *ptrp = &x1;
    int **pa;
    pa = &ptrp;
    int q1 = *ptrp;
    //ubah nilai x
    *ptrp = 10;
    printf("x : %d p : %d, q : %d \n", x1, *ptrp, q1);
    printf("Isi nilai ptrp : %p\n", ptrp);
    printf("Alama xl : %p\n", &x1);
    printf("Alama pa : %p\n", pa);
    printf("Alama ql : %p\n", &q1);

    return 0;

}
