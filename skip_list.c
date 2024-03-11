#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_LEVEL 6

// Define Node structure for skip list
typedef struct Node {
    int key;
    int value;
    struct Node *forward[MAX_LEVEL + 1];
} Node;

// Define SkipList structure
typedef struct SkipList {
    int level;
    Node *header;
} SkipList;

// Function to create a new node
Node* createNode(int key, int value, int level) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->forward = (Node **)malloc((level + 1) * sizeof(Node *));
    for (int i = 0; i <= level; ++i) {
        newNode->forward[i] = NULL;
    }
    return newNode;
}

// Function to create a new skip list
SkipList* createSkipList() {
    SkipList *skipList = (SkipList *)malloc(sizeof(SkipList));
    skipList->level = 0;
    skipList->header = createNode(INT_MIN, INT_MIN, MAX_LEVEL);
    for (int i = 0; i <= MAX_LEVEL; ++i) {
        skipList->header->forward[i] = NULL;
    }
    return skipList;
}

// Function to generate random level for a new node
int randomLevel() {
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

// Function to insert a key-value pair into the skip list
void insert(SkipList *skipList, int key, int value) {
    // Array to store update pointers
    Node *update[MAX_LEVEL + 1];
    Node *current = skipList->header;
    
    // Traverse the skip list to find the position to insert
    for (int i = skipList->level; i >= 0; --i) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    
    current = current->forward[0];
    
    // Check if key already exists, if not, insert the new node
    if (current == NULL || current->key != key) {
        int newLevel = randomLevel();
        
        if (newLevel > skipList->level) {
            for (int i = skipList->level + 1; i <= newLevel; ++i) {
                update[i] = skipList->header;
            }
            skipList->level = newLevel;
        }
        
        Node *newNode = createNode(key, value, newLevel);
        
        for (int i = 0; i <= newLevel; ++i) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

// Function to search for a key in the skip list
bool search(SkipList *skipList, int key) {
    Node *current = skipList->header;
    
    for (int i = skipList->level; i >= 0; --i) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
    }
    
    current = current->forward[0];
    
    return current != NULL && current->key == key;
}

// Function to display the skip list
void display(SkipList *skipList) {
    printf("Skip List:\n");
    for (int i = 0; i <= skipList->level; ++i) {
        Node *node = skipList->header->forward[i];
        printf("Level %d: ", i);
        while (node != NULL) {
            printf("(%d,%d) ", node->key, node->value);
            node = node->forward[i];
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new skip list
    SkipList *skipList = createSkipList();
    int choice, key, value;
    
    // Interactive menu loop
    while (true) {
        // Display menu options
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Insert key-value pair into the skip list
                printf("Enter key and value to insert: ");
                scanf("%d %d", &key, &value);
                insert(skipList, key, value);
                break;
            case 2:
                // Search for a key in the skip list
                printf("Enter key to search: ");
                scanf("%d", &key);
                printf("%s\n", search(skipList, key) ? "Found" : "Not Found");
                break;
            case 3:
                // Display the skip list
                display(skipList);
                break;
            case 4:
                // Exit the program
                printf("Exiting...\n");
                return 0;
            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    }
}
