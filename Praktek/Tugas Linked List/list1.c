/* File        : list1.h */
/* Deskripsi   : ADT list berkait dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */

#include "list1.h"
#include <stdlib.h>
//#ifndef list1_H
//#define list1_H
//#include <stdbool.h>
//#include <stdio.h>
//#define Nil NULL
//#define Info(P) (P)->info
//#define Next(P) (P)->next
//#define First(L) (L).First

//typedef int infotype;
//typedef struct tElmtList *address;
//typedef struct tElmtList {
//    infotype info;
//    address  next;
//    } ElmtList;

/* Definisi list : */
/* List kosong ===> First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P) dan Next(P);  */
/* Elemen terakhir list ===> Jika addressnya Last maka Next(Last) = Nil */
//typedef struct {
//     address First;
//} List;

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
bool ListEmpty (List L){
/* Mengirim true jika List Kosong */
    if (First(L) == Nil){
        return true;
    } else {
        return false;
    }
}


/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L){
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
    L->First = (struct tElmtList *) malloc(sizeof(struct tElmtList));

    if(L->First != Nil){
        L->First->next = Nil;
    } else {
        printf("Gagal Membua List");
    }
}

/**** Manajemen Memory ****/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    address P = (struct tElmtList *) malloc(sizeof(struct tElmtList));

    if(P != Nil){
        Info(P) = X;
        Next(P) = Nil;
        return P;
    } else {
        return Nil;
    }
}

void DeAlokasi (address P){
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
    free(P);
}


/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
    while(L.First->next != Nil){
        if(L.First->info == X){
            return L.First;
        } else {
            L.First = L.First->next;
        }
    }
    return Nil;
}

bool FSearch (List L, address P){
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
    while(L.First->next != Nil){
        if(L.First == P){
            return true;
        } else {
            L.First = L.First->next;
        }
    }
    return false;
}

address SearchPrec (List L, infotype X){
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
    int i=0;
    address P;

    while(L.First->next != Nil  && L.First->info != X){
        P = L.First;
        L.First = L.First->next;
        i++;
    }

    if(L.First->next == Nil || i==0)
        return Nil;
    else
        return P;

}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (List * L, infotype X){
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    List newList = *L;
    CreateList(&newList);

    if(!ListEmpty(newList)){
        if(ListEmpty(*L)){
            newList.First->info = X;
            newList.First->next = Nil;
            L->First = newList.First;
        } else {
            newList.First->info = X;
            newList.First->next = L->First;
            L->First = newList.First;
        }
    } else {
        printf("Gagal Membuat List");
    }
}

void InsVLast (List * L, infotype X){
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
    List newList;
    List temp = *L;
    CreateList(&newList);

    //printf("%d %d", temp.First, L->First);

    if(!ListEmpty(newList)){
        newList.First->info = X;
        newList.First->next = Nil;

        if(ListEmpty(*L)){
            L->First = newList.First;
        } else {
            while (temp.First->next != Nil){
                temp.First = temp.First->next;
            }
            temp.First->next = newList.First;
        }
    } else {
        printf("Gagal Membua List");
    }
}

/**** Penghapusan Elemen ****/
void DelVFirst (List * L, infotype * X){
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */
    List temp = *L;
    List prev;

    if(!ListEmpty(temp)){
        *X = temp.First->info;
        L->First = temp.First->next;
        DeAlokasi(temp.First);
    } else {
        printf("Sorry Your List Is Empty");
    }

}

void DelVLast (List * L, infotype * X){
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
    List temp = *L;
    List prev;

    if(!ListEmpty(temp)){
        if(temp.First->next != Nil){
           while(temp.First->next != Nil){
                prev = temp;
                temp.First = temp.First->next;
            }
            *X = temp.First->info;
            prev.First->next = Nil;
            DeAlokasi(temp.First);
        } else {
            *X = temp.First->info;
            L->First = Nil;
            DeAlokasi(L->First);
        }
    } else {
        printf("Sorry Your List Is Empty");
    }

}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P){
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
    //List newList;
    //CreateList(&newList);

    if(P != Nil){
        if(ListEmpty(*L)){
            P->next = Nil;
            L->First = P;
        } else {
            P->next = L->First;
            L->First = P;
        }
    } else {
        printf("Gagal Membuat List");
    }
}

void InsertAfter (List * L, address P, address Prec){
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
    List temp = *L;

    if(Prec != Nil){
        while(temp.First->next != Nil && temp.First->info != Prec->info){
            temp.First = temp.First->next;
        }

        if(temp.First->next != Nil){
            P->next = temp.First->next;
            temp.First->next = P;
        } else {
            P->next = Nil;
            temp.First->next = P;
        }
    } else {
        printf("Prec Nil");
    }

}

void InsertLast (List * L, address P){
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
    List temp = *L;

    if(P != Nil){
        while(temp.First->next != Nil){
            temp.First = temp.First->next;
        }

        temp.First->next = P;
    } else {
        printf("something wrong");
    }


}

/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, address * P){
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */
    List prev = *L;

    if(!ListEmpty(prev)){
        *P = L->First;
        L->First = prev.First->next;
        DeAlokasi(prev.First);
    } else {
        printf("Sorry Your List Is Empty");
    }

}

void DelP (List * L, infotype X){
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap*/
/* List mungkin menjadi kosong karena penghapusan */
    address temp = First(*L);
    address prev = temp;
    int i = 0;

    if(!ListEmpty(*L)){
        while(temp.First != Nil && temp.First->info != X){
            prev = temp;
            temp.First = temp.First->next;
            i++;
        }

        if(i==0){
            prev.First = Nil;
        } else if(temp.First == Nil){
            prev.First->next = Nil;
        } else {
            prev.First->next = temp.First->next;
        }

        DeAlokasi(temp.First);
    } else {
        printf("Sorry Your List Is Empty");
    }

}

void DelLast (List * L, address * P){
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
    List temp = *L;
    List prev;

    if(!ListEmpty(temp)){
        if(temp.First->next != Nil){
           while(temp.First->next != Nil){
                prev = temp;
                temp.First = temp.First->next;
            }
            *P = temp.First;
            prev.First->next = Nil;
            DeAlokasi(temp.First);
        } else {
            *P = temp.First;
            L->First = Nil;
            DeAlokasi(L->First);
        }
    } else {
        printf("Sorry Your List Is Empty");
    }
}

void DelAfter (List * L, address * Pdel, address Prec){
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */
    List temp = *L;
    address tempAdrs = Prec;

    if(temp.First != Nil){
        while(temp.First->next != Nil && temp.First->info != Prec->info){
            temp.First = temp.First->next;
        }

        if(temp.First->next != Nil){
            *Pdel = temp.First->next;
            if(Prec->next != Nil){
                temp.First->next = Prec->next->next;
                //printf("info prec : %d %d", Prec->info, Prec->next);
            }
            else{
                temp.First->next = Nil;
            }
        } else {
            printf("List hanya satu, tidak bisa delete after");
        }
    } else {
        printf("List Nil");
    }
}

/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L){
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
    int i = 0;

    while (L.First != Nil){
        printf(" %d ", L.First->info);
        L.First = L.First->next;
        i++;
    }

    if(i==0)
        printf("List anda kosong");

}

int NbElmt (List L){
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
    int i = 0;

    while(L.First != Nil){
        L.First = L.First->next;
        i++;
    }

    return i;

}

infotype Max (List L){
/* Mengirimkan nilai Info(P) yang maksimum */
    infotype max = L.First->info;

    while(L.First->next != Nil){
        L.First = L.First->next;
        if(L.First->info > max){
            max = L.First->info;
        }
    }

    return max;

}


address AdrMax (List L){
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    address max = L.First;
    max->info = L.First->info;

    while(L.First->next != Nil){
        L.First = L.First->next;
        if(L.First->info > max->info){
            max = L.First;
        }
    }

    return max;
}

infotype Min (List L){
/* Mengirimkan nilai Info(P) yang minimum */
    infotype min = L.First->info;

    while(L.First->next != Nil){
        L.First = L.First->next;
        if(L.First->info < min){
            min = L.First->info;
        }
    }

    return min;
}


address AdrMin (List L){
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    address min = L.First;
    min->info = L.First->info;

    while(L.First->next != Nil){
        L.First = L.First->next;
        if(L.First->info < min->info){
            min = L.First;
        }
    }

    return min;
}

//tipe di ubah karena rat-rata kemungkinan tidak bulat
float Average (List L){
/* Mengirimkan nilai rata-rata Info(P) */
    infotype average = 0;
    infotype i = 1;

    while(L.First->next != Nil){
        average += L.First->info;
        L.First = L.First->next;
        i++;
    }

    average += L.First->info;

    return (average/i);
}


/***************************************/
/*******  PROSES TERHADAP LIST  ********/
/***************************************/

void DelAll (List * L){
/* Delete semua elemen list dan alamat elemen di dealokasi */
    List temp = *L;
    List next;

    while(temp.First != Nil){
        next.First = temp.First->next;
        DeAlokasi(temp.First);
        temp.First = next.First;
    }

    L->First = Nil;
}

void InversList (List * L){
/* IS : L sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst */
/*	Membalik elemen list, tanpa melakukan alokasi / dealokasi */
    List temp = *L;
    address prev = Nil;
    address next = Nil;

    while(temp.First!= Nil){
        next = temp.First->next;
        temp.First->next = prev;
        prev = temp.First;
        temp.First = next;
    }

    L->First = prev;

}

List FInversList (List L){
/* Mengirimkan list baru, hasil invers dari L */
    List baru, temp = L;
    address P = First(L);
    CreateList(&baru);

    if(!ListEmpty(baru)){
        baru = FCopyList(temp);
        InversList(&baru);
    }

    return baru;
}


void CopyList (List L1, List * L2){
/* IS : L1 sembarang */
/* FS : L2 = l1 */
/* L1 dan L2 "menunjuk" ke list yang sama, Tidak ada alokasi / dealokasi */
    *L2 = L1;

}

List FCopyList (List L){
/* Mengirimkan List yang merupakan salinan L */
    List baru;
    baru.First = Nil;
    address P;
    //CreateList(&baru);

        while(L.First != Nil){
            P = Alokasi(L.First->info);
            //printf("Isi dari info copy : %d", P->info);
            if(P != Nil){
                InsVLast(&baru, P->info);
            } else {
                printf("gagal alokasi");
            }
            L.First = L.First->next;
        }

    return baru;

}

void CpAlokList (List Lin, List * Lout){
/* IS : Lin Sembarang */
/* FS : Jika semua alokasi berhasi, maka Lout berisi hasil copy Lin */
/* 	Jika ada alokasi yang gagal, maka Lout = Nil dan semua elemen yang */
/*	terlanjur di alokasi, maka didealokasikan */
/* 	Dengan melakukan alokasi elemen */
/*	Lout adalah  list kosong jika ada alokasi elemen yang gagal */
	address P, Pt;
    bool gagal;

    CreateList(Lout);
    gagal = false;
    P = First(Lin);
    while ((P != Nil)&&(!gagal)) {
    	Pt = Alokasi(Info(P));
    	if (Pt != Nil) {
        	InsertLast(Lout,Pt);
        	P = Next(P);
      	} else {
        	gagal = true;
        	DelAll(Lout);
      	}
    }

}

void Konkat (List L1, List L2, List * L3){
/* IS : L1 dan L2 sembarang */
/* FS : L1 dan L2 tetap, L3 adalah hasil konkatenansi L1 dan L2 */
/*	Jika semua alokasi berhasil , maka L3 adalah hasil konkatenasi */
/*	Jika ada alokasi gagal, semua elemen yang sudah di alokasi harus */
/* 	di dealokasi dan L3 = Nil */
/* Konkatenasi dua buah list : L1 dan L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang "baru". Jika ada alokasi yang */
/*	  GAGAL, maka L3 harus bernilai nil dan semua elemen yang pernah di */
/*	  alokasi didealokasi */
    address P, Pt;
    bool gagal;

    CreateList(L3);
    gagal = false;
    P = First(L1);
    while ((P != Nil)&&(!gagal)) {
		Pt = Alokasi(Info(P));
		if (Pt != Nil) {
			InsertLast(L3,Pt);
			P = Next(P);
		} else {
			gagal = true;
			DelAll(L3);
		}
    }
    if (!gagal) {
		P = First(L2);
		while ((P != Nil)&&(!gagal)) {
			Pt = Alokasi(Info(P));
			if (Pt != Nil) {
				InsertLast(L3,Pt);
				P = Next(P);
			} else {
				gagal = true;
				DelAll(L3);
			}
		}
    }
}

void Konkat1 (List * L1, List * L2, List * L3){
/* IS : L1 dan L2 sembarang */
/* FS : L1 dan L2 kosong, L3 adalah hasil konkatenansi L1 dan L2 */
/*	Konkatenasi dua buah List L1 dan L2; menghasilkan L3 yang baru */
/* 	(dengan elemen List L1 dan L2) */
/*	dan L1 serta L2 menjadi list kosong */
/* 	Tidak ada alokasi / dealokasi pada procedure ini */
	address P;

	P = First(*L1);
    CreateList(L3);
    First(*L3) = First(*L1);
    if (P != Nil) {
		while (Next(P) != Nil) {
        	P = Next(P);
      	}
    }
    Next(P) = First(*L2);
    CreateList(L1);
    CreateList(L2);
}

void PecahList (List * L1, List * L2, List L){
/* IS : L mungkin kosong */
/* FS : berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah : untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil , maka separuh adalah NbElmt (L) div 2 */
    address P, Pt;
    bool gagal;
    int i, N;

    CreateList(L1);
    CreateList(L2);
    gagal = false;
    i = 1;
    N = NbElmt(L)/2;
    P = First(L);
    while ((P != Nil) && (!gagal)) {
		Pt = Alokasi(Info(P));
		if (i <= N) {
	        if (Pt != Nil) {
				InsertLast(L1,Pt);
				P = Next(P);
				i++;
	        } else {
				gagal = true;
				DelAll(L1);
	        }
    	} else {
	        if (Pt != Nil) {
				InsertLast(L2,Pt);
				P = Next(P);
				i++;
	        } else {
	          gagal = true;
	          DelAll(L2);
	        }
      	}
    }
}
