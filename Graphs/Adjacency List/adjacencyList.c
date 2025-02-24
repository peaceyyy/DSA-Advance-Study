#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t
{
    int val;
    struct node_t *next;
} node_t;

typedef struct
{
    node_t *head;
} List;

typedef struct
{
    int vertices;
    List **nodeArr;
} Graph;

node_t *createNode(int val)
{
    node_t *newNode = malloc(sizeof(node_t));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed!");
        exit(1);
    }

    newNode->next = NULL;
    newNode->val = val;

    return newNode;
}

Graph *initializeAdjList(int v)
{
    Graph *g = malloc(sizeof(Graph));
    g->vertices = v;
    g->nodeArr = malloc(sizeof(List) * g->vertices);

    for (int i = 0; i < v; i++)
    {
        g->nodeArr[i] = malloc(sizeof(List));
        g->nodeArr[i]->head = NULL;
    }

    return g;
}

int checkForEdge(Graph *g, int sourceVertex, int targetVertex)
{

    if (sourceVertex < 0 || sourceVertex >= g->vertices)
    {
        return 0;
    }

    node_t *trav = g->nodeArr[sourceVertex]->head;

    while (trav != NULL)
    {
        if (trav->val == targetVertex)
        {
            return 1;
        }
        trav = trav->next;
    }

    return 0;
}
void addEdge(Graph *g, int src, int dest, bool isDirected)
{
    if (src < 0 || src >= g->vertices || dest < 0 || dest >= g->vertices)
    {
        printf("Source (%d) or Destination (%d) out of bounds!\n", src, dest);
        return;
    }

    if (checkForEdge(g, src, dest))
    {
        printf("%d and %d are already connected\n", src, dest);
        return;
    }

    node_t *temp = createNode(dest);
    temp->next = g->nodeArr[src]->head;
    g->nodeArr[src]->head = temp;

    if (!isDirected)
    {
        node_t *temp2 = createNode(src);
        temp2->next = g->nodeArr[dest]->head;
        g->nodeArr[dest]->head = temp2;
    }
}

void removeEdge(Graph *g, int src, int dest, bool isDirected)
{
    
    if (src < 0 || src >= g->vertices || dest < 0 || dest >= g->vertices)
    {
        printf("Source (%d) or Destination (%d) out of bounds!\n", src, dest);
        return;
    }

    
    if (!checkForEdge(g, src, dest))
    {
        printf("Vertices are not connected!\n");
        return;
    }

    
    node_t *trav1 = g->nodeArr[src]->head;
    while (trav1 != NULL)
    {
        if (trav1->val == dest)
        {
            node_t *temp = trav1;
            trav1 = trav1->next;
            free(temp);
            break; 
        }
        trav1 = trav1->next;
    }

    
    if (!isDirected)
    {
        node_t *trav2 = g->nodeArr[dest]->head;
        while (trav2 != NULL)
        {
            if ((trav2)->val == src)
            {
                node_t *temp = trav2;
                trav2 = trav2->next;
                free(temp);
                break; 
            }
            trav2 = trav2->next;
        }
    }
}

void printGraph(Graph *g)

{
    if (g == NULL)
    {
        printf("Graph ain't here");
        return;
    }

    for (int i = 0; i < g->vertices; i++)
    {
        printf("Vertex %d: ", i);
        node_t *trav = g->nodeArr[i]->head;
        while (trav != NULL)
        {
            printf("%d -> ", trav->val);
            trav = trav->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(Graph *g)
{
    if (g == NULL) return; 

    for (int i = 0; i < g->vertices; i++)
    {
        if (g->nodeArr[i] != NULL) 
        {
            node_t *trav = g->nodeArr[i]->head;
            while (trav != NULL)
            {
                node_t *temp = trav;
                trav = trav->next;
                free(temp);
            }
            free(g->nodeArr[i]);  
            g->nodeArr[i] = NULL; // Prevent dangling pointer
        }
    }
    free(g->nodeArr); 
    free(g); 

}

void freeList (List* l)
{   
    if (l == NULL) return;

    node_t* trav = l->head;

    while (l != NULL)
    {
        node_t* temp = trav;
        trav = trav -> next;
        free(temp);
    }

    free(l);
}
List *getNodeNeighbors(Graph *g, int node)
{
    if (node < 0 || node >= g->vertices)
    {
        printf("Invalid node index!\n");
        return NULL;
    }
    List *neighborsList = malloc(sizeof(List));

    if (!neighborsList)
    {
        fprintf(stderr,"Memory allocation failed!\n");
        return NULL;
    }

    neighborsList->head = NULL;

    node_t *trav = g->nodeArr[node]->head;
    while (trav != NULL)
    {
        node_t *newNode = createNode(trav->val);
        newNode->next = neighborsList->head;
        neighborsList->head = newNode;
        trav = trav->next;
    }

    return neighborsList;
}

int main()
{
    Graph *g = initializeAdjList(4);

    addEdge(g, 0, 3, false);
    addEdge(g, 2, 1, false);
    addEdge(g, 1, 2, false);
    addEdge(g, 0, 2, false);

    /////// Test get Node Neighbors

    printf("Neighbors of Node 0 are: ");
    List *nodeNeighbors = getNodeNeighbors(g, 0);

    node_t *trav = nodeNeighbors->head;
    while (trav)
    {
        printf("%d -> ", trav->val);
        trav = trav->next;
    }
    printf("NULL\n");

    ///////

    printf("\n");
    printGraph(g);

    freeList(nodeNeighbors); 
    freeGraph(g);

    return 0;
}
