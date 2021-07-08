#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "NonBinaryTree.h"

int menu()
{
    int fitur;
    do
    {
        //clearkan layar monitor
        system("cls");
        //fitur menu
        printf("=== Program Organisasi ===\n");
        printf("1. Add Root\n");
        printf("2. Add Child\n");
        printf("3. Add Brother\n");
        printf("4. Print PreOrder\n");
        printf("5. Print PostOrder (Not Yet)\n");
        printf("6. Print InOrder (Not Yet)\n");
        printf("7. Print Lever Order (Not Yet)\n");
        printf("8. Info Atasan\n");
        printf("9. Info Bawahan\n");
        printf("0. Exit\n");
        printf("\nChoose : ");
        scanf("%d", &fitur);
    } while (fitur < 0 || fitur > 9);

    return fitur;
}

int main()
{
    //Deklarasi
    nbTree tree;
    infotype x, input;
    addrNodeTree current;
    int fitur = -1;

    //Inisialisasi
    current = NULL;
    createTree(&tree);

    //Make Apps Still a live untill user press exit
    while ((fitur = menu()) != 0)
    {
        switch (fitur)
        {
        case 1:
            //Input Info
            createInfo(&x);
            //masukan ke root
            addRoot(&tree, x);
            break;
        case 2:
            //print dulu tree
            printPreOrder(tree.first);
            //input dimana mau masuknya
            printf("Menambahakan bawahan siapa ?\n");
            setName(&x);
            //infotype untuk node baru
            printf("Siapakah yang ditambahkan ?\n");
            createInfo(&input);
            //cari alamatnya
            FindAddrByInfo(tree.first, x, &current);
            //masukan sebagai anak pertama dari current
            if (current != NULL)
                addFirst(&current, input);
            else
                printf("Sorry cant find that node");
            break;
        case 3:
            //print dulu tree
            printPreOrder(tree.first);
            //input dimana mau masuknya
            printf("Menambahakan satu level dimana ?\n");
            setName(&x);
            //infotype untuk node baru
            printf("Siapakah yang ditambahkan ?\n");
            createInfo(&input);
            //cari alamatnya
            FindAddrByInfo(tree.first, x, &current);
            //masukan sebagai brother dari current
            if (current != NULL)
                addNextBrother(&current, input);
            else
                printf("Sorry cant find that node\n");
            break;
        case 4:
            //pastikan layar bersih
            system("cls");
            printPreOrder(tree.first);
            break;
        case 8:
            printPreOrder(tree.first);
            printf("Siapa bawahannya ?\n");
            setName(&x);
            printf("Atasannya adalah %s\n", getParentsInfo(tree, x).Nama);
            break;
        case 9:
            printPreOrder(tree.first);
            printf("Siapa Atasannya ?\n");
            setName(&x);
            printf("Bawahannya adalah :\n");
            FindAddrByInfo(tree.first, x, &current);
            printChildInfo(current->child);
            break;
        default:
            printf("Mungkin fitur belum ada :)\n");
            break;
        }
        system("pause");
    }

    return 0;
}