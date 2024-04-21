#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX_LEVEL 6 // Maximum level for the skip list

// Node structure for the skip list
typedef struct Node {
    int value;
    struct Node **forward; // Array of pointers to forward nodes
} Node;

// Skip list structure
typedef struct SkipList {
    int level; // Current level of the skip list
    Node *header; // Header node of the skip list
} SkipList;

// Function to create a new node
Node *createNode(int value, int level) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->forward = (Node **)malloc((level + 1) * sizeof(Node *));
    return node;
}

// Function to create a skip list
SkipList *createSkipList() {
    SkipList *skipList = (SkipList *)malloc(sizeof(SkipList));
    skipList->level = 0;
    skipList->header = createNode(INT_MIN, MAX_LEVEL); // Initialize header node with minimum integer value
    for (int i = 0; i <= MAX_LEVEL; i++) {
        skipList->header->forward[i] = NULL; // Initialize all forward pointers of header to NULL
    }
    return skipList;
}

// Function to generate a random level for a new node
int randomLevel() {
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

// Function to insert a value into the skip list
void insert(SkipList *skipList, int value) {
    Node *update[MAX_LEVEL + 1];
    Node *current = skipList->header;

    // Traverse the skip list from top level to bottom level
    for (int i = skipList->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        update[i] = current; // Store the last visited node at each level
    }

    current = current->forward[0]; // Move to the next node at the bottom level

    // If the value already exists, do nothing
    if (current == NULL || current->value != value) {
        int newLevel = randomLevel();
        // If the new level is greater than the current level of the skip list, update the header and update array
        if (newLevel > skipList->level) {
            for (int i = skipList->level + 1; i <= newLevel; i++) {
                update[i] = skipList->header;
            }
            skipList->level = newLevel;
        }

        // Create a new node with the given value and random level
        Node *newNode = createNode(value, newLevel);

        // Update the forward pointers of the new node and the previous nodes in the update array
        for (int i = 0; i <= newLevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

// Function to delete a value from the skip list
void delete(SkipList *skipList, int value) {
    Node *update[MAX_LEVEL + 1];
    Node *current = skipList->header;

    // Traverse the skip list from top level to bottom level
    for (int i = skipList->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        update[i] = current; // Store the last visited node at each level
    }

    current = current->forward[0]; // Move to the next node at the bottom level

    // If the value exists, delete it
    if (current != NULL && current->value == value) {
        // Update the forward pointers of previous nodes to remove the node to be deleted
        for (int i = 0; i <= skipList->level; i++) {
            if (update[i]->forward[i] != current) {
                break;
            }
            update[i]->forward[i] = current->forward[i];
        }

        // Free memory allocated for the node
        free(current);

        // Update the level of the skip list if necessary
        while (skipList->level > 0 && skipList->header->forward[skipList->level] == NULL) {
            skipList->level--;
        }
    }
}

// Function to search for a value in the skip list
Node *search(SkipList *skipList, int value) {
    Node *current = skipList->header;

    // Traverse the skip list from top level to bottom level
    for (int i = skipList->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->value < value) {
            current = current->forward[i];
        }
    }

    // Move to the next node at the bottom level
    current = current->forward[0];

    // If the current node contains the value, return it
    if (current != NULL && current->value == value) {
        return current;
    } else {
        return NULL; // Value not found
    }
}

// Function to print the skip list
void printSkipList(SkipList *skipList) {
    printf("Skip List:\n");
    for (int i = skipList->level; i >= 0; i--) {
        Node *current = skipList->header->forward[i];
        printf("Level %d: ", i);
        while (current != NULL) {
            printf("%d ", current->value);
            current = current->forward[i];
        }
        printf("\n");
    }
}

// Function to display the menu
void displayMenu() {
    printf("\nSkip List Menu:\n");
    printf("1. Insert a value\n");
    printf("2. Delete a value\n");
    printf("3. Search for a value\n");
    printf("4. Print the skip list\n");
    printf("5. Exit\n");
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    SkipList *skipList = createSkipList();
    int choice, value;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(skipList, value);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                delete(skipList, value);
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                if (search(skipList, value) != NULL) {
                    printf("Value %d is present in the skip list.\n", value);
                } else {
                    printf("Value %d is not present in the skip list.\n", value);
                }
                break;
            case 4:
                printSkipList(skipList);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
