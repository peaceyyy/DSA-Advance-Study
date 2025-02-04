#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef Node 
{
    
    int val;
    struct node_t* next;
    
} node_t;


node_t* stackTop = NULL;

bool isEmpty (node_t* stackTop)
{
    if (stackTop == NULL)
    {
        return true;
    }
    
    return false;
}


void push (int x)
{
    
    node_t* newNode = malloc(sizeof(node_t));
    
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed.");
    }
    
    newNode -> next = stackTop;
    newNode -> val = x;
    stackTop = newNode;

    
}

int pop (node_t* stackTop)
{
    if (isEmpty(stackTop)
    {
        printf("Stack is empty");
        return -1;
    }
    
    int x = stackTop -> val;
    node_t* temp = stackTop;
    stackTop = stackTop -> next;
    free(temp);
    
    return x;
    

}

int peek (node_t* stackTop)
{
    if (isEmpty(stackTop)
    {
        printf("Stack is empty");
        return -1;
    }
    
    
    int x = stackTop -> val;
    return x;
 
}

void displayStack (node_t* stackTop)
{
    if (isEmpty(stackTop)
    {
        printf("Stack is empty");
        return -1;
    }
    
    
    node_t* trav = stackTop;
    
    while (trav -> next != NULL)
    {
        printf("%d -> ", trav -> val);
        trav = trav -> next;
    }
    
}

int stackCount (node_t* stackTop)
{
    if (isEmpty(stackTop)
    {
        printf("Stack is empty");
        return -1;
    }
    
    int nodeCount = 0;
    while (trav -> next != NULL)
    {
        count++;
        trav = trav -> next;
    }
    
    return nodeCount;
    
}
