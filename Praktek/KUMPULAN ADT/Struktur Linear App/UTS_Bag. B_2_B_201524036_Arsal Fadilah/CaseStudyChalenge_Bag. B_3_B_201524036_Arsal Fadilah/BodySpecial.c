#include <stdio.h>
#include "QueueSpecial.h"
#include "boolean.h"

/****** Function definition ******/
boolean QueueSpecialEmpty(QueueSpecial  L)
{  /*  Mengirim true jika QueueSpecial kosong  */

   	return(First(L)==Nil);
}

/* Pembuatan  QueueSpecial Kosong  */
void CreateQueueSpecial(QueueSpecial *L)
{  /* I.S  :  Sembarang    		*/
   /* F.S  :  Terbentuk  QueueSpecial kosong  	*/
   First(*L)=Nil;
}

/* ********  MANAJEMEN MEMORY  ********* */
address Alokasi(infotype  X)
{/* Mengirimkan  address  hasil alokasi    sebuah elemen */
 /* Jika alokasi  berhasil, maka  address tidak nil, dan misalnya  */
 /* menghasilkan   P,  maka info(P)=X,  Next(P)=Nil;               */
 /* Jika alokasi  gagal,  mengirimkan  Nil 			   */
   address P;
   P=(address)malloc(sizeof(ElmtQueueSpecial));
   if(P!=Nil) { /* Berhasil  */
         Info(P)=X;
	 Next(P)=Nil;
   }
   return P;
}

void Dealokasi(address *P)
{ /* I.S  : P terdefinisi      				*/
  /* F.S  : P dikembalikan ke  sistem 			*/
  /*   	    Melakukan dealokasi, pengembalian address P */
    Next(*P)=Nil;
    free(*P);
}

boolean ListEmpty(QueueSpecial  L)
{  /*  Mengirim true jika List kosong  */

   	return(First(L)==Nil);
}

/*   ** PENCARIAN SEBUAH ELEMEN QueueSpecial **   */
//address Search1(QueueSpecial L, infotype  X)
//{  /* Mencari apakah  ada elemen QueueSpecial dengan info(P)=X   */
//   /* Jika ada, mengirimkan  address dgn info(P)=X       */
//   /* Jika  tidak ada, mengirimkan Nil 			 */
//   /* Skema dengan boolean. Berlaku untuk QueueSpecial kosong  	 */
//   address  P=First(L);
//   boolean found=false;
//
//   while((P!=Nil)&&(!found))  {
//	   if(Info(P)==X) {
//		{  found=true;
//		   }
//	   }
//           else {
//	         P=Next(P);
//	   }
//   } /*P=Nil or  found  */
//   return P;
//}


//address Search2(QueueSpecial L, infotype  X)
//{  /* Mencari apakah  ada elemen QueueSpecial dengan info(P)=X   */
//   /* Jika ada, mengirimkan  address dgn info(P)=X       */
//   /* Jika  tidak ada, mengirimkan Nil 			 */
//   /* Skema tanpa boolean. Tdk berlaku u/ QueueSpecial kosong  	 */
//   address  P;
//   if(First(L)!=Nil){
//   	return Nil;
//   } else {
//   	P=First(L);
//   	while((Next(P)!=Nil)&&(Info(P)!=X)) {
//	      P=Next(P);
//   	} /* Next(P)==Nil or Info(P)==X */
//   	if(Info(P)==X)  {
//   	    return P;
//   	}else {
//   	    return Nil;
//	  }
//   }
//   return P;
//}
//
//
//boolean FSearch(QueueSpecial L, address P)
//{ /* Mencari apakah ada elemen QueueSpecial yang beralamat P  */
//  /* Mengirimkan true jika ada, false jika tidak ada  */
//  /* QueueSpecial Tidak mungkin kosong  */
//
//  address PTemp=First(L);
//  boolean found=false;
//
//  while((PTemp!=Nil)&&(!found)){
//     if(PTemp==P) {
//	 found=true;
//     }
//     else
//     {
//	 PTemp=Next(PTemp);
//     }
//
//  } /* PTemp==Nil or found / ketemu */
//  return found;
//}
//
//address SearchPrec(QueueSpecial L, infotype X)
//{ /* Mengirimkan address elemen sebelum elemen yang nilainya=X */
//  /* Mencari apakah ada elemen QueueSpecial dengan info(P)=X	       */
//  /* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P   */
//  /* dan Info(P)=X; Jika tidak ada mengirimkan Nil	       */
//  /* Jika P adalah  elemen pertama, maka Prec=Nil	       */
//  address Prec;
//  address P;
//
//  if(Next(P)==Nil)  { /* QueueSpecial hanya berisi 1 elemen */
//    Prec=Nil;
//  } else {
//	  P=First(L);
//	  while((Next(P)!=Nil) &&(Info(P)!=X)) {
//	      Prec=P;
//              P=Next(P);
//  	   }  /* Next(P)==Nil or Info(P)==X */
//
//  	   if(Info(P)==X){ /* Ketemu Info (P)== X */
//  	        return Prec;
//  	   } else {
//  	        return Nil;  /* tidak ada X di QueueSpecial */
//  	   }
//     } /* else */
//}

/* ** PRIMITIF BERDASARKAN NILAI ** */

/* ** Penambahan Elemen ** */
void InsVFirst(QueueSpecial *L, infotype X)
{  /* I.S  : L mungkin kosong          */
   /* F.S  : Melakukan alokasi sebuah elemen dan             */
   /*        menambahkan elemen pertama dengan nilai X jika  */
   /*        Alokasi berhasil 				     */
   address P=Alokasi(X);
   if(P!=Nil) { /* Alokasi Berhasil */
      InsertFirst(&(*L),P);
    }
}

void InsVLast(QueueSpecial *L, infotype X)
{ /* I.S  : L mungkin kosong          */
  /* F.S  : Melakukan alokasi sebuah elemen dan                */
  /*        menambahkan elemen QueueSpecial di akhir; elemen terakhir  */
  /*        yang baru bernilai X jika alokasi berhasil,        */
  /*	    Jika alokasi gagal: I.S = F.S		       */

     address P=Alokasi(X);
     if(P!=Nil)
     {  InsertLast(&(*L),P);
         }
}

/* *** Penghapusan Elemen  ***  */

void DelVFirst(QueueSpecial *L, infotype *X)
{ /* I.S    : QueueSpecial tidak kosong  		                 */
  /* F.S    : Elemen pertama QueueSpecial dihapus, nilai info disimpan   */
  /*	      pada X dan alamat elemen pertama  di-dealokasi 	 */
  /* Kamus */
  address  P;

  DelFirst(&(*L),&P); /* Hapus elemem pertama, blm didealokasi */
  *X=Info(P); 		/* info dari First disimpan di X       */
  Dealokasi(&P);
}

void DelVLast(QueueSpecial *L, infotype *X)
{  /* I.S    : QueueSpecial tidak kosong  		                 */
   /* F.S    : Elemen terakhir QueueSpecial dihapus, nilai info disimpan */
   /*	      pada X dan alamat elemen terakhir di-dealokasi 	 */
   address P;
   DelLast(&(*L),&P);
        /* Hapus Elemen Terakhir, addressnya disimpan di P, */
        /* Belum diDealokasi, masih bisa dibaca isinya      */
   *X=Info(P);	/* Info dari address P, ditampung  */
   Dealokasi(&P);
}


/* *******  PRIMITIF BERDASARKAN ALAMAT ********	*/
/* Penambahan Elemen Berdasarkan Alamat 		*/
void InsertFirst(QueueSpecial *L, address P)
{ /* I.S   : Sembarang, P sudah dialokasi		*/
  /* F.S   : Menambahkan elemen ber-address P, sebagai  */
  /*         elemen pertama				*/
    Next(P)=First(*L);
    First(*L)=P;
}

void InsertAfter(QueueSpecial *L, address P, address Prec)
{ /* I.S   : Prec pastilah elemen  dan bukan elemen terakhir  */
  /*         P sudah dialokasi 					  */
  /* F.S   : Insert P sebagai elemen sesudah elemen beralamat Prec*/
	Next(P)=Next(Prec);
	Next(Prec)=P;
}

void InsertLast(QueueSpecial  *L, address P)
{ /* I.S   : Sembarang, P sudah dialokasi			*/
  /* F.S   : P ditambahkan  sebagai elemen terakhir yang baru	*/

      address Last;
      if(QueueSpecialEmpty(*L)) { /* Jika kosong, Insert elemen pertama */
	   InsertFirst(&(*L),P);
      }
      else { /* tdk kosong */
	    Last=First(*L);
            while(Next(Last)!=Nil)  { /* menuju ke last */
	          Last=Next(Last);
	    } /* Next(Last)==Nil */

	  Next(Last)=P;
      }
}

/******* PENGHAPUSAN SEBUAH ELEMEN **********/
void DeleteByAddres(QueueSpecial *L, address Target){
    address temp;
    if(Target->next == Nil){
      DelLast(&(*L), &temp);
    } else {
      
    }
}

void DelFirst (QueueSpecial *L, address *P)
{ /* I.S   : QueueSpecial tidak kosong 	*/
  /* F.S   : P adalah alamat elemen pertama QueueSpecial sebelum penghapusan */
  /*         Elemen QueueSpecial berkurang satu (mungkin menjadi kosong)     */
  /* First elemen yang baru adalah suksesor elemen pertama yang lama */

      *P=First(*L);
      First(*L)=Next(First(*L));
      Next(*P)=Nil;

 }

void DelP(QueueSpecial *L, address X)
{ /* I.S   : Sembarang  */
 /* F.S   : Jika ada elemen  QueueSpecial beraddress P,dengan info (P)=X    */
 /*         Maka P dihapus dari QueueSpecial dan di-dealokasi		     */
 /*	     Jika tidak ada elemen QueueSpecial dengan info(P)=X, maka QueueSpecial  */
 /*         tetap. QueueSpecial mungkin menjadi kosomg karena penghapusan   */
    address temp = First(*L);
    address prev = temp;
    int i = 0;

    if(!ListEmpty(*L)){
      
        while(temp != Nil && temp != X){
          printf("%d", i);
            prev = temp;
            temp = temp->next;
            i++;
        }

        if(temp == X && i == 0){
            First(*L) = Next(First(*L));
            Dealokasi(&temp);
            //printf("Tset");
        } else if(temp == Nil){
            //prev->next = Nil;
        } else {
            prev->next = temp->next;
            Dealokasi(&temp);
        }
    } else {
        printf("Sorry Your List Is Empty");
    }

    //PrintInfo(*L);
}

void DelLast(QueueSpecial *L, address *P)
{ /* I.S   : QueueSpecial tidak kosong  */
  /* F.S   : P adalah alamat elemen terakhir QueueSpecial sebelum penghapusan */
  /*	     Elemen QueueSpecial berkurang 1 (mungkin menjadi kosong)	      */
  /*         Last elemen baru adalah predessesor elemen pertama yang  */
  /*         lama, jika  ada					      */

  /* Kamus */
  address Last,PrecLast;

  Last=First(*L);
  /* dari catatan di kelas */
  if(Next(Last)==Nil)  { /* hanya 1 elemen */
	  DelFirst(&(*L),&(Last));
  }
  else { /* Lebih dr 1 elemen */
	  PrecLast=Nil;
	  while(Next(Last)!=Nil){   /* Maju sampai elemen terakhir */
		  PrecLast=Last;
		  Last=Next(Last);
	  } /* Next(Last)=Nil */
	  *P=Last;
	  Next(PrecLast)=Nil;
       }
}


void DelAfter(QueueSpecial *L, address *Pdel, address Prec)
{  /* I.S   : QueueSpecial tidak kosong, Prec adalah anggota QueueSpecial	*/
   /* F.S   : Menghapus Next(Prec) :				*/
   /*         Pdel adalah alamat elemen QueueSpecial yang dihapus	*/
	*Pdel=Next(Prec);
	Next(Prec)=Next(*Pdel);
}


/* *************PROSES SEMUA ELEMEN ****************   */
void PrintInfo(QueueSpecial L)
{ /* I.S   : QueueSpecial mungkin kosong 	*/
  /* F.S   : Jika QueueSpecial tidak kosong, semua info yang disimpan pada */
  /*         elemen QueueSpecial di-print			  	   */
  /*         Jika QueueSpecial kosong, hanya menuliskan "QueueSpecial Kosong"	   */
  int i;
  address P=First(L);
  if( P==Nil) {
  	  printf("QueueSpecial Kosong !\n");
  } else { /* QueueSpecial tidak kosong */
	    printf("[\n");
	    do {
	 	  printf("%s %d %d %d %d\n", P->info.Nama, P->info.waktuDatang, P->info.jumlahLEbar, P->info.waktuDilayani, P->info.waktuSelesaiDilayani);
		  P=Next(P);
		  i++;
	    } while(P!=Nil);
	    printf("]");
	 }
  printf("\n");
}

int NbElmt(QueueSpecial L)
{ /* Mengirimkan banyaknya elemen QueueSpecial, mengirimkan Nol jika kosong */
  address P;
  int NbEl=0;
  if(QueueSpecialEmpty(L)){
 	return 0;
  } else { /* Tidak kosong */
	      P=First(L);
       	      do {
		    NbEl++;
		    P=Next(P);
	      }while(P!=Nil);
  	}
       return NbEl;
}

//infotype Max(QueueSpecial L)
//{  /* Mengirimkan nilai info(P) yang maksimum */
//
//   address P;
//   infotype MMax;
//   if(!QueueSpecialEmpty(L))
//   {      P=First(L);
//	  MMax=Info(P);
//	  while(Next(P)!=Nil) {
//	 	P=Next(P);
//		if(Info(P)>MMax) {
//		   MMax=Info(P);
//		}
//	  } /* Next(P)==Nil */
//   }
//  return MMax;
//}
//
//address AdrMax(QueueSpecial L)
//{  /* mengirimkan address P, dengan info (P) yang maksimum */
//
//   address PMax,P;
//   infotype Max;
//   if(!QueueSpecialEmpty(L)){
//	   P=First(L);
//	   Max=Info(P);
//	   while(Next(P) != Nil) {
//		   P=Next(P);
//		   if(Info(P)>Max) {
//			   Max = Info(P);
//			   PMax=P;
//		   }
//	   } /* Next(P)==Nil */
//   }
//   return PMax;
//}
//
//
//infotype Min(QueueSpecial L)
//{ /* mengirimkan nilai info(P), yang minimum    */
//
//   address P;
//   infotype MMin;
//   if(!QueueSpecialEmpty(L))
//   {      P=First(L);
//	  MMin=Info(P);
//	  while(Next(P)!=Nil) {
//	 	   P=Next(P);
//		   if(Info(P)<MMin) {
//		        MMin=Info(P);
//		   }
//	  } /* Next(P)==Nil */
//    }
//    return MMin;
//}
//
//
//address AdrMin(QueueSpecial L)
//{ /* mengirimkan address P, dengan info(P) yang minimum */
//
//   address PMin,P;
//   infotype Min;
//   if(!QueueSpecialEmpty(L)){
//	   P=First(L);
//	   Min=Info(P);
//	   while(Next(P) != Nil) {
//	      P=Next(P);
//	      if(Info(P)<Min) {
//			   Min = Info(P);
//			   PMin=P;
//		   }
//  	   }
//   }
//   return PMin;
//}
//
//float Average(QueueSpecial L)
//{  /* mengirimkan nilai rata-rata info(P)	*/
//	address P;
//	infotype NbEl,Count;
//	float avg;
//
//	if(!QueueSpecialEmpty(L)) { /* Tidak kosong */
//		P=First(L);
//		Count=Info(P);
//		NbEl=1;
//		while(Next(P)!=Nil)
//		{  P=Next(P);
//		   Count=Count+Info(P);
//		   NbEl++;
//		} /*Next(P) == Nil */
//		avg= (float)Count/(float)NbEl;
//	}
//       return avg;
//}

/******************************************************/
/***   		PROSES TERHADAP QueueSpecial		    ***/
/******************************************************/
void DelAll(QueueSpecial *L)
{ /* Delete semua elemen QueueSpecial, dan alamat elemen di-dealokasi */
   infotype X;
   while(!QueueSpecialEmpty(*L)) {
	  DelVFirst(&(*L),&X);
   } /* kosong */
}

void InversQueueSpecial(QueueSpecial *L)
{ /* I.S   : sembarang  			*/
  /* F.S   : elemen QueueSpecial  dibalik		*/
  /*	   elemen terakhir menjadi elemen pertama, dst    */
  /*	   Membalik elemen QueueSpecial, tanpa alokasi/dealokasi  */

	/* Kamus */
	QueueSpecial LTemp;
	address P;

	/* Algoritma */
	CreateQueueSpecial(&LTemp);
	while(First(*L)!=Nil){
		DelFirst(&(*L),&P);
		Next(P)=Nil;
		InsertFirst(&LTemp,P);
	}
	First(*L)=First(LTemp);
}

QueueSpecial FInversQueueSpecial(QueueSpecial L)
{ /* mengirimkan QueueSpecial baru (LB), hasil invers dari L 	*/
  /* dengan Alokasi 					*/

  /* QueueSpecial L tidak kosong ; min 1 elemen				*/

  /* Kamus */
   QueueSpecial LB;
   address P,PB;
   infotype X;

  /* Algoritma */
	P=First(L);
	CreateQueueSpecial(&LB);
	do {    X=Info(P);
		PB=Alokasi(X);
		if(PB!=Nil) { /* berhasil alokasi */
		    InsertLast(&LB,PB);
		    P=Next(P);
		} else { /* alokasi gagal */
			    DelAll(&LB);
			    First(LB)=Nil;
			}
	} while (P!= Nil);
   return LB;
}

void CopyQueueSpecial(QueueSpecial L1, QueueSpecial *L2)
{ /* I.S   : L1 sembarang 				*/
  /* F.S   : L1 dan L2 menunjuk ke QueueSpecial yang sama 	*/
  /*         tidak ada alokasi/dealokasi 		*/
   *L2=L1;
}


QueueSpecial FCopyQueueSpecial(QueueSpecial L)
{ /* Mengirimkan QueueSpecial yang merupakan salinan L  	*/
    QueueSpecial baru;
    baru.First = Nil;
    address P;
    //CreateQueueSpecial(&baru);

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

void CpAlokQueueSpecial(QueueSpecial Lin, QueueSpecial  *Lout)
{ /* I.S   : Lin sembarang				    */
  /* F.S   : Jika semua alokasi berhasil, maka Lout berisi  */
  /*         hasil copy Lin. Jika ada alokasi yang  gagal   */
  /*         maka Lout=Nil, dan semua elemen yang terlanjur */
  /*	   dialokasi, didealokasi dengan melakukan alokasi  */
  /*	   elemen. Lout adalah QueueSpecial kosong, jika ada alokasi*/
  /*	   elemen yang gagal				    */

	/* Kamus */
	address P,Pout;
	infotype X;

	/* ALgoritma */
	if(!QueueSpecialEmpty(Lin)) { /* tidak kosong */

		CreateQueueSpecial(&(*Lout));
		P=First(Lin);
		do
		{  X=Info(P);
		   Pout=Alokasi(X);
		   if(Pout!=Nil) {  /* Alokasi berhasil */
			InsertLast(&(*Lout),Pout);
			P=Next(P);
		   } else { /* Alokasi Pout gagal */
			     DelAll(&(*Lout));
			     First(*Lout)=Nil;
			     break;
		          }
	        } while	(Next(P) != Nil);
	}
}


void konkat(QueueSpecial L1, QueueSpecial L2, QueueSpecial *L3)
{ /* I.S   : L1 dan L2 sembarang			      */
/* F.S   : L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 &  */
/*	   L2. Jika semua alokasi berhasil, maka L3  adalah   */
/*	   hasil konkatenasi. Jika ada alokasi yang gagal,    */
/*	   semua elemen yang sudah dialokasi, di-dealokasi dan*/
/*	   L3=Nil					      */
/*
/*      L1, dan L2 tidak kosong */

	/* Kamus */
	address P1,P2,P3;
        infotype X1,X2;

	/* Algoritma */
	CreateQueueSpecial(&(*L3));

	/* Mengisi L3 dengan L1 */
	P1=First(L1);
	do
	{ /* L1 minimal 1 elemen */
		X1=Info(P1);
		P3=Alokasi(X1);
		if(P3!=Nil) { /* Alokasi L3 berhasil */
			InsertLast(&(*L3),P3);
			P1=Next(P1);
		} else { /* Alokasi gagal ; L3 di-dealokasi semua */
			    DelAll(&(*L3));
			    First(*L3)=Nil;
			    break;
			}
	} while(Next(P1) != Nil);

	/* Mengisi L3 dengan L2 */
	P2=First(L2);
	do
	{ /* L2 minimal 1 elemen */
		X2=Info(P2);
		P3=Alokasi(X2);
		if(P3!=Nil){
			InsertLast(&(*L3),P3);
			P2=Next(P2);
		} else { /* Alokasi L3 gagal */
			DelAll(&(*L3));
			First(*L3)=Nil;
			break;
		}
	}while (Next(P2)!=Nil);
}

void konkat1(QueueSpecial *L1, QueueSpecial *L2, QueueSpecial *L3)
{ /* I.S  : L1 dan L2 sembarang	; 			  */
  /* F.S  : L1 dan L2 kosong,  L3 adalah hasil konkatenasi*/
  /*	  L1 & L2, 					  */
  /* Konkatenasi 2 buah QueueSpecial : L1 dan L2 menghasilkan L3  */
  /* yang baru (dengan elemen QueueSpecial L1 dan L2 menjadi      */
  /* QueueSpecial kosong. Tidak ada alokasi/dealokasi  		  */


  address P1,P2,P3;
  infotype X1,X2,X3;

   CreateQueueSpecial(&(*L3));

   while (First(*L1)!=Nil)  /* L1 belum kosong */
   {   DelFirst(&(*L1),&P1);
       InsertLast(&(*L3),P1);
   } /* First(L1) == Nil ; Kosong */

   while (First(*L2)!=Nil)  /* L2 belum kosong */
   {   DelFirst(&(*L2),&P2);
       InsertLast(&(*L3),P2);
   } /* First (L2) == Nil ; kosong */

}

void PecahQueueSpecial(QueueSpecial *L1, QueueSpecial *L2, QueueSpecial L)
{ /* I.S  : L mungkin kosong  */
  /* F.S  : Berdasarkan L, dibentuk 2 buah QueueSpecial L1 dan L2     */
  /*        L tidak berubah. Untuk membentuk L1 dan L2 harus  */
  /*	  alokasi. L1 berisi separuh elemen  L dan L2 berisi  */
  /*	  sisa elemen L. Jika elemen L ganjil, maka separuh   */
  /* 	  adalah NbElmt(L)div 2				      */

  /* Kamus */
  address P,P1,P2;
  infotype X1,X2;

  int Nb,tengah;

  /* ALgoritma */
  if(!QueueSpecialEmpty(L)) {           /* tidak kosong ; minimal 1 elemen    */
	  CreateQueueSpecial(&(*L1));

	  if(NbElmt(L)==1) {  /* Hanya L1 yang dapat diisi 1 elm, dari L */
		  First(*L1)=First(L);
	  } else /* L1 beirisi > 1 elemen */
	  	{  tengah = NbElmt(L) / 2;
		   P=First(L);
		   Nb=1;

		   do /* mengisi L1 */
		   {  X1=Info(P);
		      P1=Alokasi(X1);
	   	      if(P1!=Nil){
			  InsertLast(&(*L1),P1);
			  P=Next(P);
			  Nb++;
		      } else { /* alokasi gagal; semua di-dealokasi */
			  DelAll(&(*L1));
			  First(*L1)=Nil;
		    	  break;
		      	}
		   } while(Nb<=tengah);

		   do  /* Mengisi L2 */
		   {  X2=Info(P);
	       	      P2=Alokasi(X2);
	   	      if(P2!=Nil) {
			      InsertLast(&(*L2),P2);
			      P=Next(P);
		      } else {
			      DelAll(&(*L2));
			      First(*L2)=Nil;
			      break;
		      }
		   } while(Next(P)!=Nil);
		} /* End ; L > 1 elemen */
  } else { /* First(L) == Nil */
		printf("QueueSpecial tidak dapat dipecah ! Kosong !\n");
	  }
}

void sortQueueSpecialQueue(QueueSpecial *L){
int swapped, i;
    address ptr1;
    address lptr = NULL;
    int no_1, no_2;

    /* Checking for empty QueueSpecial */
    if (L->First == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = L->First;

        while (ptr1->next != lptr)
        {
            if(ptr1->info.waktuDatang > ptr1->next->info.waktuDatang){
                swapAddr(ptr1, ptr1->next);
                swapped = 1;
            }
             else if( ptr1->info.waktuDatang == ptr1->next->info.waktuDatang){
                if(ptr1->info.jumlahLEbar > ptr1->next->info.jumlahLEbar){
                    swapAddr(ptr1, ptr1->next);
                    swapped = 1;
                }
            }

            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

void swapAddr(address a, address b){
    infotype temp = a->info;
    a->info = b->info;
    b->info = temp;
}
