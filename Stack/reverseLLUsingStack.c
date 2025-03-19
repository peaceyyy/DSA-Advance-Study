#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} *Node;


Node createNode(int val)
{
    Node new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation for node failed");
        exit(0);
    }

    new_node->data = val;
    new_node->next = NULL;

    return new_node;
}

void insertNodeAtBeginning (Node* head, int val)
{
    Node new_node = createNode(val);

    if (head == NULL)
    {
        *head = new_node;
        return;
    }
    
    new_node->next = *head;
    *head = new_node;
}



void insertNodeAtEnd (Node* head, int val)
{
    Node new_node = createNode(val);

    if (head == NULL)
    {
        *head = new_node;
        return;
    }

    Node trav = *head;

    while (trav->next != NULL)
    {
        trav = trav -> next;
    }

    trav -> next = new_node;

    
}

void insertNodeAtindex (Node* head, int index, int val)
{
    Node new_node = createNode(val);

    if (head == NULL)
    {
        *head = new_node;
        return;
    }

    Node trav = *head;
    int i = 0;

    while (i < index || trav->next != NULL)
    {
        trav = trav -> next;
        i++;
    }

    new_node -> next = trav -> next -> next;
    trav -> next = new_node;

    
}

int search (Node* head, int val)
{
    
    Node trav = *head;
    int i = 0;

    while (trav->next != NULL)
    {
        if (trav -> data = val) 
        {   
            return i;
        }

        i++;
        trav = trav -> next;
        
    }
    
    printf("Value not in LL");
    return -1;
}

void printLinkedList (Node head)
{
    Node trav = head;

    while (trav != NULL)
    {
        printf("%d ", trav->data);
        trav = trav -> next;
    }
}

void freeLinkedList (Node head)
{
    Node trav = head;

    while (trav != NULL)
    {   
        Node temp = trav;
        trav = trav -> next;
        free(temp);
    }

     free(trav);
}


//Stack 

typedef struct {
    Node* nodeArr;
    int stackCapacity;
    int nodeCount;
}* NodeStack;

NodeStack createNodeStack (int size)
{
    NodeStack nodeStack = malloc(sizeof(NodeStack));
    nodeStack->nodeArr = malloc(sizeof(Node) * size);
    nodeStack->stackCapacity = size;
    nodeStack->nodeCount = 0;

    return nodeStack;
    
}  

bool isStackFull (NodeStack NS)
{
    if (NS->nodeCount == NS->stackCapacity) return true;

    return false;
}

bool isStackEmpty (NodeStack NS)
{
    if (NS->nodeCount != 0) return true;

    return false;
}


void push (NodeStack NS, Node node)
{   
    if (isStackFull(NS))
    {
        fprintf(stderr, "Stack is full!");
        return;
    }
    NS->nodeArr[NS->nodeCount++] = node;
}

Node pop (NodeStack NS)
{   
    if (isStackEmpty(NS))
    {
        fprintf(stderr, "Stack is empty!");
        return NULL;
    }

    return NS->nodeArr[--NS->nodeCount];
}

void pushNodesToStack (NodeStack NS, Node* head)
{
    Node trav = *head;

    while (trav != NULL)
    {
        push(NS, trav);
        trav = trav -> next;
    }
}

void printReversedLL (NodeStack NS)
{
    for (int i = NS -> nodeCount - 1; i >= 0; i--)
    {
        printf("%d ", NS->nodeArr[i]->data);
    }
}





int main()
{
    Node head = createNode(10);
    insertNodeAtEnd(&head, 20);
    insertNodeAtEnd(&head, 30);
    insertNodeAtBeginning(&head, 100);

    printf("\n\n\n");
    printLinkedList(head);
    printf("\n\n\n");

    NodeStack NS1 = createNodeStack(4);
    pushNodesToStack(NS1, &head);   
    printReversedLL(NS1);


    freeLinkedList(head);  


    

    return 0;
    
}   