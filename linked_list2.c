
// basic methods.....these are not best
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next; // address storing space
};
struct node *create_node(int val)
{
    struct node *new = malloc(sizeof(struct node));
    new->data = val;
    new->next = NULL;
    return new;
}

 struct node * insert_at_begin_2(struct node *head, int data) // adds element to the begin of linked list
{
    struct node *new = create_node(data);

    if (head == NULL)
    {
        return new;
    } // it requires handling of head pointer

    else
    {
        new->next = head;
        head = new;

        return head;
    }
}

void insert_at_end_2(struct node *head, int data) // adding elements with the help of head pointer (starting pointer)
{                                                 // it has time complexity o(n)
                                                  // it doesnt require extra pointer handling

    struct node *new = create_node(data);

    if (head == NULL)
    {
        head = new;
    }

    else
    {
        struct node *ptr = head;

        while (ptr->next != NULL)
        {

            ptr = ptr->next;
        }
        ptr->next = new;
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

int main()
{
    // initializing and making linked list
    struct node *head = malloc(sizeof(struct node));
    head->data = 90;
    head->next = NULL;

    struct node *new = malloc(sizeof(struct node));
    new->data = 89;
    new->next = NULL;

    head->next = new;
    new = malloc(sizeof(struct node));
    new->data = 87;
    new->next = NULL;

    head->next->next = new;

    display(head);
    insert_at_end_2(head, 78);
    display(head);
    // printf("%d",length(head));
    head=insert_at_begin_2(head, 100);
    display(head);
    // printf("%d \n", head->next->data);

    return 0;
}
