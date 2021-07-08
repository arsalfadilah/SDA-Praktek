/* Definisi elemen dan address */
#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

//Attribut data
typedef struct NodeQueue *addrNQ;
typedef struct
{
    // silahkan isi sendiri sesuai dengan simulasi di atas
    char Nama[10];
    int waktuDaftar;
    char jmlhKoper;
    int waktuTunggu;
    int estWaktuSelesai;
} infotype;
typedef struct NodeQueue
{
    infotype info; // info pelanggan
    addrNQ next;
} NodeQueue;
typedef struct
{
    addrNQ Front; // tag antrian depan
    addrNQ Rear;  // tag antrian belakang
} Queue;
//end atribut data

/** Modul - Modul **/
/***** Manajemen memori *****/
/* Mengirimkan address hasil alokasi sebuah elemen dengan info X.
* Jika alokasi berhasil, modul mengembalikan P; Info(P) = X,
Next(P) = NULL.
* P adalah pointer yang menunjuk ke node Queue sebagai hasil
alokasi.
* Jika alokasi gagal, modul mengembalikan NULL.
*/
addrNQ Alokasi(infotype X);

/* Melakukan dealokasi elemen P (pointer menunjuk ke alamat node
queue).
* I.S.: P terdefinisi.
* F.S.: P dikembalikan ke sistem.
*/
void Dealokasi(addrNQ *P);

/***** Manajemen Queue *****/
/* Membuat sebuah Queue kosong dengan Front(Q) = Nil dan Rear (Q) =
Nil
I.S. Belum terbentuk Queue
F.S. Sudah terbentuk Queue
*/
void CreateQueue(Queue *Q);

/* Mengetahui apakah Queue kosong atau tidak.
mengirimkan 1 jika Queue Kosong yaitu Front(Q) = Nil dan Rear
(Q) = Nil
Sebaliknya 0 (Queue tidak kosong)
*/
bool IsQueueEmpty(Queue Q);

/* Memasukkan info baru ke dalam Queue dengan aturan FIFO */
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */
/* F.S. info baru (data) menjadi Rear yang baru dengan node Rear
yang lama mengaitkan pointernya ke node yang baru */
void enQueue(Queue *Q, infotype data);

/* Proses: Mengambil info pada Front(Q) dan mengeluarkannya dari
Queue dengan aturan FIFO */
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */
/* F.S. info yang diambil = nilai elemen Front pd I.S. */
/* Front(Q) menunjuk ke next antrian atau diset menjadi NIll, Q
mungkin kosong */
void deQueue(Queue *Q, infotype *data);

/* Mengirimkan banyaknya elemen queue jika Q berisi atrian atau
mengirimkan 0 jika Q kosong
*/
int NBElmt(Queue Q);
//end modul utama

/* Modul Tambahan */
/**menghitung waktu estimasu selesai layanan  pada
 * setiap customer berdasarkan infromasi waktu tunggu sebelumnya dan waktu daftar **/
int HitungWaktuSelesai(infotype customer, int WaktuSelesaiSebelumnya);

/** menghitung waktu tunggu pada setiap customer
 * menggunakan parameter data waktu datang customer dan waktu
 * dan waktu selesai customer sebelumnya
 **/
int HitungWaktuTunggu(infotype customer, int WaktuSelesaiSebelumnya);

/** Print seluruh info dari Queue **/
void printInfotype(infotype info);

//print semua element yang ada di queue
void printElemQueue(Queue Q);

/** menampilkan estimasi waktu dari cs yg baru antri **/
void printInfotypeEstimasi(infotype info);

//masuk antrian untuk dihitung kalkulasi atau estimasi waktu mengantri/tunggu dan estimasi selesai mengantrinya
void MasukAntrian(Queue *Q, int *waktuSebelumnya);

//method penghitung proses estimasi
void MulaiMengestimasiWaktu(infotype *x, int *waktuSebelumnya);

//menghapus satu customer pertama yang telah mengantri
void HapusAntrian(Queue *Q, infotype *X);

void HoldnCls();

#endif // QUEUE_H
/** End Header File QUEUE.h **/
