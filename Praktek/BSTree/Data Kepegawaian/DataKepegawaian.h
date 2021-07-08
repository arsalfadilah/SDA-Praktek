#ifndef DATAKEPEGAWAIAN_H
#define DATAKEPEGWAIAN_H

#include <stdbool.h>

//struktur data
typedef struct Node* address;
typedef struct {
	int id;
	char nama[50];
}infotype;
typedef struct Node{
	infotype info;
	address left;
	address right;
}node;
typedef struct{
	address Root;
}BSTree;
/* ==== Method Utama ====*/
//membuat bst
void createDataKepegawaian(BSTree *DataPegawai);
//menambahkan data pegawai
void insertDataPegawai(address *DataKepegawaian, infotype infoDataPegawai); 
//menghapus data pegawai
void deleteDataPegawai(address *DataKepegawaian, infotype infoDataPegawai);
//mencari data 
address searchDataPegawai(address DataKepegawaian, infotype infoDataPegawai);  
//menampilkan seluruh data secara in-order
void printDataKepegawaianInOrder(address DataKepegawaian);
//print In Order
void printInOrder(address DataKepegawaian);
//Alokasi Data Kepegawaian
address AlokasiDataPegawai(infotype infoDataKepegawaian);
//Delokasi Data Kepegawaian
void DealokasiDataPegawai(address *DataPegawai);
//cek addres empty atau tidak
bool isEmpty(address DataPegawai);
//cek apakah value a, b sama atau tidak
bool isEquals(int ID_1, int ID_2);
//insert infotype data pegawai
infotype insertInfoType();
//search succesor dari P
address succesor(address DataKepegawaian);

/*==== Method Fitur Apps ====*/
int home();
void tampilDataPegewai(BSTree DataKepegawaian);
void tambahDataPegawai(BSTree *DataKepegawaian);
void searchDataKepegawaian(BSTree DataKepegawaian);
void deleteDataKepegawaian(BSTree *DataKepegawaian);

#endif