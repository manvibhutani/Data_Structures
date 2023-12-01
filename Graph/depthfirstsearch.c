#include<stdio.h>
#include<stdlib.h>
#define max 20
int visited[max+1], parent[max+1];
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
    for(int i=1; i<=ver; i++)
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
    for (int v = 1; v <= graph->V; ++v) {
        struct Node* current = graph->adj[v];
        printf("Adjacency list of vertex %d: ", v);
        while (current) {
            printf("%d -> ", current->val);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void DFS(struct Graph* graph)
{
for(int i=1; i<=graph->V; i++)
{
    visited[i]=0;
    parent[i]=-1;
    
}
for(int i=1; i<=graph->V; i++)
    {
        if(visited[i]==0)
        {
            DFS_visit(graph,i);
        }
    }
}
void DFS_visit(struct Graph* graph, int i)
{
    struct Node* temp;
    visited[i]=1;
    int adjv;
    printf("\nvisited=%d\n",i);
    temp=graph->adj[i];
    while(temp!=NULL)
    {
        adjv=temp->val;
        if(visited[adjv]==0)
        {
            //parent[adjv]=i;
            DFS_visit(graph,adjv);
        }
        temp=temp->next;
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
    int V = 7; // Number of vertices
    struct Graph* graph = createGraph(V);

    // Add edges to the graph
   addEdge(graph, 1, 5);
    addEdge(graph, 1,6);
    addEdge(graph, 2,1);
    addEdge(graph, 2,7);
    addEdge(graph, 3,2);
    addEdge(graph, 3,4);
    addEdge(graph, 4,5);
    addEdge(graph, 5,6);
   
  
    // Print the graph
    printGraph(graph);
    printf("DFS Traversal:\n");
DFS(graph);

    // Free the memory
    freeGraph(graph);

    return 0;
}







