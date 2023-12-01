#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    struct Node* next;
};
struct Graph
{
    int V;//No. of vertices
    struct Node** adj; //Array of adjacency list
};


struct Node* createNode(int n)
{
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->val=n;
    newNode->next=NULL;
    return newNode;
}

struct Graph* createGraph(int ver)
{
    struct Graph* g=malloc(sizeof(struct Graph));
    g->V=ver;
    g->adj=(struct Node**)malloc(ver*sizeof(struct Node*));
    for(int i=0; i<ver; i++)
    {
        g->adj[i]=NULL;
    }
    return g;
}
void addEdge(struct Graph* graph, int src, int dest)
{
    struct Node* newNode=createNode(dest);
    newNode->next=graph->adj[src];
    graph->adj[src]=newNode;

    //For undirected, do the same but from dest to src

}
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct Node* current = graph->adj[v];
        printf("Adjacency list of vertex %d: ", v);
        while (current) {
            printf("%d -> ", current->val);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct Node* current = graph->adj[v];
        while (current) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adj);
    free(graph);
}
int main() {
    int V = 5; // Number of vertices
    struct Graph* graph = createGraph(V);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    // Print the graph
    printGraph(graph);

    // Free the memory
    freeGraph(graph);

    return 0;
}







