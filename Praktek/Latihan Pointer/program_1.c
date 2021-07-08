#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
 char jenis;
 int jumlah;
 char** nomor;
 char nKamar[3];
}kamar;

int main(){
    kamar myRoom[4] = {};
    int urutan[4] = {};
    int i, j;

    for(i = 0; i < 4; i++){
        char kamar;
        int jml;
        scanf("%s %d", &kamar, &jml);

        myRoom[i].jenis = kamar;
        myRoom[i].jumlah = jml;
        myRoom[i].nomor = malloc(jml*4);

        for(j = 0; j < jml; j++){
            myRoom[i].nomor[j] = malloc(4);
            scanf("%s", myRoom[i].nomor[j]);
        }
    }

    for(i = 0; i < 4; i++){
        char* ptrkamar = malloc(4);
        char no_kamar = '\0';
        scanf("%s %s", ptrkamar, &no_kamar);
        for(j = 0; j < 4; j++){
            if(!strcmp(&myRoom[j].jenis, &no_kamar)){
                urutan[i] = j;

                strcpy(myRoom[j].nKamar, ptrkamar);
                break;
            }
        }
    }

    for(i = 0; i < 4; i++){
        printf("%s", myRoom[urutan[i]].nKamar);

        for(j = 0; j < myRoom[urutan[i]].jumlah;j++){
            printf(" %s", myRoom[urutan[i]].nomor[j]);
        }
        printf("\n");
    }

    return 0;
}
