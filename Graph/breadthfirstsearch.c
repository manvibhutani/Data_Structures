//Manvi,12213106
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 20

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

int visited[max + 1];
struct Queue* createQueue(int capacity);
bool isEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, int item);
int dequeue(struct Queue* queue);

struct Node* createNode(int n) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->val = n;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int ver) {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->V = ver;
    g->adj = (struct Node**)malloc(ver * sizeof(struct Node*));
    for (int i = 1; i <= ver; i++) {
        g->adj[i] = NULL;
    }
    return g;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;

    // For undirected, do the same but from dest to src
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

void BFS(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue(max);
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("Visited = %d\n", currentVertex);

        struct Node* temp = graph->adj[currentVertex];
        while (temp) {
            int adjVertex = temp->val;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
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
    int V = 8; 
    struct Graph* graph = createGraph(V);

   
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4,8);
    addEdge(graph, 8,7);
    addEdge(graph, 7,3);
    addEdge(graph, 7,6);
    addEdge(graph, 6,2);
    addEdge(graph, 6,5);
    addEdge(graph, 5,1);
  

    
    printGraph(graph);
    printf("BFS Traversal:\n");
    BFS(graph, 1);

    
    freeGraph(graph);

    return 0;
}

struct Queue* createQueue(int capacity) {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->array = malloc(capacity * sizeof(int));
    return queue;
}

bool isEmpty(struct Queue* queue) {
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
    if (isEmpty(queue)) {
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

