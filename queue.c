#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queue {
    int size;
    int front, rear;
    unsigned capacity;
    int *array;
} queue;

int is_full(queue *q) {
    return q->size == q->capacity;  // Changed q->rear to q->size
}

int is_empty(queue *q) {
    return q->size == 0;
}

queue *allocate(unsigned capacity) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->capacity = capacity;
    q->array = (int *)malloc(sizeof(int) * capacity);
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;

    return q;
}

queue *enqueue(queue *q) {
    if (is_full(q)) {
        printf("The Queue is full!\n\n");
        return q;
    }
    int data;
    printf("Enter the data you want to enqueue -> ");
    scanf("%d", &data);
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = data;
    q->size = q->size + 1;
    printf("%d enqueued to queue\n", data);

    return q;
}

queue *dequeue(queue *q) {
    if (is_empty(q)) {
        printf("The Queue is Empty!\n\n");
        return q;
    }
    int item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    printf("%d is deleted from the queue\n", item);
    return q;
}   
// Function to get front of queue
int front(queue *q)
{
    if (is_empty(q))
        return INT_MIN;
    return q->array[q->front];
}

int rear(queue *q)
{
    if (is_empty(q))
    {
        return INT_MIN;
    }
    return q->array[q->rear];
}
void display(queue *q)
{
    if (is_empty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    int i = q->front;
    printf("Queue elements: ");
    for (int count = 0; count < q->size; count++)
    {
        printf("%d ", q->array[i]);
        i = (i + 1) % q->capacity;
    }
    printf("\n");
}

int main()
{
    unsigned capacity;
    printf("Enter the capacity of the queue -> ");
    scanf("%d", &capacity);
    queue *q = allocate(capacity);
    int option;
    do
    {
        printf("\n************ Operations on Queue ***************\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter the operation you want to perform -> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            q = enqueue(q);

            display(q);
            break;
        case 2:
            q = dequeue(q);
            display(q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option.\n");
            break;
        }
    } while (option != 4);

    // Free allocated memory
    free(q->array);
    free(q);

    return 0;
}
