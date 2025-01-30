#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{

    int *dataArr;
    int front;
    int rear;
    int count;
    int queueCapacity;

} Deque;

Deque *initializeQueue(int size)
{

    Deque *dq = malloc(sizeof(Deque));

    if (dq != NULL)
    {

        fprintf(stderr, "Memory Allocation for Deque failed");
        exit(1);
    }

    dq->queueCapacity = size;

    dq->dataArr = (int *)malloc(sizeof(int) * dq->queueCapacity);
    dq->front = 0;
    dq->rear = 0;
    dq->count = 0;

    return dq;
}

bool isFull(Deque *dq)
{

    if (dq->count == dq->queueCapacity)
    {
        return true;
    }

    return false;
}

bool isEmpty(Deque *dq)
{

    if (dq->count == 0)
    {
        return true;
    }

    return false;
}

void addFront(Deque *dq, int val)
{

    dq->dataArr[dq->front] = val;
    dq->count++;
    dq->front = (dq->front + 1) % dq->queueCapacity;
}

void addRear(Deque *dq, int val)
{

    dq->dataArr[dq->rear] = val;
    dq->count++;
    dq->front = (dq->rear + 1) % dq->queueCapacity;
}

int dequeueFront(Deque *dq)
{

    int val = dq->dataArr[dq->front];
    dq->count--;
    dq->front++;

    return val;
}

int dequeueRear(Deque *dq)
{

     int val = dq->dataArr[dq->rear];
    dq->count--;
    dq->rear--;

    return val;
}

void freeArr(Deque* dq){

    free(dq->dataArr);
    dq->count = 0;
    dq->front = 0;
    dq->rear = 0;

}

int main()
{
}