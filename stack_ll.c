#include <stdio.h>
#include <stdlib.h>
typedef struct list_node
{
    int data;
    struct list_node *next;
} node;
typedef struct stack
{
    node *top;
} stack;
stack *create()
{
    stack *s = malloc(sizeof(stack));
    if (!s)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    s->top = NULL;
    return s;
}

int is_empty(stack *s)
{
    return s->top == NULL;
}
int is_full(stack *s)
{
    return 0;
}
void display(stack *s)
{
    node *current = s->top;

    while (current != NULL)
    {
        printf("| %d |\n", current->data);
        current = current->next;
    }

    printf("|____|\n");
}

void push(stack *s)
{
    int data;
    printf("Enter the data -> ");
    scanf("%d", &data);
    node *temp = malloc(sizeof(node));
    if (!temp)
    {
        printf("Memory allocation failed \n\n");
        return;
    }
    temp->data = data;
    temp->next = s->top;
    s->top = temp;
}
int size(stack *s)
{
    int count = 0;
    if (is_empty(s))
    {
        return 0;
    }
    node *temp = s->top;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
int pop(stack *s)
{
    int data;
    if (is_empty(s))
    {
        return -1;
    }
    node *temp = s->top;
    s->top = s->top->next;
    data = temp->data;
    free(temp);
    return data;
}
int peek(stack *s)
{
    if (is_empty(s))
    {
        return -1;
    }
    return s->top->data;
}
void delete_stack(stack *s)
{
    node *temp, *p;
    p = s->top;
    while (p)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
    free(s);
}

int main()
{
    stack *s = create();
    int choice, data;

    do
    {
        printf("\nMenu for stack operations:\n");
        printf("1 -> Push\n");
        printf("2 -> Pop\n");
        printf("3 -> Peek\n");
        printf("4 -> Size\n");
        printf("5 -> Is Empty\n");
        printf("6 -> Exit\n");
        printf("Enter your choice -> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(s);
            display(s);
            break;
        case 2:
            data = pop(s);
            if (data != -1)
            {
                printf("Popped element: %d\n", data);
            }
            else
            {
                printf("Stack is empty\n");
            }
            display(s);
            break;
        case 3:
            data = peek(s);
            if (data != -1)
            {
                printf("Peeked element: %d\n", data);
            }
            else
            {
                printf("Stack is empty\n");
            }
            display(s);
            break;
        case 4:
            printf("Stack size: %d\n", size(s));
            break;
        case 5:
            if (is_empty(s))
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            display(s);
            break;
        case 6:
            
            printf("Exiting...\n");
            free(s);

            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}
