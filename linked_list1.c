#include <stdio.h>
#include <stdlib.h>
// THESE METHODS ARE  BETTER THAN LINKED LIST METHODS IN LINKEDLIST2


struct node
{
    int data;
    struct node *next; // address storing space
};

struct node *create_node( int val)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;

    return temp;
}





void insert_at_begin_1(struct node **head, int val) // adds element to the begin of linked list
{
    struct node *nod =create_node( val);
    

    if (*head == NULL)
    {
        return;

    } // it dont requires handling of head pointer

    else
    {

        nod->next = *head;
        *head = nod;
    }
}

struct node *insert_at_end_1(struct node *endptr, int val) // adding elements with the help of endptr (end pointer)
{                                                          // it has time complexity O(1)
    struct node *nod=create_node(val);;                                        // it requires handling of extra pointer endptr
    
    if (endptr == NULL)
    {
        return nod;
    }
    else
    {
        endptr->next = nod;
        return nod;
    }
}

struct node *del_at_begin(struct node *head)
{
    if (head == NULL)
    {
        printf("empty");
    }

    else
    {
        head = head->next;
        return head;
    }
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d \t ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int length(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        // printf("empty");
        return 0;
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        // printf("%d \t ", ptr->data);
        ptr = ptr->next;
        count++;
    }
    return count;
    // printf("\n");
}

int main()
{
    // creating linked list

    struct node *head = malloc(sizeof(struct node)); // head always points to the first element
    head->data = 89;
    head->next = NULL;

    struct node *endptr;                // it should be always handled through out the program to easily add
    endptr = insert_at_end_1(head, 98); // elements at the end with time complexity O(1)

    insert_at_begin_1(&head, 46);
    display(head);

    endptr = insert_at_end_1(endptr, 3);
    display(head);

    head = del_at_begin(head);

    display(head);

    return 0;
}