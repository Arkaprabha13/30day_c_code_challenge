#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define max_size 10
typedef struct stack
{
    int top;
    char *items;
} stack;
stack *initialize(int max_size)
{
    stack *s = (stack *)malloc(sizeof(stack));
    if (s == NULL)
    {
        fprintf(stderr, "Memory allocation failed for stack structure\n");
        exit(EXIT_FAILURE);
    }

    s->items = (char *)malloc(max_size * sizeof(char));
    if (s->items == NULL)
    {
        fprintf(stderr, "Memory allocation failed for stack items\n");
        exit(EXIT_FAILURE);
    }

    s->top = -1;
    return s;
}

char pop(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

void push(stack *s, char item)
{
    if (s->top == 10 - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++s->top] = item;
}
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int priority(char x)
{
    if (x == '(')
    {
        return 0;
    }
    if (x == '+' || x == '-')
    {
        return 1;
    }
    if (x == '*' || x == '/')
    {
        return 2;
    }
}
char *infix_to_postfix(char *infix)
{
    stack *s;
    s = initialize(10);
    char *postfix =(char *)malloc((strlen(infix)+1) * sizeof(char));
    int i = 0; // for infix
    int j = 0; // for postfix
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (priority(infix[i]) > priority(s->top))
            {
                push(s, infix[i]);
                i++;
            }
            else
            {
                postfix[j++] = pop(s);
            }
        }
    }
    while (s->top != -1)
    {
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char *infix = "x-y*z-k*d";
    char *postfix = infix_to_postfix(infix);
    printf("Infix -> %s\n", infix);
    printf("Postfix -> %s\n", postfix);
    return 0;
}
