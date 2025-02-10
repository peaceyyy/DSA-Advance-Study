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

    if (q->rear == NULL) {  // If queue is empty
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) {  // Edge case: empty queue
        fprintf(stderr, "Queue is empty. Cannot dequeue.\n");
        exit(1);
    }

    QueueNode* temp = q->front;
    int val = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {  // If queue becomes empty, update rear
        q->rear = NULL;
    }

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
    return NULL;  // Stack starts empty
}

void push(StackNode** top, int val) {
    StackNode* newNode = malloc(sizeof(StackNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = val;
    newNode->next = *top;  // Point new node to old top
    *top = newNode;        // Update top to new node
}

int pop(StackNode** top) {
    if (*top == NULL) {  // Edge case: empty stack
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

// -------------------- FUNCTION TO REVERSE QUEUE --------------------

void reverseQueue(Queue* q) {
    StackNode* stack = createStack();

    // Step 1: Move all elements from queue to stack
    while (!isQueueEmpty(q)) {
        push(&stack, dequeue(q));  // Dequeue from queue, push onto stack
    }

    // Step 2: Move all elements back from stack to queue (this reverses the order)
    while (!isStackEmpty(stack)) {
        enqueue(q, pop(&stack));  // Pop from stack, enqueue back to queue
    }
}

// -------------------- MAIN FUNCTION --------------------

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