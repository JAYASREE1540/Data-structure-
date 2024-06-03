#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Graph implementation
struct Graph {
    int V;
    int** adjMatrix;
};

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++)
        graph->adjMatrix[i] = (int*)malloc(V * sizeof(int));
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // If the graph is undirected
}

// Function for Depth First Search traversal of the graph
void DFSUtil(struct Graph* graph, int currentVertex, bool* visited) {
    visited[currentVertex] = true;
    printf("%d ", currentVertex);

    for (int i = 0; i < graph->V; i++) {
        if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i])
            DFSUtil(graph, i, visited);
    }
}

void DFS(struct Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;

    DFSUtil(graph, startVertex, visited);

    free(visited);
}

int main() {
    int V = 6; // Number of vertices in the graph
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("Depth First Traversal starting from vertex 0: ");
    DFS(graph, 0);
    printf("\n");

    return 0;
}

