#include <stdio.h>
#include <stdlib.h>

struct NODE {
 int number;
 struct NODE *next;
 struct NODE *prev;
};

void append_node(struct NODE *tList, int num);
int  search_value(struct NODE *tList, int num);
void display_list(struct NODE *tList, struct NODE *Kiri, struct NODE *Kanan);
void setPtrKiri(struct NODE **Kiri, struct NODE *tList, int pos);
void setPtrKanan(struct NODE **Kanan, struct NODE *tList, int pos);
void addInKiri(struct NODE *tList, int num);
void penyambung(struct NODE **tList);

int main(void) {
    int num = 0;
    int input = 5;
    int retval = 0;
    struct NODE *tList;
    struct NODE *Kiri, *Kanan;

    //Inisialisasi
    tList = (struct NODE *)malloc(sizeof(struct NODE));
    tList->prev = NULL;
    tList->number = 7;
    tList->next = NULL;

    append_node(tList, 2);
    append_node(tList, 10);
    append_node(tList, 3);
    append_node(tList, 5);
    addInKiri(tList, 1);

//    Kiri = tList;
    setPtrKiri(&Kiri, tList, 1);
    setPtrKanan(&Kanan, tList, 1);

while(input != 0) {
      printf("\n===== Pilih Menu =====\n");
      printf("0: Keluar\n");
      printf("1: Insert\n");
      printf("2: Search\n");
      printf("3: Tampilkan\n");
      printf("\nPilihan: ");scanf("%d", &input);

    if(input==0){
        printf("...Terimakasih...\n");
    }
    else if(input==1){
        printf("Anda Memilih: 'Insert'\n");
        printf("Masukkan Nilai Yang Akan di Insert: ");
        scanf("%d", &num);
        append_node(tList, num);
    }
    else if(input==2){
        printf("Anda Memilih: 'Search'\n");
        printf("Masukkan Nilai Yang Akan di Cari (Search): ");
        scanf("%d", &num);
        if((retval = search_value(tList, num)) == -1)
            printf("Value `%d' not found\n", num);
        else
            printf("Value `%d' located at position `%d'\n", num, retval);
    }
    else if(input==3){
        printf("Anda Memilih: 'Tampilkan'\n");
        display_list(tList, Kiri, Kanan);
    }
}

    free(tList);
    return(0);
}

void append_node(struct NODE *tList, int num) {
    struct NODE *temp;
    temp = tList;

    while(tList->next != temp->prev)
        tList = tList->next;

        tList->next = (struct NODE *)malloc(sizeof(struct NODE));
        tList->next->prev = tList->next;
        tList->next->number = num;
        tList->next->next = temp->prev;
}

int search_value(struct NODE *tList, int num) {
    int retval = -1;
    int i = 1;
    while(tList->next != NULL) {
        if(tList->next->number == num)
            return i;
        else
            i++;

        tList = tList->next;
    }

    return retval;
}

void display_list(struct NODE *tList, struct NODE *Kiri, struct NODE *Kanan) {
    struct NODE *temp;
    temp = tList;
    while(tList->next != temp->prev) {
        printf("%u %d %u\n", tList->prev, tList->number, tList->next);
        tList = tList->next;
    }

    printf("%u %d %u\n", tList->prev, tList->number, tList->next);

    printf("\nINFO\n");
    printf("Ptr Kiri ada di : \n");
    printf("%u %d %u\n", Kiri->prev, Kiri->number, Kiri->next);
    printf("Ptr Kanan ada di : \n");
    printf("%u %d %u", Kanan->prev, Kanan->number, Kanan->next);
}

void setPtrKiri(struct NODE **Kiri, struct NODE *tList, int pos){

    for(int i=1; i<pos; i++){
        tList = tList->next;
    }

    *Kiri = tList;

}

void setPtrKanan(struct NODE **Kanan, struct NODE *tList, int pos){

    while(tList->next != NULL)
        tList = tList->next;

    *Kanan = tList;

}

void addInKiri(struct NODE *tList, int num){
    struct NODE *temp;
    temp = tList;

    while(tList->prev != temp->next)
        temp = temp->next;

        tList->prev = NULL;
        tList->prev = (struct NODE *)malloc(sizeof(struct NODE));
        tList->prev->next = tList->prev;
        tList->prev->number = num;
        tList->prev->prev = temp->next;

}
