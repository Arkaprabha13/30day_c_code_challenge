#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int *arr;
    int size;
    int top;
} stack;

stack *initialize(int capacity)
{
    stack *s = (stack *)malloc(sizeof(stack));
    if (!s)
    {
        printf("Memory not allocated !!\n\n");
        return NULL;
    }
    s->arr = (int *)malloc(sizeof(int) * capacity);
    s->size = capacity;
    if (!s->arr)
    {
        printf("Memory not allocated !!\n\n");
        free(s); // Free the stack structure if memory allocation fails
        return NULL;
    }
    s->top = -1;
    return s;
}
int is_empty(stack *s)
{
    return s->top == -1;
}
int is_full(stack *s)
{
    return s->top == s->size - 1;
}
stack *push(stack *s)
{
    if (is_full(s))
    {
        printf("The stack is full !!\n\n");
        return s;
    }
    printf("Enter the data to store in the stack -> ");
    int data;
    scanf("%d", &data);
    s->arr[++s->top] = data;
    return s;
}
stack *pop(stack *s)
{
    if (is_empty(s))
    {
        printf("The stack is Empty !!\n\n");
        return s;
    }
    printf(" %d is poped \n", s->arr[s->top]);
    s->top--;
    return s;
}
void display(stack *s)
{
    if (is_empty(s))
    {
        printf("The stack is Empty !!\n\n");
        return;
    }
    for (int i = s->top; i >= 0; i--)
    {
        printf(" | %d | \n", s->arr[i]); // Changed the while loop to a for loop
    }
    printf(" |___|\n"); // Added a newline character
}
int main()
{
    int choice;
    stack *s;
    int capacity;
    printf("Enter the capcity of stack -> ");
    scanf("%d", &capacity);
    s = initialize(capacity);

    do
    {
        printf(" !! Menu for Stack using array !! \n");
        printf("1 -> PUSH\n");
        printf("2 -> POP\n");
        printf("3 -> Peak\n");
        printf("4 -> Exit\n");
        printf("Enter your choice  -> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            s = push(s);
            display(s);
            break;
        case 2:
            s = pop(s);
            display(s);
            break;
        case 3:
            printf("The peak element of the stack is -> ", s->arr[s->top]);
            break;
        case 4:
            printf("Exiting !!\n\n");
            exit(1);
            break;

        default:
            printf("Invalid Choice ");
            break;
        }
    } while (1);

    return 0;
}
