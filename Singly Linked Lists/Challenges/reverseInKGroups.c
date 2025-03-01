#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int x;
    struct Node *next;
} node_t;

void insertAtEnd(node_t **head, int val)
{
    

    node_t *new_node = malloc(sizeof(node_t));
    new_node->x = val;
    new_node->next = NULL;

      if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    node_t *trav = *head;

    while (trav->next != NULL)
    {
        trav = trav->next;
    }

    trav->next = new_node;
}

void insertAtBeginning(node_t **head, int val)
{

    node_t *new_node = malloc(sizeof(node_t));
    new_node->x = val;
    new_node->next = *head;
    *head = new_node;
}
node_t *reverseInKGroups(node_t *head, int k)
{

    if (head == NULL || k == 1)
    {
        return head;
    }

    int i = 0, count = 0;
    node_t *trav = head;
    
    while (i < k && trav != NULL)
    {
        trav = trav -> next;
        count++;
    }
    
    if (count < k)
    {
        return head;
    }
    
    trav = head;
    node_t *prev = NULL;
    node_t *nextNode;

    while (i < k && trav != NULL)
    {
        nextNode = trav->next;
        trav -> next = prev;
        prev = trav;
        trav = nextNode;
        i++;
    }

    if (trav != NULL) {

        head->next = reverseInKGroups(trav, k);
    }

    return prev;
} 

void printLinkedList(node_t *head)
{
    node_t *temporary = head;

    while (temporary != NULL)
    {
        printf("%d\n", temporary->x);
        temporary = temporary->next;
    }
}
int main() {
    node_t* head = NULL;

    for (int i = 1; i <= 8; i++) {
        insertAtEnd(&head, i);
    }

    printf("Original list:\n");
    printLinkedList(head);

    int k = 3; 
    printf("\nReversing in groups of %d:\n", k);
    head = reverseInKGroups(head, k);
    printLinkedList(head);

    node_t* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
    