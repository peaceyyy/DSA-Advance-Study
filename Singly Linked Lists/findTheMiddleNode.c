#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int x;
    struct Node* next;
} node_t;

void insertAtEnd(node_t** head, int val){
   
    node_t* new_node = malloc(sizeof(node_t));

    if (new_node == NULL){

      fprintf(stderr, "Memory Allocation Failed!");
    }
  
    new_node->x = val;
    new_node->next = NULL;
   
 
    node_t* trav = *head;
   
    while (trav -> next != NULL){
        trav = trav -> next;
    }
   
    trav -> next = new_node;
   
}

void insertAtBeginning(node_t** head, int val){
   
    node_t* new_node = malloc(sizeof(node_t));

    if (new_node == NULL){

      fprintf(stderr, "Memory Allocation Failed!");
    }

  
    new_node->x = val;
    new_node->next = *head;
    *head = new_node;
   
}

int numOfNodes(node_t* Node){
  
    if (Node == NULL){
        return 0;
    }
   
    return 1 + numOfNodes(Node->next);
}

node_t* findMiddleNode(node_t** head){
   
    int nodeCount = numOfNodes(*head)/2, i = 0;  
    node_t* trav = *head;
   
    while (i < nodeCount){
       
        trav = trav -> next;
        i++;
    }
   
    return trav;
}

int main(){

    node_t* head = malloc(sizeof(node_t));
    head->x = 9;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 11);
    insertAtEnd(&head, 12);
    insertAtEnd(&head, 13);
    insertAtBeginning(&head, 14);
 
    for(node_t* trav = head; trav != NULL; trav = trav -> next) printf("%d\n", trav->x);
   
    node_t* middleNode = findMiddleNode(&head);
    printf("Middle node is at %p with the value of %d", middleNode, middleNode->x);

    return 0;
}
