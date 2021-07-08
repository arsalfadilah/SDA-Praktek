
/*** Data Structure Non Binary Tree ***/
/**************************************/

#ifndef Nonbinarytree_H
#define Nonbinarytree_H

#include <stdbool.h>
/*** User Defined Data Type ***/
/** Infotype is info of each node tree **/
/**| If u want edit info only in here |**/
typedef struct
{
    /* data */
    char Nama[100];
    char Jabatan[100];
} infotype;
typedef struct Node *addrNodeTree;

/** Address of node tree **/
typedef addrNodeTree addrParent;
/** 
 * Node Tree is a 
 * element will be created for 
 * ADT non binary tree 
 * **/
typedef struct Node
{
    /* data */
    addrParent parents;
    infotype info;
    addrNodeTree child;
    addrNodeTree next;
} NodeTree;

/** nbTree is Non Binary Tree data type. this is will be acces root (first) for a moment **/
typedef struct
{
    /* data */
    addrNodeTree first;
} nbTree;

/*** End Of User Defined Data Type ***/
/*************************************/

/****************************************************/
/***                 Operations                   ***/
/****************************************************/

/******************/
/** Constructor **/

//write the constructor here

void createTree(nbTree *tree);
/** Membuat tree kosong **/

void createInfo(infotype *X);
/** Membuat Isi dari infotype **/

/** End Of Constructor **/
/************************/

/***************/
/** Accessor **/
/*** How to Access Root ?***/
/**
    Traversal Preorder (Root/Parent-Left-Right)
    Traversal PostOrder (Left-Right-Root/Parent)
    Traversal Inorder (Left-Root/Parent-Right)
Note :
    If Parent Have Children, Acces Children First
**/

//write code accesors here
void setInfo(nbTree *tree, infotype A, infotype B);
/** Mengatur info dari alamat A sebagai info X **/

addrNodeTree getParentsAddr(nbTree tree, infotype X);
/** Mendapatkan address dari parents dengan infotype X **/

infotype getParentsInfo(nbTree tree, infotype x);
/** Mendapatkan infotype parents dengan address yang diberikan oleh P **/

infotype getChildInfo(nbTree tree, addrNodeTree C);
/** Mendapatkan infotype child dengan address yang diberikan oleh P **/

/** End of Accessor **/
/********************/

/*************/
/** Mutator **/

//write your code mutator
void addNextBrother(addrNodeTree *Root, infotype input);
/** Menambahkan node tree selain di node pertama pada **/
/** suatu level dengan alamat yang sudah dialokasi **/

void addFirst(addrNodeTree *Root, infotype input);
/** Menambahkan node tree di kiri (node pertama pada **/
/** suatu level) dengan alamat yang sudah dialokasi**/

void addRoot(nbTree *tree, infotype X);
/** Menambahkan root atau 3lement pertama dari tree **/

/** End Of Mutator **/
/********************/

/****************/
/** Destructor **/

//write your destructor here
void delAll(nbTree *tree);
/** Semua tree akan dihapus dan di dealokasikan **/

void delByInfo(nbTree *tree, infotype X);
/** Mengahpus element yang berisikan info X, bisa jadi parent/root/child **/

/** End Of Destructor **/
/***********************/

/****************/
/** Read/Write **/

//write your code read/write
void printPreOrder(addrNodeTree Root);
/** Menampilkan node secara Pre Order : root, left, right **/

void printPostOrder(nbTree Root);
/** Menampilkan node secara Post Order : left, right, root **/

void printInOrder(nbTree Root);
/** Menampilkan node secara In Order : left, root , right **/

void printChildInfo(addrNodeTree parent);
/** Menampilkan anak-anak dari suatu parent**/

void printInfo(infotype X);
/** Menampilkan Info **/

/** End of Read/Write **/
/**********************/

/** additional **/
addrNodeTree Alokasi(infotype X);

void FindAddrByInfo(addrNodeTree root, infotype x, addrNodeTree *P);

bool CompareInfo(infotype A, infotype B);

void setName(infotype *x);

#endif

// /******* Body ********/
// void setInfo(nbTree *tree, infotype A, infotype B)
// {
//     /** Merubah node berinfo A menjadi B **/
//     addrNodeTree P = NULL;
//     FindAddrByInfo((*tree).first, A, &P);
//     if (P != NULL)
//     {
//         P->info = B;
//     }
// }

// addrNodeTree Alokasi(infotype X)
// {
//     /** Mengalokasikan memori untuk type X **/
//     addrNodeTree P;
//     P = (addrNodeTree)malloc(sizeof(NodeTree) + 1);
//     if (P != NULL)
//     {
//         P->info = X;
//         P->child = NULL;
//         P->parents = NULL;
//         P->next = NULL;
//     }
//     return P;
// }

// void createTree(nbTree *tree)
// {
//     /** Membuat tree kosong **/
//     (*tree).first = NULL;
// }

// void addRoot(nbTree *tree, infotype X)
// {
//     /** Menambahkan root atau element pertama dari tree **/
//     addrNodeTree P = Alokasi(X);
//     if (P != NULL)
//     {
//         (*tree).first = P;
//     }
//     else
//     {
//         return;
//     }
// }

// void createInfo(infotype *X)
// {
//     /** Membuat Isi dari infotype **/
//     fflush(stdin);
//     printf("Jabatan : ");
//     scanf("%49[^\n]", (*X).Jabatan);
//     fflush(stdin);
//     printf("Nama    : ");
//     scanf("%49[^\n]", (*X).Nama);
// }

// void addFirst(addrNodeTree *Root, infotype input)
// {
//     /** Menambahkan node tree di kiri (node pertama pada **/
//     /** suatu level) dengan alamat yang sudah dialokasi**/
//     addrNodeTree P = Alokasi(input);
//     addrNodeTree curr;
//     if (*Root != NULL && (*Root)->child == NULL)
//     {
//         curr = *Root;
//         P->parents = curr;
//         (*Root)->child = P;
//     }
// }

// void addNextBrother(addrNodeTree *Root, infotype input)
// {
//     // addrNodeTree getParentsAddr(addrNodeTree root, infotype X)
//     addrNodeTree P = Alokasi(input);
//     if ((*Root) != NULL && P != NULL)
//     {
//         P->parents = (*Root)->parents;
//         (*Root)->next = P;
//     }
// }

// void printPreOrder(addrNodeTree Root)
// {
//     /** Menampilkan node secara Pre Order : root, left, right **/
//     if (Root != NULL)
//     {
//         printInfo(Root->info);
//         printf("\n");
//     }
//     else
//     {
//         printf("Sorry no one root available");
//     }

//     if (Root->child != NULL)
//     {
//         printPreOrder(Root->child);
//     }

//     if (Root->next != NULL)
//     {
//         printPreOrder(Root->next);
//     }
// }

// void FindAddrByInfo(addrNodeTree root, infotype x, addrNodeTree *P)
// {
//     /** Guard if root = null **/
//     if (root == NULL)
//         return;

//     //Search using preOrder transversal
//     if (CompareInfo(root->info, x))
//     {
//         *P = root;
//     }

//     if (root->child != NULL)
//     {
//         FindAddrByInfo(root->child, x, &(*P));
//     }

//     if (root->next != NULL)
//     {
//         FindAddrByInfo(root->next, x, &(*P));
//     }
// }

// infotype getParentsInfo(nbTree tree, infotype x)
// {
//     /** Mendapatkan infotype parents dengan address yang diberikan oleh P **/
//     infotype def;
//     strcpy(def.Jabatan, "Not Find");
//     strcpy(def.Nama, "Not Find");
//     addrNodeTree P = NULL;
//     FindAddrByInfo(tree.first, x, &P);
//     if (P != NULL)
//     {
//         /* code */
//         return P->parents->info;
//     }
//     else
//     {
//         return def;
//     }
// }

// addrNodeTree getParentsAddr(nbTree tree, infotype x)
// {
//     /** Mendapatkan infotype parents dengan address yang diberikan oleh P **/
//     addrNodeTree P = NULL;
//     FindAddrByInfo(tree.first, x, &P);
//     if (P != NULL)
//     {
//         /* code */
//         return P->parents;
//     }
//     else
//     {
//         return P;
//     }
// }

// bool CompareInfo(infotype A, infotype B)
// {
//     /** Method untuk membadingkan Infotype **/
//     if (strcmp(A.Nama, B.Nama) == 0)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// void setName(infotype *x)
// {
//     strcpy((*x).Jabatan, "default");
//     //guard
//     fflush(stdin);
//     printf("Nama    : ");
//     scanf("%49[^\n]", (*x).Nama);
// }

// void printInfo(infotype X)
// {
//     /** Menampilkan Info **/
//     printf("Jabatan : %s\n", X.Jabatan);
//     printf("Nama    : %s\n", X.Nama);
// }

// void printChildInfo(addrNodeTree parent)
// {
//     /** Menampilkan anak-anak dari suatu parent**/
//     if (parent != NULL)
//     {
//         printInfo(parent->info);
//         printf("\n");
//     }

//     if (parent->next != NULL)
//         printChildInfo(parent->next);
// }
