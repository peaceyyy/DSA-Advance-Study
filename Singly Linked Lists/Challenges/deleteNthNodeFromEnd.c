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

int nodeCount (node_t* node)
{
    if (node == NULL)
    {
        return 0;
    }
    
    
    return (1 + nodeCount(node -> next));


}

node_t *removeNthNodeFromEnd(node_t *head, int n) {
    if (head == NULL || n == 0) {
        return head;
    }

    int totalNodes = nodeCount(head);
    if (n > totalNodes) {
        return head;  // If n is invalid, return head as is
    }

    // Special case: Remove head
    if (n == totalNodes) {
        node_t *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Find (totalNodes - n)th node (one before the target)
    node_t *trav = head;
    for (int i = 0; i < totalNodes - n - 1; i++) {
        trav = trav->next;
    }

    // Remove nth node from end
    node_t *toDelete = trav->next;
    trav->next = toDelete->next;
    free(toDelete);

    return head;
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

int main() 
{
    node_t* head = NULL;

    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original List:\n");
    printLinkedList(head);
    
    // Remove 2nd node from end (should remove 4)
    head = removeNthNodeFromEnd(head, 1);

    printf("After Removing 2nd Node from End:\n");
    printLinkedList(head);
    
    return 0;
}

