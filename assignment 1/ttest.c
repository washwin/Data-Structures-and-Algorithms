/*Assignment 1; 210010060; Ashwin Waghmare;
This is a program to solve the problem 'Tower of Hanoi' using
the concept of stacks. Three stacks are created namely, 'A', 'B', 
'C' representing individual towers*/
#include<stdio.h>
#include<stdlib.h>
FILE *op=fopen("toh.txt","w");

struct Stack
{
   int size;
   int top=-1;
   char name;
   int stack[];
};
struct  Stack A,B,C;

bool isOverflowing(struct Stack s)       //A function to check overflowing of stack
{
    if((s.top) > (s.size))
    {
        fprintf(op,"Stack %c is Overflowing", s.name);
        return 0;
    }
    else
    {
        return 1;
    }
}

bool isUnderflowing(struct Stack s)       //A function to check underflowing of stack
{
    if((s.top) < 0)
    {
        fprintf(op,"Stack %c is Underflowing", s.name);
        return 1;
    }
    else
    {
        return 0;
    }
}

int Pop(struct Stack s,int n)                //A fucntion to pop element from stack
{
   if(isUnderflowing)
   {
      exit;
   }

   fprintf(op,"Pop disk %d from stack %c\n", n , s.name);
}

int Push(struct Stack s,int n)            // A function to push elements to stack
{
   if(isOverflowing)
   {
      exit;
   }

   s.top++;
   s.stack[s.top] = n;
   fprintf(op,"Push disk %d to stack %c\n", s.stack[s.top], s.name);
}

int TowerOfHanoi(int n, struct Stack from, struct Stack to, struct Stack temp)         //A function 
   {
    if(n==0)
    return 0;

    TowerOfHanoi(n-1,from,temp,to);

    Pop(from,n);
    Push(to,n);

    TowerOfHanoi(n-1,temp,to,from);
   }

int main(int argc, char* argv[])
   {
    int  n;
    n=atoi(argv[1]);  
    A.size=n;
    A.name='A';
    B.size=n;
    B.name='B';
    C.size=n;
    C.name='C';       

    for(int i=n;i>=1;i--)
    {
      Push(A,i);
    }

    TowerOfHanoi(n,A,C,B);
    fclose(op);
    return 1;
}