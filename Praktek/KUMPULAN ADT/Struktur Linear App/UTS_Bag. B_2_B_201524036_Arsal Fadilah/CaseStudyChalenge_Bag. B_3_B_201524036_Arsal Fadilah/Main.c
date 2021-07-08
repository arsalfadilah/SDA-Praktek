#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "QueueSpecial.h"

void InputData(infotype *infoData){
    infotype info;
    fflush(stdin);
    printf("Nama : ");
    scanf("%30[^\n]s", info.Nama);
    printf("Waktu Kedatangan : ");
    scanf("%d", &info.waktuDatang);
    printf("Jumlah Lembar : ");
    scanf("%d", &info.jumlahLEbar);

    info.waktuDilayani = 0;
    info.waktuSelesaiDilayani = 0;

    *infoData = info;
}

void SiapaDuluan(QueueSpecial antrian, int waktuSelesai, address *hasil){
    address node = antrian.First;
    address minNode, maxNode, tempHasil;
    int i =0;
    tempHasil = Nil;
    
    //printf("Seblum di proses antrian adalah :\n");
    //PrintInfo(antrian);
    //Algoritma
    //1. Dapatkan Min dan Max addresnya
    if(node != Nil){
        // printf("Test TEst Test");
        // printf("node info waktu datang %d dan waktu selesai dari param %d", node->info.waktuDatang, waktuSelesai);
        if(node->info.waktuDatang <= waktuSelesai){
            minNode = node;
            maxNode = node;     
        }   

        //Update
        node = node->next;
        //PrintInfo(antrian);
        while (node != Nil)
        {
            //cari range max dari address yang mempunyai waktu datang lebih kecil dari waktu selesai
            if(node->info.waktuDatang <= waktuSelesai){
                maxNode = node;
                i++;
                //printf("ini seharusnya tidak pernah terjadi");
            }

            node = node->next;
        }
        
        // printf("Max Node data Siapa ? : %d", maxNode);
        // printf("Min Node data Siapa ? : %d", minNode);
        // /printf("harusnya ada dua kali");
        //2. Jika Min dam Max nya sama itu yang return
        //Tetapi jika tidak maka harus dicari juga addres yang mempunyai lembaran terkecil
        if(i==0){
            tempHasil= minNode;
            //printf("2 kali ini");
        }else {
            while (minNode != maxNode)
            {
                /* code */
                //printf("Test");
                //printf("0 kali ini");
                if(minNode->info.jumlahLEbar < maxNode->info.jumlahLEbar){
                    tempHasil = minNode;
                }else{
                    tempHasil = maxNode;
                }
                minNode = minNode->next;
            }
            
        }
           *hasil = tempHasil;
    } else {
        printf("Node NILLL");
    }
    
}

void Process(QueueSpecial *antrian, QueueSpecial *hasil){
    //QueueSpecial Q3;
    //CreateQueueSpecial(&temphasil);
    
    int i = 1;
    int tempWaktuSelesai=0;
    infotype X, temp;
    address tempAddr, tempAddr2;
    address ptr = First(*antrian);

    if(ptr != Nil){
        X = ptr->info;
        //Rumus Waktu Dilayani
        X.waktuDilayani = X.waktuDatang + 1;
        //Rumus Waktu Selesai Dilayani
        X.waktuSelesaiDilayani = X.waktuDilayani + X.jumlahLEbar - 1;
        tempWaktuSelesai = X.waktuSelesaiDilayani;
        //insert cs pertama ke hasil
        InsVLast(&(*hasil), X);
        //tempWaktuSelesai = X.waktuSelesaiDilayani;
        //Delete cs pertama di antrian
        DelVFirst(&(*antrian), &X);
        
    } else{
        printf("PTR NILLL");
    }
    //printf("Test TEst Test");
    //PrintInfo(*antrian);
    
    while ( (NbElmt(*antrian)) != 0)
    {
        /* code */
        //Siapa dulu :
        //tempWaktuSelesai = tempAddr->info.waktuSelesaiDilayani;
        
        SiapaDuluan((*antrian), tempWaktuSelesai, &tempAddr);
        system("pause");
        // printf("N elem = %d", NbElmt(*antrian));
        //printf("2 kali ini");
        //Masukan Rumusnya :
        if(tempAddr != Nil){
            
            tempAddr->info.waktuDilayani = tempWaktuSelesai;
            tempAddr->info.waktuSelesaiDilayani = tempAddr->info.waktuDilayani + tempAddr->info.jumlahLEbar - 1;
            tempWaktuSelesai = tempAddr->info.waktuSelesaiDilayani;
            //Adding :
            X = tempAddr->info;
            printf("\nInformasi yg diberikan oleh tempAddr adalah : \n");
            printf("1. Nama     : %s\n", X.Nama);
            printf("2. Waktu Datang : %d\n", X.waktuDatang);
            printf("3. Waktu dilayani : %d\n", X.waktuDilayani);
            printf("3. Waktu Selesai : %d\n", X.waktuSelesaiDilayani);
            InsVLast(&(*hasil), X);
            //Deleting
            DelP(&(*antrian), tempAddr);
            //PrintInfo(*antrian);
            // PrintInfo(*hasil);
        } else {
            printf("ops somthing went wrong");
        }

        
    }

    //return hasil;
}

// QueueSpecial tempAntrian(QueueSpecial antrian, int waktuSelesai){
//     infotype X;
//     QueueSpecial hasil;
//     CreateQueueSpecial(&hasil);
//     address ptr = antrian.First;

//     while (ptr != Nil)
//     {
//         if(ptr->info.waktuDatang <= waktuSelesai){
//             InsVLast(&hasil, X);
//         }

//         ptr = ptr->next;
//     }
    
//     return hasil;
// }

// void SortQueueByLembar(QueueSpecial *L){
//     int swapped, i;
//     address ptr1;
//     address lptr = NULL;
//     int no_1, no_2;

//     /* Checking for empty QueueSpecial */
//     if (L->First == NULL)
//         return;

//     do
//     {
//         swapped = 0;
//         ptr1 = L->First;

//         while (ptr1->next != lptr)
//         {
//             //Sort By Info Jumlah lembar dari TempQueue
//             if(ptr1->info.jumlahLEbar > ptr1->next->info.jumlahLEbar){
//                 swapAddr(ptr1, ptr1->next);
//                 swapped = 1;
//             }

//             ptr1 = ptr1->next;
//         }
//         lptr = ptr1;
//     }
//     while (swapped);
// }

int main(){

    //Algoritma:
    //1. Input Data Customer Fotocopy
    //2. Pilih satu customer sebagai pivot
    //Dimana customer tersebut diambil dari waktu kedatangan customer yang paling awal
    //3. Cek antrian queue dengan data dari waktu selesai pelayanan customer sebelumnya
    //4. Proses customer dengan ketentuan customer yang memiliki jumlah lembar lebih kecil di dahulukan
    //5. lakukan proses 3 sampai 4 hingga customer terakhir dilayani

    //cek dulu :
    QueueSpecial antrian, hasil;
    infotype info;
    int N_Customer;

    printf("Berapa Banyak Customer : ");
    scanf("%d", &N_Customer);

    //Clear Screen
    system("cls");

    //make sure bahwa antrian tak nol:
    if(N_Customer != 0){
        //Buat Queue kosong
        CreateQueueSpecial(&antrian);
        CreateQueueSpecial(&hasil);
        //Add sejumlah N Customer
        for(int i=0; i < N_Customer; i++){
            InputData(&info);
            InsVLast(&antrian, info);
        }

        //Cari salah satu customer yang pertama kali datang
        //Dengan cara sort list Queueu menurut kedatangannya terlebih dahulu
        sortQueueSpecialQueue(&antrian);
        //PrintInfo(antrian);
        //Lakukan proses pelayanan customer
        //hasil = Process(antrian);
        Process(&antrian, &hasil);

        if(hasil.First == Nil){
            printf("Yah Gagal");
        } else {
            //printInfo Semuanya:
            printf("\n=======================");
            printf("\nResult of the day : \n");
            PrintInfo(hasil);
        }

    }

    return 0;
}
