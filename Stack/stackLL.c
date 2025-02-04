#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node 
{
    int val;
    struct Node* next;
    
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
        return;
    }
    
    newNode -> next = stackTop;
    newNode -> val = x;
    stackTop = newNode;

    
}

int pop ()
{
    if (isEmpty(stackTop))
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

int peek ()
{
    if (isEmpty(stackTop))
    {
        printf("Stack is empty");
        return -1;
    }
    
    
    int x = stackTop -> val;
    return x;
 
}

void displayStack ()
{
    if (isEmpty(stackTop))
    {
        printf("Stack is empty");
    }
    
    
    node_t* trav = stackTop;
    
    while (trav != NULL)
    {
        printf("%d ", trav -> val);
        trav = trav -> next;
    }
    
}

int stackCount ()
{
    if (isEmpty(stackTop))
    {
        printf("Stack is empty");
        return -1;
    }
    
    node_t* trav = stackTop;
    
    int nodeCount = 0;
    while (trav -> next != NULL)
    {
        nodeCount++;
        trav = trav -> next;
    }
    
    return nodeCount;
    
}

int main() {
    printf("Testing Stack Implementation (Linked List)...\n");

    // Pushing elements onto the stack
    push(10);
    push(20);
    push(30);

    // Display the stack
    printf("Stack after pushes: ");
    displayStack(stackTop);
    printf("\n");

    // Peek at the top element
    printf("Top element: %d\n", peek(stackTop));

    // Pop an element
    printf("Popped element: %d\n", pop(stackTop));

    // Display the stack after pop
    printf("Stack after popping: ");
    displayStack(stackTop);
    printf("\n");

    // Count elements in the stack
    printf("Stack count: %d\n", stackCount(stackTop));

    // Empty the stack
    while (!isEmpty(stackTop)) {
        pop(stackTop);
    }

    // Check if the stack is empty
    printf("Stack empty? %s\n", isEmpty(stackTop) ? "Yes" : "No");

    return 0;
}
