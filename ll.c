#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_node
{
    int data;
    struct linked_list_node *next;
} node;

node *create(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node *insert_at_start(node *head)
{
    int data;
    printf("Enter the data you want to enter -> ");
    scanf("%d", &data);
    if (head == NULL)
    {
        return create(data);
    }
    node *new_node = create(data);
    new_node->next = head;
    return new_node;
}

node *insert_at_end(node *head)
{
    if (head == NULL)
    {
        return insert_at_start(head);
    }
    int data;
    printf("Enter the data you want to enter -> ");
    scanf("%d", &data);
    node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    node *new_node = create(data);
    current->next = new_node;
    new_node->next = NULL;
    return head;
}

node *insert_at_position(node *head)
{
    int position;
    printf("Enter the position you want to enter -> ");
    scanf("%d", &position);
    // position does not exist
    if (position < 0)
    {
        printf("Does not exist!!\n\n");
        return head;
    }
    // insert at start
    if (position == 0)
    {
        return insert_at_start(head);
    }
    int data;
    printf("Enter the data you want to enter -> ");
    scanf("%d", &data);
    node *new_node = create(data);
    int counter; // to have a check of position
    node *current = head;
    while (counter < position - 1 && current != NULL)
    {
        counter++;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Invalid position.\n");
        return head;
    }
    new_node->next = current->next;
    current->next = new_node;

    return head;
}
int length(node *head)
{
    int count = 0;
    node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
void print(node *head)
{
    printf("\n\n");
    if (head == NULL)
    {
        printf("The list is Empty !!\n\n");
    }

    node *current = head;
    while (current != NULL)
    {
        printf(" %d -> ", current->data);
        current = current->next;
    }
    printf("\n\n");
}
node *delte_At_start(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return NULL;
    }
    node *temp = head;
    head = temp->next;
    free(temp);
    return head;
}
node *delete_at_end(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return NULL;
    }
    node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}
node *delete_at_position(node *head)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot perform deletion.\n");
        return head;
    }

    int position;
    printf("Enter the position where you want to perform deletion: ");
    scanf("%d", &position);

    if (position <= 0)
    {
        printf("Invalid position.\n");
        return head;
    }

    if (position == 1)
    {
        // Delete the first node
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    if (position == length(head))
    {
        return delete_at_end(head);
    }
    int i = 0;
    node *current = head;
    node *previous = NULL;

    while (current != NULL && i < position - 1)
    {
        i++;
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Invalid position.\n");
        return head;
    }

    // Delete the node at the given position
    previous->next = current->next;
    free(current);

    return head;
}

int search(node *head)
{
    if (head == NULL)
    {
        return -1;
    }
    int data;
    printf("Enter the value which you want to search -> ");
    scanf("%d", &data);
    if (head->data == data)
    {
        return 0;
    }
    node *current = head;
    int count = 0;
    while (current != NULL)
    {

        if (data == current->data)
        {
            return count;
        }
        count++;
        current = current->next;
    }
    return -1;
}
node *reverse(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }
    node *prev = NULL;
    node *current = head;
    node *next;

    while (current->next != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}
int main()
{
    int choice;
    node *head = NULL;
    int l, index;
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Display\n");
        printf("8. Reverse\n");
        printf("9. Search\n");
        printf("10. Length\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = insert_at_start(head);
            print(head);
            break;
        case 2:
            head = insert_at_end(head);
            print(head);
            break;
        case 3:
            head = insert_at_position(head);
            print(head);
            break;
        case 4:
            head = delte_At_start(head);
            print(head);

            break;
        case 5:
            head = delete_at_end(head);
            print(head);
            break;
        case 6:
            head = delete_at_position(head);
            print(head);
            break;
        case 7:
            print(head);
            break;
        case 8:
            head = reverse(head);
            print(head);
            break;
        case 9:
            index = search(head);
            if (index >= 0)
            {
                printf("Yes the element is found at index -> %d", index);
            }
            break;
        case 10:
            // Declare the variable 'l'
            l = length(head); // Assign it a value using the function call

            printf("The length of the list is -> %d", l);
            break;
        case 11:
            printf("!! Exiting !!\n");
            exit(1);
            break;

        default:
            printf("Invalid input !!\n\n");
            break;
        }

    } while (1);
    return 0;
}