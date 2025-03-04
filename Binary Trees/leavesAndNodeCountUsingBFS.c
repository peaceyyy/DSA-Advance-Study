
#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

int leavesCountUsingBFS(TreeNode* root) {
    if (root == NULL) return 0;

    TreeNode* process_queue[100];
    size_t front = 0;
    size_t rear = 0;
    int leavesCount = 0;

    process_queue[rear++] = root;

    while (front < rear) {
        TreeNode* current = process_queue[front++];
        
    
        if (current->left == NULL && current->right == NULL) {
            leavesCount++;
        }

        if (current->left != NULL) {
            process_queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            process_queue[rear++] = current->right;
        }
    }

    return leavesCount;
}

int totalNodeCountUsingBFS(TreeNode* root) {
    if (root == NULL) return 0;

    TreeNode* process_queue[100];
    size_t front = 0;
    size_t rear = 0;
    int leavesCount = 0;

    process_queue[rear++] = root;

    while (front < rear) {
        TreeNode* current = process_queue[front++];
        leavesCount++;
        

        if (current->left != NULL) {
            process_queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            process_queue[rear++] = current->right;
        }
    }

    return leavesCount;
}

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    int leafCount = leavesCountUsingBFS(root);
    printf("\nNumber of leaf nodes: %d\n", leafCount);
    int totalNodesCount = totalNodeCountUsingBFS(root);
    printf("Number of total nodes: %d\n", totalNodesCount);

    free(root->left->left);
    free(root->left->right);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}