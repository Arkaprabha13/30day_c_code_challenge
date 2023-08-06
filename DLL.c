#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;
node *insert_at_begin(node *head)
{
    int x;
    printf("Enter the data for newnode at begining -> ");
    scanf("%d", &x);
    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode)
    {
        printf("Memory leak !!!!");
        return NULL;
    }
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        return head;
    }
}
node *insert_at_end(node *head)
{
    int x;
    printf("Enter the data for newnode  at end-> ");
    scanf("%d", &x);
    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode)
    {
        printf("Memory leak !!!!");
        return NULL;
    }
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode->prev = temp;
    temp->next = newnode;

    return head;
}
node *insert(node *head)
{
    int x;
    printf("Enter the data for newnode  at end-> ");
    scanf("%d", &x);
    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode)
    {
        printf("Memory leak !!!!");
        return NULL;
    }
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    int position;
    printf("Enter the position at whcih you want to insert a node ");
    scanf("%d", &position);
    if (position == 1)
    {
        insert_at_begin(head);
    }
    int counter = 1;
    node *temp = head;
    while (counter < position - 1 && temp->next != NULL)
    {
        temp = temp->next;
        counter++;
    }
    if (counter < position - 1)
    {
        printf("The position does not exist !!");
        return head;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next)
    {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    ;
    return head;
}

void display(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf(" %d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void delete_head(node **head) // passing pointer to head
{
    if (*head == NULL)
    {
        printf("\nList is empty !!\n");
        return;
    }

    node *temp = *head;
    *head = (*head)->next; // Update the head pointer to point to the next node
    if (*head != NULL)
    {
        (*head)->prev = NULL; // Update the prev pointer of the new head
    }
    free(temp);
}
void delete_last_node(node **head)
{
    if (*head == NULL)
    {
        printf("\nList is empty !!\n");
        return;
    }
    node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    if (current->prev == NULL)
    {
        // The list has only one node
        free(*head);
        *head = NULL;
    }
    else
    {
        current->prev->next = NULL;
        free(current);
    }
}
void deleting_at_a_position(node **head)
{
    if (*head == NULL)
    {
        printf("\nList is empty !!\n");
        return;
    }

    int position;
    printf("Enter the position at which you want to delete the node -> ");
    scanf("%d", &position);

    if (position <= 0)
    {
        printf("\nInvalid position !!\n");
        return;
    }

    node *current = *head;
    int counter = 1;
    while (counter < position && current != NULL)
    {
        current = current->next;
        counter++;
    }
    if (current == NULL)
    {
        printf("\nThe position does not exist !!\n");
        return;
    }
    if (current->prev == NULL)
    {
        // Deleting the first node
        *head = current->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
    else if (current->next == NULL)
    {
        // Deleting the last node
        current->prev->next = NULL;
    }
    else
    {
        // Deleting a node in the middle
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    free(current);
}

int main()
{
    node *head = NULL;
    int n;
    printf("Enter number of elemenets you want to insert at begining of DLL -> ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        head = insert_at_begin(head);
        head = insert_at_end(head);
        display(head);
    }
    for (int i = 0; i < n; i++)
    {
        head = insert(head);
        display(head);
    }
    delete_head(&head);
    printf("\nAfter deleting the head node !! \n");
    display(head);
    delete_last_node(&head);
    printf("\nAfter deleting the last node !! \n");
    display(head);
    deleting_at_a_position(&head);
    printf("\nAfter deleting a specific node !! \n");
    display(head);
    return 0;
}
