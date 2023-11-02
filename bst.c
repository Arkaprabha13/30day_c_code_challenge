#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
} node;

// Structure for a queue to hold nodes
struct QueueNode {
    struct tree_node *data;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
};

// Function to create a new queue
struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue a node
void enqueue(struct Queue *queue, struct tree_node *data) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue a node
struct tree_node *dequeue(struct Queue *queue) {
    if (queue->front == NULL) {
        return NULL;
    }

    struct tree_node *data = queue->front->data;
    struct QueueNode *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Function to perform level order traversal
void level_order_traversal(node *root) {
    if (root == NULL) {
        return;
    }

    struct Queue *queue = createQueue();
    enqueue(queue, root);

    while (queue->front != NULL) {
        node *currentNode = dequeue(queue);
        printf("%d ", currentNode->data);

        if (currentNode->left) {
            enqueue(queue, currentNode->left);
        }
        if (currentNode->right) {
            enqueue(queue, currentNode->right);
        }
    }

    free(queue);
}

node *allocate_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert_node(node *root, int data) {
    if (root == NULL) {
        return allocate_node(data);
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data);
    }
    if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

node *search(node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}

node *find_min(node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

node *delete_node(node *root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = delete_node(root->left, key);
    } else if (root->data < key) {
        root->right = delete_node(root->right, key);
    } else {
        // Node with key is found

        // Case 1: Node with one child or no child
        if (root->left == NULL) {
            node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node with both children
        node *temp = find_min(root->right);
        root->data = temp->data;  // Copying in-order successor's data
        root->right = delete_node(root->right, temp->data); // Delete the in-order successor
    }
    return root;
}

int main() {
    node *root = NULL;
    int choice, data;

    do {
        printf("1. Insert\n2. Delete\n3. Search\n4. Level Order Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert_node(root, data);
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete_node(root, data);
                break;

            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data)) {
                    printf("Data found in the tree.\n");
                } else {
                    printf("Data not found in the tree.\n");
                }
                break;

            case 4:
                printf("Level Order Traversal: ");
                level_order_traversal(root);
                printf("\n");
                break;

            case 5:
                // Free memory and exit
                // You should add code here to free the entire tree
                exit(0);
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
