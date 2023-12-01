#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define V 6  // Number of vertices

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph {
    struct Node** adjList;
};

struct Node* createNode(int vertex, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void printShortestPaths(int dist[], int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

void topologicalSortUtil(struct Graph* graph, int v, bool visited[], int stack[], int* top) {
    visited[v] = true;
    struct Node* temp = graph->adjList[v];
    while (temp != NULL) {
        int u = temp->vertex;
        if (!visited[u]) {
            topologicalSortUtil(graph, u, visited, stack, top);
        }
        temp = temp->next;
    }
    stack[(*top)++] = v;
}

void shortestPathDAG(struct Graph* graph, int src) {
    int dist[V];
    int stack[V];
    int top = 0;

    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, &top);
        }
    }

    while (top > 0) {
        int u = stack[--top];
        if (dist[u] != INT_MAX) {
            struct Node* temp = graph->adjList[u];
            while (temp != NULL) {
                int v = temp->vertex;
                if (dist[u] + temp->weight < dist[v]) {
                    dist[v] = dist[u] + temp->weight;
                }
                temp = temp->next;
            }
        }
    }

    printShortestPaths(dist, V);
}

int main() {
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 3);
    addEdge(graph, 1, 3, 6);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 2, 4, 1);
    addEdge(graph, 3, 5, 1);
    addEdge(graph, 4, 5, 2);

    int source = 0;
    shortestPathDAG(graph, source);

    return 0;
}
