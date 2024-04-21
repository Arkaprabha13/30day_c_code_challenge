#include <stdio.h>
#include <stdlib.h>

// Structure to represent a subset
struct subset {
    int parent;
    int rank;
};

// Function to create a new subset with rank 0
struct subset* makeSet(int parent) {
    struct subset* node = (struct subset*)malloc(sizeof(struct subset));
    node->parent = parent;
    node->rank = 0;
    return node;
}

// Function to find the subset to which an element belongs (with path compression)
int find(struct subset subsets[], int i) {
    // Find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// Function to merge two subsets into a single subset (union by rank)
void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree (Union by Rank)
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

// Function to find connected components in a graph using Union-Find
void findConnectedComponents(int n, int edges[][2], int numEdges) {
    // Create subsets for each vertex
    struct subset* subsets = (struct subset*)malloc(n * sizeof(struct subset));
    for (int i = 0; i < n; ++i) {
        subsets[i] = *makeSet(i);
    }

    // Perform union operations for each edge
    for (int i = 0; i < numEdges; ++i) {
        Union(subsets, edges[i][0], edges[i][1]);
    }

    // Output connected components
    printf("Connected Components:\n");
    for (int i = 0; i < n; ++i) {
        if (subsets[i].parent == i) {
            printf("Component %d: ", i);
            for (int j = 0; j < n; ++j) {
                if (find(subsets, j) == i) {
                    printf("%d ", j);
                }
            }
            printf("\n");
        }
    }

    free(subsets);
}

int main() {
    int n = 6; // Number of vertices
    int edges[][2] = {{0, 1}, {1, 2}, {3, 4}, {4, 5}}; // Edges of the graph
    int numEdges = sizeof(edges) / sizeof(edges[0]); // Number of edges

    findConnectedComponents(n, edges, numEdges);

    return 0;
}
