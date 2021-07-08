#include <stdio.h>
#include <Windows.h>
#include "DataKepegawaian.h"

int main(){
    //inisialisasi
    int stillAlive = 1;
    BSTree DataKepegawaian;
    createDataKepegawaian(&DataKepegawaian);
    while (stillAlive != 0)
    {
        stillAlive = home();
        switch (stillAlive)
        {
            case 1:
                tambahDataPegawai(&DataKepegawaian);
                break;
            case 2:
                deleteDataKepegawaian(&DataKepegawaian);
                break;
            case 3:
                tampilDataPegewai(DataKepegawaian);
            break;
            case 4:
                searchDataKepegawaian(DataKepegawaian);
                break;
        default:
            break;
        }
        printf("\n");
        system("pause");
	    system("cls");
    }
    return 0;
}