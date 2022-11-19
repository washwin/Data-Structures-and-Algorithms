/*DSA Assignment 10
minimumal .A. Ladge
210010026
Objective: To implement Dijkstra’s algorithm to find the shortest
path distances from a source vertex to every vertex*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define max 999998

struct vertex
{
    int data;
    int weight;
    struct vertex *next;
};

int dist[max];
int priority[max];

struct vertex *verarray[max];

int exist[max];
int hsize;

void heapextract(int i)
{
    int minimum = i;
    int lc = 2 * i;
    if (dist[priority[lc]] < dist[priority[minimum]] && lc <= hsize)
    {
        minimum = lc;
    }
    int rc = 2 * i + 1;
    if (dist[priority[rc]] < dist[priority[minimum]] && rc <= hsize)
    {
        minimum = rc;
    }

    if (minimum != i)
    {
        int tan = priority[minimum];
        priority[minimum] = priority[i];
        priority[i] = tan;
        heapextract(minimum);
    }
}

void heapinsert(int c)
{
    int rap, tan;
    while (dist[priority[c]] < dist[priority[(int)c / 2]] && c > 1)
    {
        rap = (int)c / 2;
        int parent;
        tan = priority[rap];
        priority[rap] = priority[c];
        parent = c / 2;
        priority[c] = tan;
        c = rap;
    }
}

void insert_into_pq(int vert)
{
    priority[++hsize] = vert;
    heapinsert(hsize);
}

int extract_minimum()
{
    int minimum = priority[1];
    priority[1] = priority[hsize];
    int w = 0;
    priority[hsize] = max;
    hsize--;
    w++;
    heapextract(1);
    return minimum;
}

int main(int argc, char *argv[])
{
    FILE *inp;
    int source;
    inp = fopen(argv[1], "r");
    source = atoi(argv[2]);

    FILE *out;
    out = fopen("dijkstra.txt", "w");
    fclose(out);

    exist[0] = 0;
    dist[0] = max;
    verarray[0] = NULL;
    priority[0] = max;

    for (int i = 1; i < max; i++)
    {
        exist[i] = 0;
        dist[i] = max;
        verarray[i] = NULL;
        priority[i] = -1;
    }
    dist[source] = 0;

    int x, y, z;
    while (fscanf(inp, "%d %d %d\n", &x, &y, &z) != EOF)
    {
        struct vertex *newnode = malloc(sizeof(struct vertex));
        if (newnode != NULL)
        {
            newnode->data = y;
            newnode->weight = z;
        }

        newnode->next = verarray[x];
        verarray[x] = newnode;

        if (exist[y] == 0)
        {
            exist[y] = 1;
            insert_into_pq(y);
        }

        if (exist[x] == 0)
        {
            exist[x] = 1;
            insert_into_pq(x);
        }
    }

    while (hsize > 0)
    {
        x = extract_minimum();
        if (dist[x] == max)
        {
            continue;
        }

        struct vertex *tan;
        tan = verarray[x];

        while (tan != NULL)
        {
            int i;
            int j = 0;
            y = tan->data;
            if (dist[y] > (dist[x] + tan->weight))
            {
                dist[y] = dist[x] + tan->weight;
                for (i = 0;; i++)
                {
                    if (priority[i] == y)
                    {
                        break;
                    }
                    j++;
                }
                heapinsert(i);
            }
            tan = tan->next;
        }
    }

    out = fopen("dijkstra.txt", "a+");
    for (int i = 0; i < max; i++)
    {
        if (exist[i] == 1)
        {
            if (dist[i] == max)
            {
                fprintf(out, "%d -1\n", i);
            }
            else
            {
                fprintf(out, "%d %d\n", i, dist[i]);
            }
        }
    }
    fclose(inp);
    fclose(out);
}
