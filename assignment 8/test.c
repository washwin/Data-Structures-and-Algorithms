#include<stdio.h>
#include<stdlib.h>

struct point
{
    /* data */
    int vertex;
    struct point * next;
};

int main(int argc, char* argv[])
{
    FILE *in;
    in=fopen(argv[1],"r");

    int totalvertices, totaledges;
    fscanf(in,"%d",&totalvertices);
    fscanf(in,"%d",&totaledges);
    int location[totalvertices];

    for(int i=0; i<totalvertices; i++)
    {
        struct point *newvertex=malloc(sizeof(struct point));
        location[i]=(int)(newvertex);
        newvertex->next=NULL;
        newvertex->vertex=i;
    }

    int n1, n2;
    struct point *t;
    while (fscanf(in,"%d %d \n", &n1, &n2) != EOF)
    {
        /* code */
        t = (struct point *)(location[n1]);
        while (t->next != NULL)
        {
            t=t->next;
        }
        struct point *newvertex1=malloc(sizeof(struct point));
        t->next=newvertex1;
        newvertex1->vertex=n2;
        newvertex1->next=NULL;

        t = (struct point *)(location[n2]);
        while (t->next != NULL)
        {
            t=t->next;
        }
        struct point *newvertex2=malloc(sizeof(struct point));
        t->next=newvertex2;
        newvertex2->vertex=n1;
        newvertex2->next=NULL;

    }
    fclose(in);

    int distance[totalvertices], visited[totalvertices], order[totalvertices];
    distance[0]=0;
    visited[0]=1;
    order[0]=0;
    for (int i = 1; i < totalvertices; i++)
    {
        /* code */
        distance[i]=-1;
        visited[i]=0;
    }

    struct point *row, *column;
    int j=1;
    FILE * sss;
    sss=fopen("tester.txt","w");
    for (int i=0; i<totalvertices; i++)
    {
        row=(struct point*)(location[order[i]]);
        fprintf(sss,"%d\n",order[i]);
        column=row->next;
        while (column!=NULL)
        {
            if(visited[column->vertex]==0)
            {
                visited[column->vertex]=1;
                distance[column->vertex]=distance[row->vertex]+1;
                order[j]=column->vertex;
                j=j+1;
            }
            //printf("ok\n");
            column=column->next;
        }
        //printf("gg\n");
    }

    FILE *op;
    op=fopen("sd.txt","w");
    printf("heloo");
    for (int i = 0; i < totalvertices; i++)
    {
        /* code */
        fprintf(op,"%d\n",distance[i]);
    }
    fclose(op); 
}

