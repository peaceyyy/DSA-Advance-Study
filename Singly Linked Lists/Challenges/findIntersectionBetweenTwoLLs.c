#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} node_t;

// Function prototype for intersection detection function
bool detectIntersection(node_t* headA, node_t* headB) {
    node_t* travA = headA;
    node_t* travB = headB;

    while (travA != travB) {  // Compare the node addresses, not values
        travA = (travA == NULL) ? headB : travA->next;
        travB = (travB == NULL) ? headA : travB->next;
    }

    return travA != NULL;
}

node_t* createNode(int data) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Test cases
void testIntersectionDetection() {
    // Test Case 1: No Intersection
    node_t* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(3);

    node_t* list2 = createNode(4);
    list2->next = createNode(5);
    list2->next->next = createNode(6);

    printf("Test Case 1 (No Intersection): %s\n",
           detectIntersection(list1, list2) ? "True" : "False");

    // Test Case 2: Intersection at node 3
    node_t* list3 = createNode(1);
    list3->next = createNode(2);
    node_t* commonNode = createNode(3);
    list3->next->next = commonNode;
    commonNode->next = createNode(4);
    commonNode->next->next = createNode(5);

    node_t* list4 = createNode(9);
    list4->next = commonNode; // Intersection happens here

    printf("Test Case 2 (Intersection at node 3): %s\n",
           detectIntersection(list3, list4) ? "True" : "False");

    // Free allocated memory
    free(list1->next->next);
    free(list1->next);
    free(list1);
    free(list2->next->next);
    free(list2->next);
    free(list2);
    free(list3);
    free(list4);
    free(commonNode->next->next);
    free(commonNode->next);
    free(commonNode);
}

// Run the tests
int main() {
    testIntersectionDetection();
    return 0;
}