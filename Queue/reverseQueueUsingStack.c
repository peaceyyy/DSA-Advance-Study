
#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Stack structure
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;


Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    
    if (!q) {
        fprintf(stderr, "Memory allocation for queue failed.\n");
        exit(1);
    }

    q->front = NULL; 
    q->rear = NULL;
    
    return q;
}


void enqueue(Queue* q, int val){

    QueueNode* newNode = malloc(sizeof(QueueNode));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    
    if (q->front == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }
    
    q->rear->next = newNode;
    q->rear = newNode;

}

int dequeue(Queue* q)
{
    QueueNode* temp = q -> front;
    int val = q -> front -> data;
    
    q -> front = q -> front -> next;
    free(temp);
    
    return val;
}

void displayQueue(Queue* q)
{
    
    QueueNode* trav = q -> front;
    
    while (trav != NULL)
    {
        printf("%d ", trav -> data);
        trav = trav -> next;
    }
}


StackNode* createStack()
{
    StackNode* top = NULL;
    top -> next = NULL;
    
    return top;
}

void push(StackNode** top, int val){

    StackNode* newNode = malloc(sizeof(StackNode));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(2);
    }
    
    newNode->data = val;
    newNode->next = NULL;
    
    if (*top == NULL) 
    {
        *top = newNode;
    }
    
    newNode -> next = *top;
    
    
    
    

    
    
    
    
}


int pop(StackNode** top);

// Function to reverse a queue using a stack
void reverseQueue(Queue* q) {
    // TODO: Implement the function using a stack
}

int main() {
    Queue* q = createQueue();
    
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    printf("Original Queue: ");
    displayQueue(q);

    reverseQueue(q);

    printf("\nReversed Queue: ");
    displayQueue(q);

    return 0;
}
