#include<stdio.h>
#include<stdlib.h>
FILE *op=fopen("testie.txt","w");
struct Stack
{
   int size;
   int top=-1;
   char name;
   int stack[];
};


bool isOverflowing(struct Stack *s)
{
    if((s->top) > (s->size))
    {
        printf("Stack %c is Overflowing", s->name);
        return 0;
    }
    else
    {
        return 1;
    }
}

bool isUnderflowing(struct Stack *s)
{
    if((s->top) < 0)
    {
        printf("Stack %c is Underflowing", s->name);
        return 1;
    }
    else
    {
        return 0;
    }
}

int Push(struct Stack *s, int n)
{
    if(isOverflowing)
    {
        exit;
    }
    
    s->top++;
    s->stack[s->top] = n;
    printf("Push disk %d in stack %c \n",n,s->name);
}

int Pop(struct Stack *s)
{
    if(isUnderflowing)
    {
        exit;
    }

    printf("Pop disk %d from stack %c \n",s->stack[s->top],s->name);
    s->top--;
}

int TowerOfHanoi(int n, struct Stack *from, struct Stack *to, struct Stack *temp)
{
    if(n==0)
    {
        return 0;
    }

    TowerOfHanoi(n-1,from,temp,to);

    Pop(from);
    Push(to,n);

    TowerOfHanoi(n-1,temp,to,from);
}

int main(int argc, char* argv[])
{
    struct Stack A,B,C;
    int n,i;
    n=atoi(argv[1]);
    i=n;

    A.size=n;
    A.name='A';
    B.size=n;
    B.name='B';
    C.size=n;
    C.name='C';
    
    while(A.size>A.top + 1)
    {
        Push(&A,i);
        i--;
    }

    TowerOfHanoi(n,&A,&C,&B);
    fclose(op);
}