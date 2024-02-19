#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// Structure to represent a subset for union-find
struct subset {
    int parent;
    int rank;
};

// Function prototypes
struct Graph* createGraph(int V, int E);
int find(struct subset subsets[], int i);
void Union(struct subset subsets[], int x, int y);
void findConnectedComponents(struct Graph* graph);

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// A utility function to find the subset of an element i
int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// A utility function to do union of two subsets
void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Finds connected components of an undirected graph
void findConnectedComponents(struct Graph* graph) {
    int V = graph->V;
    struct Edge* edge = graph->edge;

    // Allocate memory for creating V subsets
    struct subset* subsets = (struct subset*)malloc(V * sizeof(struct subset));

    // Initialize all subsets as single element sets
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Iterate through all edges, union the sets together
    for (int e = 0; e < graph->E; ++e) {
        int x = find(subsets, edge[e].src);
        int y = find(subsets, edge[e].dest);
        if (x != y)
            Union(subsets, x, y);
    }

    // Print connected components
    printf("Connected components:\n");
    for (int v = 0; v < V; ++v) {
        if (subsets[v].parent == v)
            printf("%d ", v);
    }
    printf("\n");

    free(subsets);
}

int main() {
    int V = 5; // Number of vertices
    int E = 4; // Number of edges
    struct Graph* graph = createGraph(V, E);

    // Edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    // Edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    // Edge 3-4
    graph->edge[2].src = 3;
    graph->edge[2].dest = 4;

    // Edge 2-3
    graph->edge[3].src = 2;
    graph->edge[3].dest = 3;

    findConnectedComponents(graph);

    free(graph->edge);
    free(graph);

    return 0;
}
