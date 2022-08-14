

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *create_node(int val)
{
    struct node *ne = malloc(sizeof(struct node));

    ne->data = val;
    ne->data = val;
    ne->left = NULL;
    ne->right = NULL;
    return ne;
}

struct node *insert(struct node *root, int val)
{

    // struct node *roote = root;
    if (root == NULL)
    {
        struct node *head = create_node(val);
        root = head;
    }
    else if (val <= root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

int search(struct node *root, int val)
{
    int level = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (val == root->data)
    {
        return 1;
    }
    else if (val <= root->data)
    {
        return search(root->left, val);
    }
    else
    {
        return search(root->right, val);
    }
    return level;
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    preorder(root->left);
    printf("%d ", root->data);

    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    preorder(root->left);
    preorder(root->right);
    printf("%d ", root->data);
}

int main()
{

    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 5);
    root = insert(root, 11);
    root = insert(root, 13);
    root = insert(root, 10);
    root = insert(root, 10);
    root = insert(root, 10);
    root = insert(root, 10);

    
    // printf("%d \n", search(root, 7));
    inorder(root);
    printf("\n");

    return 0;
}