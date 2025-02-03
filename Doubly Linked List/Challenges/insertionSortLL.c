#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node_t;

// Function prototypes
node_t* insertionSortLL(node_t* head); // Your sorting function
node_t* createNode(int data);
node_t* insertAtEnd(node_t* head, int data);
void printList(node_t* head);
void freeList(node_t* head);

node_t* createNode(int data) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end of the list
node_t* insertAtEnd(node_t* head, int data) {
    node_t* newNode = createNode(data);
    if (head == NULL) return newNode;

    node_t* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Print linked list
void printList(node_t* head) {
    node_t* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free linked list memory
void freeList(node_t* head) {
    node_t* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

node_t* insertionSortLL (node_t* head)
{

    if (head == NULL)
    {
        fprintf(stderr, "List is empty");
        return NULL;
    }
    
    node_t* trav = NULL;
    
    for (node_t* curr = head -> next; curr != NULL; curr = curr -> next)
    {
        int key = curr -> data;
        trav = curr -> prev;
        
        while (trav != NULL && key < (trav -> data))
        {
            trav -> next -> data = trav -> data;
            trav = trav -> prev;
        }
        
        trav -> next -> data = key;
    }
    
    return head;
}

void testSelectionSortLinkedList() {
    // Creating an unsorted linked list: 4 -> 2 -> 1 -> 5 -> 3
    node_t* head = NULL;
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 3);

    printf("Before Sorting:\n");
    printList(head);

    head = insertionSortLL(head);

    printf("After Sorting:\n");
    printList(head);

    
    freeList(head);
}




// Main function to run the test
int main() {
    testSelectionSortLinkedList();
    return 0;
}
    