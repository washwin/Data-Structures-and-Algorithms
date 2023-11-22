/*ASsignment 10
Ashwin Waghmare
210010060
A program to implement Dijkstra Algorithm*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void insert();  // to be used when inserting
void extract(); // to be used when extracting

int distance[999999];
int heapsize;
int priority_q[999999];
int exist[999999];

struct vertex
{
    int data;
    int weight;
    struct vertex *next;
};
struct vertex *vlist[999999];

int main(int argc, char *argv[])
{
    FILE *op;
    op = fopen("dijkstra.txt", "w");
    fclose(op);

    if (argc > 3)
    {
        printf("too many arguments. enter exactly one file name and source vertex.");
        exit(1);
    }
    else if (argc < 3)
    {
        printf("too few arguments. enter exactly one file name and source vertex.");
        exit(2);
    }

    int source = atoi(argv[2]);

    int i;
    for (i = 0; i < 999999; i++) // set initial values
    {
        exist[i] = 0;
        distance[i] = 999999;
        vlist[i] = NULL;
        priority_q[i] = -1;
    }
    priority_q[0] = 999999;

    distance[source] = 0; // set distance of source node to 0
    int u, v, w;
    FILE *in;
    in = fopen(argv[1], "r");
    if (in == NULL)
    {
        printf("input file does not exist\n");
        exit(3);
    }
    while (fscanf(in, "%d %d %d\n", &u, &v, &w) != EOF)
    {
        struct vertex *newnode = malloc(sizeof(struct vertex));
        if (newnode != NULL) // check if memory is available
        {
            newnode->data = v;
            newnode->weight = w;
        }
        else
        {
            printf("\nMemory Insufficient!");
            exit(4);
        }
        newnode->next = vlist[u];
        vlist[u] = newnode;
        if (exist[u] == 0)
        {
            priority_q[++heapsize] = u;
            insert(heapsize);
            exist[u] = 1;
        }
        if (exist[v] == 0)
        {
            priority_q[++heapsize] = v;
            insert(heapsize);
            exist[v] = 1;
        }
    }
    fclose(in);

    while (heapsize > 0) // main part: core of Dijkstra Algorithm
    {
        int min = priority_q[1];
        priority_q[1] = priority_q[heapsize];
        priority_q[heapsize] = 999999;
        heapsize--;
        extract(1);
        u = min;

        if (distance[u] == 999999)
        {
            continue;
        }
        struct vertex *temp;
        temp = vlist[u];
        while (temp != NULL)
        {
            if (distance[temp->data] > (distance[u] + temp->weight))
            {
                distance[temp->data] = distance[u] + temp->weight;
                i = 0;
                while (1==1)
                {
                    if (priority_q[i] == temp->data)
                    {
                        break;
                    }
                    i++;
                }
                insert(i);
            }
            temp = temp->next;
        }
    }

    op = fopen("dijkstra.txt", "a+");
    for (i = 0; i < 999999; i++)
    {
        if (exist[i] == 1)
        {
            if (distance[i] == 999999)
            {
                fprintf(op, "%d -1\n", i);
            }
            else
            {
                fprintf(op, "%d %d\n", i, distance[i]);
            }
        }
    }
    fclose(op);
}

void insert(int c)
{
    int temp, par;
    while ((c > 1) && (distance[priority_q[c]] < distance[priority_q[(int)c / 2]]))
    {
        par = (int)c / 2;
        temp = priority_q[c];
        priority_q[c] = priority_q[par];
        priority_q[par] = temp;
        c = par;
    }
}

void extract(int i)
{
    int min = i;
    if (((2 * i) <= heapsize) && (distance[priority_q[(2 * i)]] < distance[priority_q[min]]))
    {
        min = (2 * i);
    }

    if (((2 * i) + 1 <= heapsize) && (distance[priority_q[(2 * i) + 1]] < distance[priority_q[min]]))
    {
        min = (2 * i) + 1;
    }

    if (min != i)
    {
        int temp = priority_q[i];
        priority_q[i] = priority_q[min];
        priority_q[min] = temp;
        extract(min);
    }
}