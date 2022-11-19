/*Exam Assignment
Ashwin Waghmare
210010060
A program to implement Topological sort*/
#include<stdio.h>
#include<stdlib.h>

void push();
void dfs();

struct vertex
{             
    int data;
    struct vertex *next;
};
struct vertex * vlist[9999];

struct stack
{                 
    int data;
    struct stack *next;
};
struct stack *top = NULL; 

int time = 0;
int color[9999];
int discover[9999];
int finished[9999];

int main(int argc, char *argv[])
{   
    FILE *in;
    in = fopen(argv[1], "r");
    if(in == NULL)
    {
        printf("input file does not exist\n");
        exit(1);
    }

    int m, n;
    fscanf(in, "%d %d\n", &n, &m); 

    int i, v1, v2;
    for(i = 0; i < n; i++)
    {
        color[i] = 0;                
        discover[i] = -1;
        vlist[i] = NULL;
        finished[i] = -1;
    }
 
    while(fscanf(in, "%d %d\n", &v1, &v2) != EOF)
    {
        struct vertex *newnode = malloc(sizeof(struct vertex));
        if(newnode != NULL)                  
        {
            newnode->data = v2;
        }
        else
        {
           printf("\nMemory Insufficient!");
           exit(4);
        }
        newnode->next = vlist[v1];
        vlist[v1] = newnode;
    }
    fclose(in);
    
    for(i = 0; i < n; i++)                          
    {
        if(color[i] == 0)                         
        {
            dfs(i);                              
        }
    }
    
    FILE *op;
    op = fopen("ts.txt", "w");
    struct stack *t;
    int v;
    while(top !=  NULL)
    {
        t = top;             
        v = t->data;
        top = top->next;
        free(t);
        fprintf(op, "%d\n", v);
    }
    fclose(op);
    return 0;
}

void dfs(int i)
{
    color[i] = 1;
    time++;
    discover[i] = time;
    struct vertex *traversal;
    traversal = vlist[i];
    
    while(traversal != NULL)
    {
        if(color[traversal->data] == 0)
        {
            dfs(traversal->data);
        }
        traversal = traversal->next;
    }
    
    time++;
    finished[i] = time;
    color[i] = 2;
    push(i);
}

void push(int n)
{
    struct stack *newnode = (struct stack*)malloc(sizeof(struct stack));
    newnode->data = n;
    newnode->next = NULL;
    if(top == NULL)
    {
        top = newnode;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
}
