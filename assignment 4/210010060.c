/*DSA assignment 4
Ashwin Waghmare
210010060
A code to implement stacks and circular queue using sll
Also doubly linked list*/
#include <stdio.h>
#include <stdlib.h>

FILE *in, *s, *q, *d;
int size, scount, qcount;

void displaystack();
void push(int n);
void pop();
void searchstack(int n);
void displayqueue();
void enqueue(int n);
void dequeue();
void searchqueue(int n);
void displaydll();
void insert(int n);
void delete (int n);
void searchdll(int n);

struct stack
{
    int data;
    struct stack *next;
};
struct stack *stackhead = NULL;
struct stack *createstack(int n)
{
    struct stack *newnode = malloc(sizeof(struct stack));
    if (newnode == NULL)
    {
        fprintf(s, "\n Out of Memory Space: \n");
        exit(0);
    }
    newnode->data = n;
    newnode->next = NULL;
    return newnode;
};

struct queue
{
    int data;
    struct queue *next;
};
struct queue *queuehead = NULL;
struct queue *createqueue(int n)
{
    struct queue *newnode = malloc(sizeof(struct queue));
    if (newnode == NULL)
    {
        fprintf(s, "\n Out of Memory Space: \n");
        exit(0);
    }
    newnode->data = n;
    newnode->next = NULL;
    return newnode;
};

struct dll
{
    int data;
    struct dll *prev;
    struct dll *next;
};
struct dll *head = NULL;
struct dll *createdll(int n)
{
    struct dll *newnode = malloc(sizeof(struct dll));
    if (newnode == NULL)
    {
        fprintf(d, "\n Out of Memory Space: \n");
        exit(0);
    }
    newnode->data = n;
    newnode->next = NULL;
    return newnode;
};

int main(int argc, char *argv[])
{
    in = fopen(argv[1], "r");
    s = fopen("stack.txt", "w");
    q = fopen("queue.txt", "w");
    d = fopen("dll.txt", "w");

    size = atoi(argv[2]);

    scount = 0;
    qcount = 0;

    char x[10];
    int n;
    while (fscanf(in, "%c", &x) != EOF)
    {
        switch (x[0])
        {
        case '!':
            displaystack();
            displayqueue();
            displaydll();
            break;

        case '+':
            fscanf(in, "%d", &n);
            push(n);
            enqueue(n);
            insert(n);
            break;

        case '-':
            fscanf(in, "%d", &n);
            pop();
            dequeue();
            delete (n);
            break;

        case '?':
            fscanf(in, "%d", &n);
            searchstack(n);
            searchqueue(n);
            searchdll(n);
            break;
        }
        fscanf(in, "%c", &x);
    }
    fclose(in);
    fclose(s);
    fclose(q);
    fclose(d);
}

void displaystack()
{
    int a[size];
    int i = 0;
    struct stack *t;
    if (stackhead == NULL)
    {
        fprintf(s, "\n");
        return;
    }
    else
    {
        t = stackhead;
        while (t != NULL)
        {
            a[i] = t->data;
            t = t->next;
            i++;
        }
        for (int j = i - 1; j >= 0; j--)
        {
            fprintf(s, "%d ", a[j]);
        }
    }
    fprintf(s, "\n");
}

void push(int n)
{
    if (scount > size - 1)
    {
        fprintf(s, "overflow\n");
        return;
    }
    struct stack *newnode, *tail;
    newnode = createstack(n);
    if (stackhead == NULL)
    {
        stackhead = newnode;
    }
    else
    {
        tail = stackhead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
    fprintf(s, "pushed %d\n", newnode->data);
    scount++;
}

void pop()
{
    struct stack *taildel, *tailprevnode;
    if (stackhead == NULL)
    {
        fprintf(s, "underflow\n");
        return;
    }
    else if (stackhead->next == NULL)
    {
        taildel = stackhead;
        stackhead = NULL;
        fprintf(s, "popped %d\n", taildel->data);
        free(taildel);
    }
    else
    {
        taildel = stackhead;
        while (taildel->next != NULL)
        {
            tailprevnode = taildel;
            taildel = taildel->next;
        }
        tailprevnode->next = NULL;
        fprintf(s, "popped %d\n", taildel->data);
        free(taildel);
    }
    scount--;
}

void searchstack(int n)
{
    struct stack *t;
    t = stackhead;
    while (t != NULL)
    {
        if (t->data == n)
        {
            fprintf(s, "found %d\n", n);
            return;
        }
        t = t->next;
    }
    fprintf(s, "not found %d\n", n);
}

void displayqueue()
{
    struct queue *t;
    if (queuehead == NULL)
    {
        fprintf(q, "\n");
        return;
    }
    else
    {
        t = queuehead;
        while (t->next != queuehead)
        {
            fprintf(q, "%d ", t->data);
            t = t->next;
        }
        fprintf(q, "%d \n", t->data);
    }
}

void enqueue(int n)
{
    if (qcount > size - 1)
    {
        fprintf(q, "overflow\n");
        return;
    }
    struct queue *newnode, *tail;
    newnode = createqueue(n);
    if (queuehead == NULL)
    {
        queuehead = newnode;
        newnode->next = queuehead;
    }
    else
    {
        tail = queuehead;
        while (tail->next != queuehead)
        {
            tail = tail->next;
        }
        tail->next = newnode;
        newnode->next = queuehead;
    }
    fprintf(q, "enqueued %d\n", newnode->data);
    qcount++;
}

void dequeue()
{
    struct queue *tail, *headdel;
    if (queuehead == NULL)
    {
        fprintf(q, "underflow\n");
        return;
    }
    else
    {
        tail = queuehead;
        headdel = queuehead;
        if (queuehead->next == queuehead)
        {
            fprintf(q, "dequeued %d\n", headdel->data);
            queuehead = NULL;
            free(tail);
        }
        else
        {
            while (tail->next != queuehead)
            {
                tail = tail->next;
            }
            queuehead = queuehead->next;
            tail->next = queuehead;
            fprintf(q, "dequeued %d\n", headdel->data);
            free(headdel);
        }
        qcount--;
    }
}

void searchqueue(int n)
{
    struct queue *t;
    if (queuehead == NULL)
    {
        fprintf(q, "not found %d\n", n);
        return;
    }
    else
    {
        t = queuehead;
        while (t->next != queuehead)
        {
            if (t->data == n)
            {
                fprintf(q, "found %d\n", n);
                return;
            }
            t = t->next;
        }
        fprintf(q, "not found %d\n", n);
    }
}

void insert(int n)
{
    struct dll *newnode, *tail;
    if (head == NULL)
    {
        newnode = createdll(n);
        head = newnode;
        newnode->prev = NULL;
    }
    else
    {
        tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        newnode = createdll(n);
        tail->next = newnode;
        newnode->prev = tail;
    }
    fprintf(d, "inserted %d\n", newnode->data);
}

void displaydll()
{
    if (head == NULL)
    {
        fprintf(d, "\n");
        return;
    }
    else
    {
        struct dll *t;
        t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        while (t != NULL)
        {
            fprintf(d, "%d ", t->data);
            t = t->prev;
        }
    }
    fprintf(d, "\n");
}

void searchdll(int n)
{
    struct dll *t;
    t = head;
    while (t != NULL)
    {
        if (t->data == n)
        {
            fprintf(d, "found %d\n", n);
            return;
        }
        t = t->next;
    }
    fprintf(d, "not found %d\n", n);
}

void delete (int n)
{
    struct dll *t, *pr, *ne;
    t = head;
    while (t->next != NULL)
    {
        t = t->next;
    }

    while (t != head)
    {
        if (t->data == n)
        {
            pr = t->prev;
            ne = t->next;

            if (pr == NULL)
            {
                ne->prev = NULL;
                head = ne;
                free(t);
            }
            else if (ne == NULL)
            {
                pr->next = NULL;
                free(t);
            }
            else
            {
                pr->next = ne;
                ne->prev = pr;
                free(t);
            }
            fprintf(d, "deleted %d\n", n);
            return;
        }
        t = t->prev;
    }
    fprintf(d, "cannot delete %d\n", n);
}