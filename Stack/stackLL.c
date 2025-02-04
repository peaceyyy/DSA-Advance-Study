#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node 
{
    int val;
    struct Node* next;
} node_t;

node_t* stackTop = NULL;

bool isEmpty ()
{
    return stackTop == NULL;
}

void push (int x)
{
    node_t* newNode = malloc(sizeof(node_t));

    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    newNode->val = x;
    newNode->next = stackTop;
    stackTop = newNode;
}

int pop ()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return -1;
    }

    int x = stackTop->val;
    node_t* temp = stackTop;
    stackTop = stackTop->next;
    free(temp);

    return x;
}

int peek ()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return -1;
    }

    return stackTop->val;
}

void displayStack ()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }

    node_t* trav = stackTop;
    while (trav != NULL)
    {
        printf("%d ", trav->val);
        trav = trav->next;
    }
    printf("\n");
}

int stackCount ()
{
    int count = 0;
    node_t* trav = stackTop;

    while (trav != NULL)
    {
        count++;
        trav = trav->next;
    }

    return count;
}

int main() {
    printf("Testing Stack Implementation (Linked List)...\n");

    // Pushing elements onto the stack
    push(10);
    push(20);
    push(30);

    // Display the stack
    printf("Stack after pushes: ");
    displayStack();

    // Peek at the top element
    printf("Top element: %d\n", peek());

    // Pop an element
    printf("Popped element: %d\n", pop());

    // Display the stack after pop
    printf("Stack after popping: ");
    displayStack();

    // Count elements in the stack
    printf("Stack count: %d\n", stackCount());

    // Empty the stack
    while (!isEmpty()) {
        pop();
    }

    // Check if the stack is empty
    printf("Stack empty? %s\n", isEmpty() ? "Yes" : "No");

    return 0;
}