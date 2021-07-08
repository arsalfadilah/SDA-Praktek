#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

addrNQ Alokasi(infotype X)
{
    //memesan memeori sebanyak node queue
    addrNQ P = (addrNQ)malloc(sizeof(NodeQueue));
    //apabila alokasi berhasil maka
    //kembalian nilainya adalah alamat
    //yang telah  di alokasi tsb
    if (P != NULL)
    {
        P->info = X;
        P->next = NULL;
        return P;
    }
    //jika tidak maka kembalian adalah null
    else
    {
        return NULL;
    }
}

/* Melakukan dealokasi elemen P (pointer menunjuk ke alamat node
queue).
* I.S.: P terdefinisi.
* F.S.: P dikembalikan ke sistem.
*/
void Dealokasi(addrNQ *P)
{
    free(*P);
}

/***** Manajemen Queue *****/
/* Membuat sebuah Queue kosong dengan Front(Q) = Nil dan Rear (Q) =
Nil
I.S. Belum terbentuk Queue
F.S. Sudah terbentuk Queue
*/
void CreateQueue(Queue *Q)
{
    (*Q).Front = NULL;
    (*Q).Rear = NULL;
}

/* Mengetahui apakah Queue kosong atau tidak.
mengirimkan 1 jika Queue Kosong yaitu Front(Q) = Nil dan Rear
(Q) = Nil
Sebaliknya 0 (Queue tidak kosong)
*/
bool IsQueueEmpty(Queue Q)
{
    if (Q.Front == NULL && Q.Rear == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Memasukkan info baru ke dalam Queue dengan aturan FIFO */
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */
/* F.S. info baru (data) menjadi Rear yang baru dengan node Rear
yang lama mengaitkan pointernya ke node yang baru */
void enQueue(Queue *Q, infotype data)
{
    //alokasi terlebih dahulu untuk infotype data
    addrNQ P = Alokasi(data);
    if (P != NULL)
    {
        //jika Q kosong maka insert pertama
        if (IsQueueEmpty(*Q))
        {
            P->next = (*Q).Front;
            (*Q).Front = P;
            (*Q).Rear = P;
        }
        //jika tidak insert di akhir
        else
        {
            (*Q).Rear->next = P;
            (*Q).Rear = P;
        }
    }
}

/* Proses: Mengambil info pada Front(Q) dan mengeluarkannya dari
Queue dengan aturan FIFO */
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */
/* F.S. info yang diambil = nilai elemen Front pd I.S. */
/* Front(Q) menunjuk ke next antrian atau diset menjadi NIll, Q
mungkin kosong */
void deQueue(Queue *Q, infotype *data)
{
    addrNQ P;
    if (!IsQueueEmpty(*Q))
    {
        P = (*Q).Front;
        *data = P->info;
        (*Q).Front = (*Q).Front->next;
        P->next = NULL;
        Dealokasi(&P);
    }
}

/* Mengirimkan banyaknya elemen queue jika Q berisi atrian atau
mengirimkan 0 jika Q kosong
*/
int NBElmt(Queue Q)
{
    int count = 0;
    addrNQ P = Q.Front;

    while (P != NULL)
    {
        /* code */
        count++;
        P = P->next;
    }
    return count;
}
//End Queue modul

/* Modul Tambahan */
/**menghitung waktu estimasu selesai layanan grooming pada
 * setiap customer berdasarkan infromasi waktu tunggu, waktu grooming dan waktu daftar **/
int HitungWaktuSelesai(infotype customer, int WaktuSelesaiSebelumnya)
{
    //Jika waktu selesai seblumnya lebih kecil dari seblumnya
    if (customer.waktuDaftar < WaktuSelesaiSebelumnya)
    {
        return WaktuSelesaiSebelumnya + customer.waktuGrooming;
    }
    else
    {
        return customer.waktuDaftar + customer.waktuGrooming;
    }
}

/** menghitung waktu tunggu grooming pada setiap customer
 * menggunakan parameter data waktu datang customer dan waktu
 * dan waktu selesai customer sebelumnya
 **/
int HitungWaktuTunggu(infotype customer, int WaktuSelesaiSebelumnya)
{
    if (customer.waktuDaftar < WaktuSelesaiSebelumnya)
    {
        return WaktuSelesaiSebelumnya - customer.waktuDaftar;
    }
    else
    {
        return 0;
    }
}

/** mwnghitung waktu estimasi grooming berdasarkan ukuran kucing **/
int HitungWaktuGrooming(char ukuran)
{
    switch (ukuran)
    {
    case 'K':
        /* code */
        return 30;
        break;
    case 'S':
        return 45;
        break;
    case 'B':
        return 60;
        break;
    default:
        return 0;
        break;
    }
}

void printInfotype(infotype info)
{
    /* code */
    //seluruh info di print
    printf("===============================\n");
    printf("Nama              : %s\n", info.Nama);
    printf("Waktu Daftar      : %d\n", info.waktuDaftar);
    printf("Ukuran            : %c\n", info.ukuran);
    printf("Waktu Grooming    : %d\n", info.waktuGrooming);
    printf("Waktu Tunggu      : %d\n", info.waktuTunggu);
    printf("Est Waktu Selesai : %d\n", info.estWaktuSelesai);
    printf("===============================\n");
    //end
}

void MasukAntrian(Queue *Q)
{
    infotype x;
    printf("================\n");
    //jangan lebih dari 10 karakter dan jangan ada spasi
    fflush(stdin);
    printf("Nama         : ");
    scanf("%s", x.Nama);
    printf("Waktu Daftar : ");
    scanf("%d", &x.waktuDaftar);
    fflush(stdin);
    printf("Ukuran       : ");
    scanf("%c", &x.ukuran);
    printf("================\n");
    enQueue(&(*Q), x);
}

void MulaiGrooming(Queue *Q, infotype *data, int waktuSebelumnya)
{
    deQueue(&(*Q), &(*data));
    (*data).waktuGrooming = HitungWaktuGrooming((*data).ukuran);
    (*data).waktuTunggu = HitungWaktuTunggu((*data), waktuSebelumnya);
    (*data).estWaktuSelesai = HitungWaktuSelesai((*data), waktuSebelumnya);
}

void HoldnCls()
{
    system("pause");
    system("cls");
}