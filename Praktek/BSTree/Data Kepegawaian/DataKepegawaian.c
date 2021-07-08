#include "DataKepegawaian.h"
#include <stdlib.h>
#include <Windows.h>
#include <stdio.h>
/* ==== Method Utama ====*/
//membuat bst
void createDataKepegawaian(BSTree *DataPegawai){
	(*DataPegawai).Root= NULL;
}

//menambahkan data pegawai
void insertDataPegawai(address *DataKepegawaian, infotype infoDataPegawai)
{
	if(isEmpty(*DataKepegawaian)){
		(*DataKepegawaian) = AlokasiDataPegawai(infoDataPegawai);
		return;
	}

	if(isEquals((*DataKepegawaian)->info.id, infoDataPegawai.id)){
		printf("duh ga bisa sama ID-nya");
		return;
	} else if((*DataKepegawaian)->info.id > infoDataPegawai.id){
		if(isEmpty((*DataKepegawaian)->left)){
			(*DataKepegawaian)->left = AlokasiDataPegawai(infoDataPegawai);
			return;
		}else {
			insertDataPegawai(&(*DataKepegawaian)->left, infoDataPegawai);
		}
	} else{
		if(isEmpty((*DataKepegawaian)->right)){
			(*DataKepegawaian)->right = AlokasiDataPegawai(infoDataPegawai);
			return;
		}else {
			insertDataPegawai(&(*DataKepegawaian)->right, infoDataPegawai);
		}	
	}
}
//menghapus data pegawai
void deleteDataPegawai(address *DataKepegawaian, infotype infoDataPegawai){
	address temp;
	if(isEmpty(*DataKepegawaian)){
		printf("yah gak ada bos ID-nya");
		return;
	}

	if(isEquals((*DataKepegawaian)->info.id, infoDataPegawai.id)){
		printf("yes ketemu sebentar . . .");
		if(isEmpty((*DataKepegawaian)->left) && isEmpty((*DataKepegawaian)->right)){
			DealokasiDataPegawai(&(*DataKepegawaian));
		}else if(isEmpty((*DataKepegawaian)->left) || isEmpty((*DataKepegawaian)->right)){
			if(!isEmpty((*DataKepegawaian)->left)){
				(*DataKepegawaian)->info = (*DataKepegawaian)->left->info;
				DealokasiDataPegawai(&(*DataKepegawaian)->left);
			} else if(!isEmpty((*DataKepegawaian)->right)){
				(*DataKepegawaian)->info = (*DataKepegawaian)->right->info;
				DealokasiDataPegawai(&(*DataKepegawaian)->right);
			}
		} else {
			//find succesor of P
			temp = succesor((*DataKepegawaian)->right);
			if(!isEmpty(temp)){
				(*DataKepegawaian)->info = temp->info;
				DealokasiDataPegawai(&temp);
			}	
		}
	} else if((*DataKepegawaian)->info.id > infoDataPegawai.id){
		deleteDataPegawai(&(*DataKepegawaian)->left, infoDataPegawai);
	} else{
		deleteDataPegawai(&(*DataKepegawaian)->right, infoDataPegawai);
	}
}
//mencari data
address searchDataPegawai(address DataKepegawaian, infotype infoDataPegawai){
	address currentAddr = DataKepegawaian;
	if(isEmpty(currentAddr)){
		return NULL;
	}

	if(isEquals(infoDataPegawai.id, currentAddr->info.id)){
		return currentAddr;
	} else if(currentAddr->info.id > infoDataPegawai.id){
		currentAddr = searchDataPegawai(currentAddr->left, infoDataPegawai);
	} else {
		currentAddr = searchDataPegawai(currentAddr->right, infoDataPegawai);
	}
	return currentAddr;
}
//menampilkan seluruh data secara in-order
void printDataKepegawaianInOrder(address DataKepegawaian){
	if(DataKepegawaian == NULL){
		printf("NULL\n");
		return;
	}
	printInOrder(DataKepegawaian);
}
//modul tambahan print data
void printInOrder(address DataKepegawaian){
	if(!isEmpty(DataKepegawaian)){
        printInOrder(DataKepegawaian->left);
        printf("%d %s\n", DataKepegawaian->info.id, DataKepegawaian->info.nama);
        printInOrder(DataKepegawaian->right);
    }

	printf("\n");
}
//Alokasi Data Kepegawaian
address AlokasiDataPegawai(infotype infoDataKepegawaian){
	address P = (address)malloc(sizeof(node));
	if(!isEmpty(P)){
		P->info = infoDataKepegawaian;
		P->left = NULL;
		P->right =NULL;
	}
	return P;
}
//Delokasi Data Kepegawaian
void DealokasiDataPegawai(address *DataPegawai){
	free(*DataPegawai);
	(*DataPegawai) = NULL;
}
//cek addres empty nggak
bool isEmpty(address DataPegawai){
	if(DataPegawai == NULL){
		return true;
	}else{
		return false;
	}
}
//cek apakah value a, b sama atau tidak
bool isEquals(int a, int b){
	if(a == b){
		return true;
	} else {
		return false;
	}
}
//insert infotype data pegawai
infotype insertInfoType(){
	infotype DataPegawai;
	printf("ID    : ");
	scanf("%d", &DataPegawai.id);
	fflush(stdin);
	printf("Nama  : ");
	scanf("%[^\n]", DataPegawai.nama);
	return DataPegawai;
}
//search succesor dari P, syarat P jangan NULL
//syarat P parameter yg dimasukkan adalah kanannya dulu
address succesor(address P){
	if(isEmpty(P)){
		return NULL;
	}
	if(!isEmpty(P->left)){
		return succesor(P->left);
	}
}

/*==== Method Fitur Apps ==== */
int home(){
	printf("=========================\n");
	printf(" PT SEJAHTERA KAMI SEMUA\n");
	printf("=========================\n");
	printf("1. Insert Data Pegawai\n");
	printf("2. Delete Data Kepegawaian\n");
	printf("3. Show Data Pegawai\n");
	printf("4. Search Data Pegawai\n");
	printf("0. Exit\n");
	int pilihMenu;
	printf("\nPilih : ");
	scanf("%d", &pilihMenu);
	return pilihMenu;
}
void tampilDataPegewai(BSTree DataKepegawaian){
	printDataKepegawaianInOrder(DataKepegawaian.Root);
}
void tambahDataPegawai(BSTree *DataKepegawaian){
	printf("Silahkan inputkan info data pegawai :\n");
	infotype DataPegawai = insertInfoType();
	insertDataPegawai(&(*DataKepegawaian).Root, DataPegawai);
}
void deleteDataKepegawaian(BSTree *DataKepegawaian){
	printf("Silahkan inputkan info data pegawai yang akan di delete :\n");
	infotype DataPegawai = insertInfoType();
	deleteDataPegawai(&(*DataKepegawaian).Root, DataPegawai);
}
void searchDataKepegawaian(BSTree DataKepegawaian){
	infotype info;
	int ID;
	printf("Silahkan inputkan ID data pegawai\n");
	scanf("%d", &ID);
	info.id = ID;
	address search = searchDataPegawai(DataKepegawaian.Root, info);
	if(isEmpty(search)){
		//print tidak ada something
		printf("tidak ada");
	} else {
		//yee ada
		printf("ada");
	}
}