#include <stdio.h>
#include <stdlib.h>


typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;


typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// -------------------- QUEUE FUNCTIONS --------------------

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

void enqueue(Queue* q, int val) {
    QueueNode* newNode = malloc(sizeof(QueueNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;

    if (q->rear == NULL) { 
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) {  
        q->rear = NULL;
        fprintf(stderr, "Queue is empty. Cannot dequeue.\n");
        exit(1);
    }

    QueueNode* temp = q->front;
    int val = temp->data;

    q->front = q->front->next;

    free(temp);
    return val;
}

void displayQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    QueueNode* trav = q->front;
    while (trav != NULL) {
        printf("%d ", trav->data);
        trav = trav->next;
    }
    printf("\n");
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// -------------------- STACK FUNCTIONS --------------------

StackNode* createStack() {
    return NULL; 
}

void push(StackNode** top, int val) {
    StackNode* newNode = malloc(sizeof(StackNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = val;
    newNode->next = *top;  
    *top = newNode;        
}

int pop(StackNode** top) {
    if (*top == NULL) {  
        fprintf(stderr, "Stack is empty. Cannot pop.\n");
        exit(1);
    }

    StackNode* temp = *top;
    int val = temp->data;

    *top = (*top)->next;
    free(temp);

    return val;
}

int isStackEmpty(StackNode* top) {
    return top == NULL;
}



void reverseQueue(Queue* q) {
    StackNode* stack = createStack();

    // Move all elements from queue to stack
    while (!isQueueEmpty(q)) {
        push(&stack, dequeue(q));  // Dequeue from queue, push onto stack
    }

    // Move all elements back from stack to queue 
    while (!isStackEmpty(stack)) {
        enqueue(q, pop(&stack));  // Pop from stack, enqueue back to queue
    }
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
