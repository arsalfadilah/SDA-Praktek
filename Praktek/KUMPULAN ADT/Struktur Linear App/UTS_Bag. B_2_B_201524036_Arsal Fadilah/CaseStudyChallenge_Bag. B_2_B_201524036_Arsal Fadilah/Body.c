#include "List.h"
#include <stdio.h>
#include <string.h>

//Test Jika list kosong
bool ListEmpty(List  L){
    return (L.First == NULL);
}

//Membuat List
void CreateList(List *L){
    (*L).First = NULL;
}

//Mengalokasikan Memori
address Alokasi(Infotype X){
    address P;
    
    P=(address)malloc(sizeof(Node));
    
    if(P != NULL) { 
        /* Berhasil  */
        P->info = X;
        P->next= NULL;
    }

    return P;
}

//Membebaskan P
void Dealokasi(address *P){
    (*P)->next = NULL;
    free(*P);
}

//Menambah node terakhir
void InsVLast(List *L, Infotype X){
    address Last;
    address P=Alokasi(X);
    
    if(P!=NULL)
    {      
        if(ListEmpty(*L)) { /* Jika kosong, Insert elemen pertama */
	        //InsertFirst(&(*L),P);
            P->next = (*L).First;
            (*L).First = P;
        }
        else { /* tdk kosong */
	        Last = (*L).First;
            
            while(Last->next != NULL)  { /* menuju ke last */
	          Last = Last->next;
	        } /* Next(Last)==Nil */

	        Last->next = P;
      }

    }
}

void PrintInfo(List L){
    address P = L.First;

    if(P == NULL){
        printf("List Kosong !");
    } else {
        do{
            printf("Nama : %s\n", P->info.Nama);
            printf("Posisi (Kolom, Baris) : (%d, %d)\n", P->info.pos.x, P->info.pos.y);

            P = P->next;
        }while(P != NULL);
    }
}

void InputPos(Posisi *Pos){
    scanf("%d %d", &(*Pos).x, &(*Pos).y);
}

void InputInfo(Infotype *X){
    fflush(stdin);
    printf("Nama : ");
    scanf("%10[^\n]", (*X).Nama);
    printf("Posisi : ");
    InputPos(&(*X).pos);
}

void GetInfotypeByTask(List L, int pos, char task[], address *Now, Infotype *New){
    address P = L.First;
    int PosSelanjutnya;

    if(strcmp(task, "Belakang") == 0){
        
        PosSelanjutnya = (*Now)->info.pos.x + pos;

        while (P != NULL && P->info.pos.x != PosSelanjutnya)
        {
            /* code */ 
            P = P->next;
        }

        if(P->info.pos.x == PosSelanjutnya){
            //return P->info;
            *New = P->info;
            *Now = P;
        }
        
    }

    if(strcmp(task, "Depan") == 0){
        PosSelanjutnya = (*Now)->info.pos.x - pos;

        while (P != NULL && P->info.pos.x != PosSelanjutnya)
        {
            /* code */ 
            P = P->next;
        }

        if(P->info.pos.x == PosSelanjutnya){
            *New = P->info;
            *Now = P;
        }  
    }

    if(strcmp(task, "Kanan") == 0){
        PosSelanjutnya = (*Now)->info.pos.y + pos;
        //printf("Ini pos : %d", PosSelanjutnya);

        while (P != NULL && P->info.pos.y != PosSelanjutnya)
        {
            /* code */ 
            P = P->next;
        }

        if(P->info.pos.y == PosSelanjutnya){
            *New = P->info;
            *Now = P;
            //printf("Masuk Kanan");
        }  

        
    }

    if(strcmp(task, "Kiri") == 0){
        PosSelanjutnya = (*Now)->info.pos.y - pos;

        while (P != NULL && P->info.pos.y != PosSelanjutnya)
        {
            /* code */ 
            P = P->next;
        }

        if(P->info.pos.y == PosSelanjutnya){
            *New = P->info;
            *Now = P;
            //printf("Masuk Kiri");
        }  
    }
    
    
}