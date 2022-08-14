

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *create_node( int val){
        struct node *n = malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;
    n->prev = NULL;
    return n;
}


void display(struct node *head)
{

    if (head == NULL)
    {
        printf("linked list empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf(" <=>%d<=> ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int length(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        return count;
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        //   printf(" <=>%d<=> ", ptr->data);
        count++;
        ptr = ptr->next;
    }
    return count;
}
struct node *insert_at_empty(struct node *head, int val)
{
    struct node *n = create_node(val);

    head = n;
    return head;
}


void del_at_pos(struct node *head, int pos)
{
    if (pos == 1)
    {
        return;
    }
    else if (pos == length(head))
    {
        struct node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
    else
    {
        int itr = 1;
        struct node *temp = head;
        while (itr != pos - 1)
        {
            itr++;
            temp = temp->next;
        }
        temp->next->next->prev = temp;
        temp->next = temp->next->next;
    }
}

struct node *insert_begin(struct node *head, int val)
{
    struct node *n = create_node( val);
    if (head == NULL)
    {
        head = n;
        return head;
    }
    else
    {
        n->next = head;
        head->prev = n;
        head = n;

        return head;
    }
}

void insert_at_end(struct node *head, int data) // adding elements with the help of head pointer (starting pointer)
{                                               // it has time complexity o(n)
                                                // it doesnt require extra pointer handling

    struct node *new = create_node( data);


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
        new->prev = ptr;
    }
}
void insert_at_pos(struct node *head, int val, int pos)
{
    if (pos == 1)
    {
        insert_begin(head, val);
    }
    else if (pos == length(head) + 1)
    {
        insert_at_end(head, val);
    }
    else
    {
        struct node *temp = head;

        int itr = 1;
      struct node *n = create_node( val);


        while (itr != pos - 1)
        {
            temp = temp->next;
            itr++;
        }
        n->next = temp->next;
        n->prev = temp;
        temp->next->prev = n;
        temp->next = n;
    }
}

int main()
{
    struct node *head = NULL;
    head = insert_begin(head, 89);
    head = insert_begin(head, 95);
    insert_at_end(head, 87);
    display(head);
    //  printf("%d", length(head));
    insert_at_pos(head, 2, 2);
    display(head);
    del_at_pos(head, 2);

    display(head);

    // struct node *pead = NULL;
    // pead = insert_at_empty(pead, 77777);
    // display(pead);

    return 0;
}