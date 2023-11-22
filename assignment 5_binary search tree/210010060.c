/*
DSA Assignment 5
Ashwin Waghmare
210010060
A program to create a binary tree and perform the following actions:-
insert
inorder
preorder
postorder
maximum
minimum
successor
predecessor
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct bst
{
    struct bst *l;
    int data;
    struct bst *r;
};

struct bst * create(int n)
{
    struct bst *t = (struct bst *)malloc(sizeof(struct bst));
    t->l = NULL;
    t->data = n;
    t->r = NULL;
    return t;
}
struct bst *root;

int size = 0;
int cnt = 0;
int a[10000]; // array to store inorder of the binary tree
int i;        // variable to store the size of the array
FILE *op;
void insert(int n);
void inorder(struct bst *t);
void preorder(struct bst *t);
void postorder(struct bst *t);
void search(int n);
void minimum(struct bst *t);
void maximum(struct bst *t);
void inorderarray(struct bst *t);
void successorprint(int n);
void predecessorprint(int n);

int main(int argc, char *argv[])
{
    op = fopen("bst.txt", "w");
    FILE *in;
    in = fopen(argv[1], "r");

    char s[20];

    while (fgets(s, 20, in) != NULL)
    {
        if (strstr(s, "insert"))
        {
            char *t = s;
            t += 7;
            strcpy(s, t);
            s[strlen(s) - 1] = '\0';
            int n = atoi(s);
            insert(n);
        }
        else if (strstr(s, "inorder"))
        {
            cnt = 0;
            inorder(root);
            fprintf(op, "\n");
        }
        else if (strstr(s, "preorder"))
        {
            cnt = 0;
            preorder(root);
            fprintf(op, "\n");
        }
        else if (strstr(s, "postorder"))
        {
            cnt = 0;
            postorder(root);
            fprintf(op, "\n");
        }
        else if (strstr(s, "search"))
        {
            char *t = s;
            t += 7;
            strcpy(s, t);
            s[strlen(s) - 1] = '\0';
            int n = atoi(s);
            search(n);
        }
        else if (strstr(s, "minimum"))
        {
            minimum(root);
        }
        else if (strstr(s, "maximum"))
        {
            maximum(root);
        }
        else if (strstr(s, "successor"))
        {
            char *t = s;
            t += 10;
            strcpy(s, t);
            s[strlen(s) - 1] = '\0';
            int n = atoi(s);
            i = -1;
            inorderarray(root);
            successorprint(n);
        }
        else if (strstr(s, "predecessor"))
        {
            char *t = s;
            t += 12;
            strcpy(s, t);
            s[strlen(s) - 1] = '\0';
            int n = atoi(s);
            i = -1;
            inorderarray(root);
            predecessorprint(n);
        }
    }

    fclose(in);
    fclose(op);
    return (0);
}

void inorderarray(struct bst *t)
{
    if (t != NULL)
    {
        inorderarray(t->l);
        i++;
        a[i] = t->data;
        inorderarray(t->r);
    }
}

void insert(int n)
{
    struct bst *newnode;
    newnode = create(n);
    if (root == NULL)
    {
        root = newnode;
    }

    else
    {
        struct bst *current, *temp;
        current = root;
        while (current != NULL)
        {
            temp = current;
            if (current->data > newnode->data)
            {
                current = current->l;
            }
            else
            {
                current = current->r;
            }
        }

        if (temp->data > newnode->data)
        {
            temp->l = newnode;
        }
        else
        {
            temp->r = newnode;
        }
    }
    fprintf(op, "%d inserted\n", n);
    size++;
}

void maximum(struct bst *t)
{
    if (root == NULL)
    {
        return;
    }
    while (t->r != NULL)
    {
        t = t->r;
    }
    fprintf(op, "%d\n", t->data);
}

void inorder(struct bst *t)
{
    if (t != NULL)
    {
        inorder(t->l);
        cnt++;
        if (cnt == size)
        {
            fprintf(op, "%d", t->data);
        }
        else
        {
            fprintf(op, "%d ", t->data);
        }
        inorder(t->r);
    }
}

void search(int n)
{
    struct bst *s;
    s = root;
    while (s != NULL)
    {
        if (n == s->data)
        {
            fprintf(op, "%d found\n", n);
            return;
        }
        else if (n < s->data)
        {
            s = s->l;
        }
        else
        {
            s = s->r;
        }
    }
    fprintf(op, "%d not found\n", n);
}

void preorder(struct bst *t)
{
    if (t != NULL)
    {
        cnt++;
        if (cnt == size)
        {
            fprintf(op, "%d", t->data);
        }
        else
        {
            fprintf(op, "%d ", t->data);
        }
        preorder(t->l);
        preorder(t->r);
    }
}

void postorder(struct bst *t)
{
    if (t != NULL)
    {
        postorder(t->l);
        postorder(t->r);

        cnt++;
        if (cnt == size)
        {
            fprintf(op, "%d", t->data);
        }
        else
        {
            fprintf(op, "%d ", t->data);
        }
    }
}

void minimum(struct bst *t)
{
    if (root == NULL)
    {
        return;
    }
    while (t->l != NULL)
    {
        t = t->l;
    }
    fprintf(op, "%d\n", t->data);
}

void successorprint(int n)
{
    if (i == 0)
    {
        fprintf(op, "%d does not exist\n", n);
        return;
    }
    if (a[i] == n)
    {
        fprintf(op, "successor of %d does not exist\n", n);
        return;
    }
    i--;
    while (i != 0)
    {
        if (a[i] == n)
        {
            fprintf(op, "%d\n", a[i + 1]);
            return;
        }
        i--;
    }
    fprintf(op, "%d does not exist\n", n);
}

void predecessorprint(int n)
{
    if (i == 0)
    {
        fprintf(op, "%d does not exist\n", n);
        return;
    }
    if (a[1] == n)
    {
        fprintf(op, "predecessor of %d does not exist\n", n);
        return;
    }
    while (i != 1)
    {
        if (a[i] == n)
        {
            fprintf(op, "%d\n", a[i - 1]);
            return;
        }
        i--;
    }
    fprintf(op, "%d does not exist\n", n);
}
