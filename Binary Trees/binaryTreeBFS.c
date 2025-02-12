#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Define the structure for a queue node
typedef struct QueueNode
{
    TreeNode *treeNode;
    struct QueueNode *next;
} QueueNode;

// Define the structure for the queue
typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

// Function to create a new tree node
TreeNode *createTreeNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new queue node
QueueNode *createQueueNode(TreeNode *treeNode)
{
    QueueNode *newQueueNode = (QueueNode *)malloc(sizeof(QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;
    return newQueueNode;
}

// Function to initialize a queue
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue *queue)
{
    return queue->front == NULL;
}

// Function to enqueue a tree node
void enqueue(Queue *queue, TreeNode *treeNode)
{
    QueueNode *newQueueNode = createQueueNode(treeNode);
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newQueueNode;
        return;
    }
    queue->rear->next = newQueueNode;
    queue->rear = newQueueNode;
}

// Function to dequeue a tree node
TreeNode *dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        return NULL;
    }
    QueueNode *temp = queue->front;
    TreeNode *treeNode = temp->treeNode;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return treeNode;
}

// Function to perform BFS on the binary tree
void breadthFirstSearch(TreeNode *root)
{

    Queue *queue = createQueue();
    enqueue(queue, root);
    

    while (!isQueueEmpty(queue))
    {
        printf("%d ", curr->data);
        TreeNode *curr = dequeue(queue);
        

        if (curr->left != NULL)
        {
            enqueue(queue, curr->left);
        }

        if (curr->right != NULL)
        {
            enqueue(queue, curr->right);
        }


    }
}

// Main function
int main()
{

    TreeNode *root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);

    printf("Breadth-First Search: ");
    breadthFirstSearch(root);

    return 0;
}