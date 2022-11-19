#include<stdio.h>
#include<stdlib.h>
FILE *op=fopen("toh.txt","w");
struct Stack
{
   int size;
   int top;
   char name;
   int stack[];
};

bool isStackfull(Stack s)
{
    if (s.top==s.size)
    return 1;

    else
    return 0;
}

bool isStackempty(Stack s)
{
    if (s.top== -1)
    return 1;

    else
    return 0;
}

int  pop(Stack s,int n)
{
    if(isStackempty(s))
    {
        printf("stack is empty");
        exit;
    }
    else
    {
        s.stack[s.top]=0;
        s.top--;
        fprintf(op,"Pop disk %d from stack %c\n", n , s.name);
    }
}

int push(Stack s,int n)
{
    if(isStackfull(s))
    {
        printf("stack is full");
        exit;
    }
    else
    {
        s.top++;
        s.stack[s.top]=n;
        fprintf(op,"Push disk %d to stack %c\n", n, s.name);
    }
}

int TowerOfHanoi(int n,Stack from, Stack to, Stack temp)
{
    if (n==0)
    {
        return 0;
    }

    TowerOfHanoi(n-1,from,temp,to);

    push(from,n);
    pop(to,n);

    TowerOfHanoi(n-1,temp,to,from);
}
int main(int argc, char* argv[])
   {

    int  n;
    n=atoi(argv[1]);                
    Stack A,B,C;
    A.size=n;
    B.size=n;
    C.size=n;
    A.name='A';
    B.name='B';
    C.name='C';

    TowerOfHanoi(n,A,B,C);
    return 1;

   }