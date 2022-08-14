

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next; // address storing space
};
struct node *create_node(int val)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = temp; // as it is circular linked list
    return temp;
}
int length(struct node *tail)
{
    struct node *temp = tail->next;
    int count = 0;
    do
    {

        count++;
        temp = temp->next;
    } while (temp != tail->next);
    return count;
}

void display(struct node *tail)
{
    struct node *temp = tail->next;

    do
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);

    printf("\n");
}

struct node *insert_at_pos(struct node *tail, int pos, int val)
{
    struct node *nod = create_node(val);

    if (tail == NULL)

    {
        return nod;
    }

    else
    {

        {
            struct node *temp = tail;

            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }

            nod->next = temp->next;
            temp->next = nod;

            if (temp == tail & pos == length(tail))
            {
                tail = tail->next;
            }

            return tail;
        }
    }
}

int main()
{

    struct node *tail = create_node(78); // maintain a tail pointer instead of head pointer

    tail = insert_at_pos(tail, 1, 79);
    tail = insert_at_pos(tail, 3, 71);

    display(tail);

    return 0;
}