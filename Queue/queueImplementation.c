#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* dataArray;
    int queueSize;
    int front;
    int rear;
} Queue;

void initializeQueue(Queue* q, int size) {
    q->queueSize = size;
    q->dataArray = (int*) malloc(sizeof(int) * size);
    q->front = 0;
    q->rear = 0;
}

bool isFull(Queue* q) {
    if (q->rear == q->queueSize) {
        printf("Queue is full\n");
        return true;
    }
    return false;
}

bool isEmpty(Queue* q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return true;
    }
    return false;
}

void enqueue(Queue* q, int val) {
    if (isFull(q)) {
        return;
    }
    q->dataArray[q->rear++] = val;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        return -1000;
    }
    int value = q->dataArray[q->front++];
    if (q->front == q->rear) {
        q->front = 0;
        q->rear = 0;
    }
    return value;
}

int main() {
    Queue q1;
    initializeQueue(&q1, 5);
    enqueue(&q1, 3);
    enqueue(&q1, 4);
    enqueue(&q1, 5);
    enqueue(&q1, 6);
    enqueue(&q1, 7);
    dequeue(&q1);

    for (int i = q1.front; i < q1.rear; i++) {
        printf("%d\n", q1.dataArray[i]);
    }

    free(q1.dataArray); // Free allocated memory

    return 0;
}