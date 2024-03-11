#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LEVEL 6

// Define Node structure for skip list
typedef struct Node {
    int key;
    struct Node *forward[MAX_LEVEL + 1];
} Node;

// Define SkipList structure
typedef struct SkipList {
    int level;
    Node *header;
} SkipList;

// Function to create a new node
Node* createNode(int key) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    for (int i = 0; i <= MAX_LEVEL; ++i) {
        newNode->forward[i] = NULL;
    }
    return newNode;
}

// Function to create a new skip list
SkipList* createSkipList() {
    SkipList *skipList = (SkipList *)malloc(sizeof(SkipList));
    skipList->level = 0;
    skipList->header = createNode(INT_MIN);
    return skipList;
}

// Function to generate random level for a new node
int randomLevel() {
    int level = 1;
    while (rand() % 2 == 0 && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

// Function to insert a key into the skip list
void insert(SkipList *skipList, int key) {
    Node *update[MAX_LEVEL + 1];
    Node *current = skipList->header;
    for (int i = skipList->level; i >= 0; --i) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];
    if (current == NULL || current->key != key) {
        int newLevel = randomLevel();
        if (newLevel > skipList->level) {
            for (int i = skipList->level + 1; i <= newLevel; ++i) {
                update[i] = skipList->header;
            }
            skipList->level = newLevel;
        }
        Node *newNode = createNode(key);
        for (int i = 0; i <= newLevel; ++i) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

// Function to search for a key in the skip list
int search(SkipList *skipList, int key) {
    Node *current = skipList->header;
    for (int i = skipList->level; i >= 0; --i) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    return (current != NULL && current->key == key);
}

// Function to display the skip list
void display(SkipList *skipList) {
    printf("Skip List:\n");
    for (int i = 0; i <= skipList->level; ++i) {
        Node *node = skipList->header->forward[i];
        printf("Level %d: ", i);
        while (node != NULL) {
            printf("%d ", node->key);
            node = node->forward[i];
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a new skip list
    SkipList *skipList = createSkipList();

    // Insert keys into the skip list
    insert(skipList, 30);
    insert(skipList, 20);
    insert(skipList, 10);
    insert(skipList, 40);
    insert(skipList, 400);

    // Search for a key in the skip list
    int keyToSearch = 30;
    if (search(skipList, keyToSearch)) {
        printf("Key %d found in the skip list\n", keyToSearch);
    } else {
        printf("Key %d not found in the skip list\n", keyToSearch);
    }

    // Display the skip list
    display(skipList);

    return 0;
}
