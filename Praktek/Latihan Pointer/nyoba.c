// C program for the above approach
#include <stdio.h>
#include <stdlib.h>

// Node for linked list
//struct Node {
//    int data;
//    address next;
//};
typedef struct Node *address;
typedef struct Node {
    int data;
    address  next;
} node;
typedef struct {
     address First;
} List;
// Function to print given linked list
void printList(address head)
{
    address ptr = head;
    while (ptr) {

        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL");
}

// Function to create a new node
void insert(address head_ref, int data)
{
    // Allocate the memory for new Node
    // in the heap and set its data
    address newNode = (address) malloc(sizeof(struct Node));

    newNode->data = data;

    // Set the next node pointer of the
    // new Node to point to the current
    // node of the list
    newNode->next = head_ref;

    // Change the pointer of head to point
    // to the new Node
    head_ref = newNode;
}

// Function to create a copy of a linked list
address copyList(address head)
{
    if (head == NULL) {
        return NULL;
    }
    else {

        // Allocate the memory for new Node
        // in the heap and set its data
        address newNode
            = (address)malloc(
                sizeof(struct Node));

        newNode->data = head->data;

        // Recursively set the next pointer of
        // the new Node by recurring for the
        // remaining nodes
        newNode->next = copyList(head->next);

        return newNode;
    }
}

// Function to create the new linked list
address create(int arr[], int N)
{
    // Pointer to point the head node
    // of the singly linked list
    address head_ref = NULL;

    // Construct the linked list
    for (int i = N - 1; i >= 0; i--) {

        insert(head_ref, arr[i]);
    }

    // Return the head pointer
    return head_ref;
}

// Function to create both the lists
void printLists(address head_ref,
                address dup)
{

    printf("Original list: ");

    // Print the original linked list
    printList(head_ref);

    printf("\nDuplicate list: ");

    // Print the duplicate linked list
    printList(dup);
}

// Driver Code
int main(void)
{
    // Given nodes value
    int arr[] = { 1, 2, 3, 4, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);

    // Head of the original Linked list
    //    address head_ref = create(arr, N);
    address head_ref = create(arr, N);

    // Head of the duplicate Linked List
//    address dup = copyList(head_ref);
    address dup = copyList(head_ref);

    printLists(head_ref, dup);

    return 0;
}
