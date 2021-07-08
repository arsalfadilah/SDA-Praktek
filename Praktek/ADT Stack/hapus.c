#include<stdio.h>

int main(){
    int as = 123;
    char asda[5];


    asda[0]=0;
    sprintf(asda, "%d", as);
    printf("%s", asda);

    return 0;
}
