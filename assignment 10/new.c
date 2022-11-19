#include <stdio.h>
#include <stdlib.h>

struct vertex
{
    int data;
    int weight;
    struct vertex *next;
};

int main(int argc, char *argv[])
{
    int u, v, w, i, totaledges = 0;
    struct vertex *vlist[6000];
    int distance[6000], visited[6000];
    for (i = 0; i < 6000; i++)
    {
        vlist[i] = NULL;
        distance[i] = 99999;
        visited[i] = 0;
    }

    FILE *in;
    in = fopen(argv[1], "r");
    while (fscanf(in, "%d %d %d", &u, &v, &w) != EOF)
    {
        struct vertex *newnode = malloc(sizeof(struct vertex));
        newnode->data = v;
        newnode->weight = w;
        newnode->next = vlist[u];
        vlist[u] = newnode;
        totaledges++;
    }
    fclose(in);

    int source, cnt = 0;
    source = atoi(argv[2]);
    distance[source] = 0;
    int q[totaledges+1]; // priority queue
    q[0] = source;

    struct vertex *temp;
    i = 1; 
    while (cnt != totaledges+1)
    {
        if (visited[q[cnt]] == 0)
        {
            temp = vlist[q[cnt]];
            while (temp != NULL)
            {
                q[i] = temp->data;
                temp = temp->next;
                i++;
                printf("%d|",cnt);
            }
            visited[q[cnt]] = 1;
        }
        cnt++;
    }

for(i=0;i<totaledges;i++)
printf("%d|",q[i]);
    while (temp != NULL)
    {
        if (distance[source] + temp->weight < distance[temp->data])
        {
            distance[temp->data] = distance[source] + temp->weight;
        }
        temp = temp->next;
    }
}