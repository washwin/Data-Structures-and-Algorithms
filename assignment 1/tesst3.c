#include<stdio.h>
#include<stdlib.h>
FILE *op=fopen("toh2.txt","w");
struct Stack
{
   int size;
   int top=0;
   char name;
   int stack[];
};
struct Stack A,B,C;    
bool isOverflowing( struct Stack s)
{
    if (s.top>s.size+1)
    {
        printf("Stack %c is overflowing\n", s.name);
        return 1;
    }
    else
    {
        return 0;
    }    
}

bool isUnderflowing(struct Stack s)
{
    if (s.top<-1)
    {
        printf("Stack %c is underflowing\n", s.name);
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int pop(struct Stack s,int n)
{
    if(isUnderflowing(s))
    {
        exit;
    }
    else
    {
        s.stack[s.top]=0;
        s.top--;
        fprintf(op,"Pop disk %d from stack %c\n", n , s.name);
    }
}

int push(struct Stack s,int n)
{
    s.top++;
    if(isOverflowing(s))
    {
        exit;
    }
    else
    {
        s.stack[s.top]=n;
        fprintf(op,"Push disk %d to stack %c\n", n, s.name);
    }
}

int TowerOfHanoi(int n,struct Stack from, struct Stack to, struct Stack temp)
{
    if (n==0)
    {
        return 0;
    }

    TowerOfHanoi(n-1,from,temp,to);

    pop(to,n);

    push(from,n);
    

    TowerOfHanoi(n-1,temp,to,from);
}
int main(int argc, char* argv[])
   {

    int  n,i=1;
    n=atoi(argv[1]);
          
    A.size=n;
    B.size=n;
    C.size=n;
    A.name='A';
    B.name='B';
    C.name='C';

    while(1)
    {
        A.stack[A.top]=i;
        A.top++;
        i++;
        
        if(A.top>n)
        break;
    }
    A.top--;
  

    TowerOfHanoi(n,A,C,B);
    return 1;

   }

if (/* condition */)
{
    /* code */
}
