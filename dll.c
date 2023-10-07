#include <stdio.h>
#include <stdlib.h>
typedef struct doubly_linked_list
{
    int data;
    struct doubly_linked_list *next;
    struct doubly_linked_list *prev;
} node;
node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}
node *insert_at_start(node *head)
{
    int data;
    printf("Enter the data you want to insert - > ");
    scanf("%d", &data);
    if (head == NULL)
    {
        return create_node(data);
    }
    node *new_node = create_node(data);
    new_node->next = head;
    head->prev = new_node;
    new_node->prev = NULL;
    return new_node;
}
node *insert_at_end(node *head)
{
    int data;
    printf("Enter the data you want to insert - > ");
    scanf("%d", &data);
    if (head == NULL)
    {
        return insert_at_start(head);
    }
    node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    node *new_node = create_node(data);

    current->next = new_node;
    new_node->prev = current;
    new_node->next = NULL;
    return head;
}
node *insert_at_position(node *head)
{
    if (head == NULL)
    {
        int data;
        printf("Enter the data you want to insert - > ");
        scanf("%d", &data);
        return create_node(data);
    }
    int position;
    printf("enter the position where you want to insert -> ");
    scanf("%d", &position);
    if (position <= 0)
    {
        printf("Invalid position\n\n");
        return head;
    }
    if (position == 1)
    {
        return insert_at_start(head);
    }
    int i = 0;
    node *current = head;
    while (i < position - 2 && current->next != NULL)
    {
        current = current->next;
        i++;
    }
    int data;
    printf("Enter the data you want to insert - > ");
    scanf("%d", &data);
    node *new_node = create_node(data);
    new_node->next = current->next;
    current->next = new_node;
    new_node->prev = current;
    return head;
}
node *delete_at_start(node *head)
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
    head->prev = NULL;
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
    node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}
node *delete_at_position(node *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return NULL;
    }
    int position;
    printf("enter the position where you want to delete -> ");
    scanf("%d", &position);
    if (position <= 0)
    {
        printf("Invalid position\n\n");
        return head;
    }
    if (position == 1)
    {
        return delete_at_start(head);
    }
    node *current = head;
    int i=0;
    while (current->next != NULL && i < position - 1)
    {
        current = current->next;
        i++;
    }
    current->next->prev = current;
    node *temp = current->next;
    current->next = temp->next;

        free(temp);

    return head;
}
node* reverseDoublyLinkedList(node* head) {
    node* current = head;
    node* temp = NULL;

    while (current != NULL) {
        // Swap the prev and next pointers of the current node
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node
        current = current->prev;
    }

    // Update the head to point to the new beginning
    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}
int search(node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    int data;
    printf("Enter the data you want to search - > ");
    scanf("%d",&data);
    if(head->data==data)
    {
        return 1;
    }
    int count=1;
    node*current=head;
    while(current!=NULL )
    {
        if(data==current->data)
        {
            return count;
        }
        current=current->next;
        count++;
    }
    return 0;
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
void display(node *head)
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
            display(head);
            break;
        case 2:
            head = insert_at_end(head);
            display(head);
            break;
        case 3:
            head = insert_at_position(head);
            display(head);
            break;
        case 4:
            head = delete_at_start(head);
            display(head);

            break;
        case 5:
            head = delete_at_end(head);
            display(head);
            break;
        case 6:
            head = delete_at_position(head);
            display(head);
            break;
        case 7:
            display(head);
            break;
        case 8:
            head = reverseDoublyLinkedList(head);
            display(head);
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
