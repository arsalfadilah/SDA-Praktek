#include<stdio.h>

int main(){
    int no = 10;
    char strNo[5];
    char temp;


    //Formatting
    sprintf(strNo, "%d", no);
    if(no > 999){
//        strcpy(x.noPendaftar, strNo);
        printStack("%s\n", strNo);
    } else if(no > 99){
        for(int i = 3; i<0; i--){
            strNo[i] = strNo[i-1];
        }
        strNo[0]='0';

//        strcpy(x.noPendaftar, strNo);
        printStack("%s\n", strNo);
    } else if(no > 9){
        for(int i = 3; i<1; i--){
            strNo[i] = strNo[i-1];
        }
        strNo[0]='0';
        strNo[1]='0';

//        strcpy(x.noPendaftar, strNo);
        printStack("%s\n", strNo);
    } else {
        temp = strNo[0];
        strNo[0]='0';
        strNo[1]='0';
        strNo[2]='0';
        strNo[3]=temp;
//        strcpy(x.noPendaftar, strNo);
        printStack("%s\n", strNo);
    }

    return 0;
}
