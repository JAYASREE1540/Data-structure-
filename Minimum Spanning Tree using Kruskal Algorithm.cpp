#include <stdio.h>
#include <stdlib.h>

#define V 5
#define INF 99999

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to create a graph with V vertices
struct Edge* createGraph() {
    // Allocate memory for graph
    struct Edge* edge = (struct Edge*)malloc(V * sizeof(struct Edge));
    return edge;
}

// A utility function to find the subset of an element i
int find(struct Subset subsets[], int i) {
    // Find root and make root as parent of i
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// A function that does union of two sets of x and y
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        // If ranks are the same, then make one as root and increment its rank by one
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights
int compare(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight - b1->weight;
}

// Function to construct MST using Kruskal's algorithm
void KruskalMST(struct Edge* edge) {
    struct Edge result[V]; // Store the resultant MST
    int e = 0; // An index variable, used for result[]

    int i = 0; // An index variable, used for sorted edges
    qsort(edge, V, sizeof(edge[0]), compare); // Sort all the edges in non-decreasing order of their weight

    // Allocate memory for creating V subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Create V subsets with single elements
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1) {
        // Pick the smallest edge. Increment the index for next iteration
        struct Edge next_edge = edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does't cause cycle, include it in result and increment the index
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the constructed MST
    printf("Edges in MST:\n");
    for (int i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    struct Edge* edge = createGraph();

    // Example graph represented as an array of edges
    edge[0].src = 0;
    edge[0].dest = 1;
    edge[0].weight = 10;

    edge[1].src = 0;
    edge[1].dest = 2;
    edge[1].weight = 6;

    edge[2].src = 0;
    edge[2].dest = 3;
    edge[2].weight = 5;

    edge[3].src = 1;
    edge[3].dest = 3;
    edge[3].weight = 15;

    edge[4].src = 2;
    edge[4].dest = 3;
    edge[4].weight = 4;

    // Function call to construct MST
    KruskalMST(edge);

    return 0;
}

