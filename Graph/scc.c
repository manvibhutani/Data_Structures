#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 20
int visited[max + 1], parent[max + 1];

struct Node {
    int val;
    struct Node* next;
};

struct Graph {
    int V;             // No. of vertices
    struct Node** adj; // Array of adjacency lists
};

struct Queue {
    int front, rear;
    int* array;
};

struct Stack {
    int top;
    int items[max];
};


void push(struct Stack* S, int n);
int pop(struct Stack* s);

void BFS(struct Graph* graph, int startVertex);
void DFS(struct Graph* graph);
void DFS_visit(struct Graph* graph, int i);
void TopologicalSorting(struct Graph* g, int* a);
void SCC(struct Graph* g, int* a);
void freeGraph(struct Graph* graph);

struct Queue* createQueue(int capacity);
bool isQueueEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, int item);
int dequeue(struct Queue* queue);
struct Node* createNode(int n);
struct Graph* createGraph(int ver);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
void Topol(struct Graph* g, struct Stack* s, int v);

int main() {
    int V = 8; 
    struct Graph* graph = createGraph(V);

 
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 7);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 3);
    addEdge(graph, 4, 8);
    addEdge(graph, 5, 1);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 6);
    addEdge(graph, 7, 8);

    printGraph(graph);

    int* a = malloc(sizeof(int) * (max + 1));
    struct Graph* gT = createGraph(V);
    TopologicalSorting(graph, a);
    printf("\n");
    addEdge(gT, 2,1);
    addEdge(gT, 5,2);
    addEdge(gT, 6,2);
    addEdge(gT, 3,2);
    addEdge(gT, 7,3);
    addEdge(gT, 4,3);
    addEdge(gT, 3,4);
    addEdge(gT, 8,4);
    addEdge(gT, 1,5);
    addEdge(gT, 6,5);
    addEdge(gT, 7,6);
    addEdge(gT, 6,7);
    addEdge(gT, 8,7);
    SCC(gT, a);


    // Free the memory
    freeGraph(graph);
    freeGraph(gT);
    free(a);

    return 0;
}

struct Queue* createQueue(int capacity) {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->array = malloc(capacity * sizeof(int));
    return queue;
}

bool isQueueEmpty(struct Queue* queue) {
    return queue->front == -1;
}

void enqueue(struct Queue* queue, int item) {
    if (queue->rear == max - 1) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = item;
}

int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return item;
}

struct Node* createNode(int n) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->val = n;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int ver) {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->V = ver;
    g->adj = (struct Node**)malloc((ver + 1) * sizeof(struct Node*));
    for (int i = 1; i <= ver; i++) {
        g->adj[i] = NULL;
    }
    return g;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
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

void Topol(struct Graph* g, struct Stack* s, int v) {
    visited[v] = 1;
    struct Node* temp;
    temp = g->adj[v];
    while (temp) {
        if (!visited[temp->val]) {
            Topol(g, s, temp->val);
        }
        temp = temp->next;
    }
    push(s, v);
}

void TopologicalSorting(struct Graph* g, int* a) {
    struct Stack* s = malloc(sizeof(struct Stack));
    s->top = -1;

    for (int i = 0; i <= max; i++) {
        visited[i] = 0;
    }

    for (int i = 1; i <= g->V; i++) {
        if (visited[i] == 0) {
            Topol(g, s, i);
        }
    }
    int k = 0;
    while (!isStackEmpty(s)) {
        a[k] = s->items[s->top];
        k++;
        printf("%d ", s->items[s->top]);
        pop(s);
    }
    free(s);
}

int isStackEmpty(struct Stack* s) {
    return s->top == -1;
}

int pop(struct Stack* s) {
    if (isStackEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

void push(struct Stack* S, int n) {
    S->items[++S->top] = n;
}

void DFS(struct Graph* graph) {
    for (int i = 1; i <= graph->V; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }
    for (int i = 1; i <= graph->V; i++) {
        if (visited[i] == 0) {
            DFS_visit(graph, i);
        }
    }
}

void DFS_visit(struct Graph* graph, int i) {
    struct Node* temp;
    visited[i] = 1;
    int adjv;
    printf("%d ",i);
    temp = graph->adj[i];
    while (temp != NULL) {
        adjv = temp->val;
        if (visited[adjv] == 0) {
            parent[adjv] = i;
            DFS_visit(graph, adjv);
        }
        temp = temp->next;
    }
}

void SCC(struct Graph* g, int* a) {
    for(int i=0; i<max+1; i++)
    {
        visited[i]=0;
        parent[i]=-1;
    }
    for (int i = 0; i < g->V; i++) {
        if (visited[a[i]] == 0) {
            DFS_visit(g, a[i]);
            printf("\n");
        }
    }
}

void freeGraph(struct Graph* graph) {
    for (int v = 1; v <= graph->V; ++v) {
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
