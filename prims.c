#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 999999

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

    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Structure to represent a node in the priority queue
struct MinHeapNode {
    int v;
    int key;
};

// Structure to represent the priority queue
struct MinHeap {
    int size;
    int capacity;
    int *pos;
    struct MinHeapNode **array;
};

// Function to create a new Min Heap Node
struct MinHeapNode* newMinHeapNode(int v, int key) {
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->key = key;
    return minHeapNode;
}

// Function to create a Min Heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Function to swap two nodes of Min Heap
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify at given index
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key)
        smallest = right;

    if (smallest != idx) {
        // The nodes to be swapped in min heap
        struct MinHeapNode *smallestNode = minHeap->array[smallest];
        struct MinHeapNode *idxNode = minHeap->array[idx];

        // Swap positions
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        // Swap nodes
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

// Function to check if the given minHeap is empty or not
bool isEmpty(struct MinHeap* minHeap) {
    return minHeap->size == 0;
}

// Function to extract the minimum node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    if (isEmpty(minHeap))
        return NULL;

    struct MinHeapNode* root = minHeap->array[0];

    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

// Function to decrease the key value of a given vertex v
void decreaseKey(struct MinHeap* minHeap, int v, int key) {
    int i = minHeap->pos[v];
    minHeap->array[i]->key = key;

    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key) {
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

// Function to check if a given vertex is in the Min Heap or not
bool isInMinHeap(struct MinHeap *minHeap, int v) {
    if (minHeap->pos[v] < minHeap->size)
        return true;
    return false;
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], struct Graph* graph) {
    printf("Edge   Weight\n");
    int totalWeight = 0;
    for (int i = 1; i < graph->V; ++i) {
        struct AdjListNode* crawl = graph->array[i].head;
        while (crawl != NULL) {
            if (crawl->dest == parent[i]) {
                printf("%d - %d    %d \n", parent[i], i, crawl->weight);
                totalWeight += crawl->weight;
                break;
            }
            crawl = crawl->next;
        }
    }
    printf("Total Weight of MST: %d\n", totalWeight);
}

// Prim's MST algorithm
void primMST(struct Graph* graph) {
    int V = graph->V;
    int parent[V];
    int key[V];
    struct MinHeap* minHeap = createMinHeap(V);

    for (int v = 1; v < V; ++v) {
        parent[v] = -1;
        key[v] = INF;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }

    key[0] = 0;
    minHeap->array[0] = newMinHeapNode(0, key[0]);
    minHeap->pos[0] = 0;
    minHeap->size = V;

    while (!isEmpty(minHeap)) {
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;

        struct AdjListNode* crawl = graph->array[u].head;
        while (crawl != NULL) {
            int v = crawl->dest;

            if (isInMinHeap(minHeap, v) && crawl->weight < key[v]) {
                key[v] = crawl->weight;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
            crawl = crawl->next;
        }
    }

    printMST(parent, graph);
}

int main() {
    int V = 5; // Number of vertices in the graph
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);

    // Print the MST
    primMST(graph);

    return 0;
}
