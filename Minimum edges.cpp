#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    graph->numVertices = numVertices;

    // Allocate memory for adjacency lists
    graph->adjLists = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    if (graph->adjLists == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initialize each adjacency list as empty
    for (int i = 0; i < numVertices; ++i) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since it's an undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        struct Node* temp = graph->adjLists[i];
        printf("Adjacency list of vertex %d\n", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to free memory allocated for the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
    free(graph);
}

int main() {
    int numVertices = 5;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    freeGraph(graph);

    return 0;
}
