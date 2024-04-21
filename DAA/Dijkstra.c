#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent a node in the graph
struct Node {
    int vertex;
    int weight;
};

// Structure to represent the adjacency list node
struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
};

// Structure to represent the adjacency list for each vertex
struct AdjList {
    struct AdjListNode *head;
};

// Structure to represent the graph
struct Graph {
    int V;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // For undirected graph, add an edge from dest to src as well
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to print the shortest distances from the source vertex
void printShortestPaths(int dist[], int n) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

// Function to find the vertex with minimum distance value
int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to perform Dijkstra's algorithm
void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in the shortest path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        // u is always equal to src in the first iteration
        int u = minDistance(dist, sptSet, V);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;

            // Update dist[v] only if is not in sptSet, there is an edge from u to v, and the total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && pCrawl->weight && dist[u] != INT_MAX && dist[u] + pCrawl->weight < dist[v])
                dist[v] = dist[u] + pCrawl->weight;

            pCrawl = pCrawl->next;
        }
    }

    // Print the shortest distances from the source vertex
    printShortestPaths(dist, V);
}

// Function to read graph from file and construct the graph
struct Graph* readGraphFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    int V, E;
    fscanf(file, "%d %d", &V, &E);

    struct Graph* graph = createGraph(V);

    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        fscanf(file, "%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    fclose(file);

    return graph;
}

int main() {
    const char* filename = "graph.txt";
    struct Graph* graph = readGraphFromFile(filename);

    // Print the graph (optional)
    printf("Graph read from file:\n");
    for (int i = 0; i < graph->V; ++i) {
        struct AdjListNode* pCrawl = graph->array[i].head;
        while (pCrawl != NULL) {
            printf("%d -> %d, Weight: %d\n", i, pCrawl->dest, pCrawl->weight);
            pCrawl = pCrawl->next;
        }
    }

    // Apply Dijkstra's algorithm to find shortest paths
    int source_vertex = 0; // Change this to the desired source vertex
    printf("Shortest paths from source vertex %d:\n", source_vertex);
    dijkstra(graph, source_vertex);

    return 0;
}
