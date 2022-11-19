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
struct  Stack A,B,C;                    // Three towers respectively

int isOverflowing(struct Stack s)       //A function to check overflowing of stack
{
    if((s.top)+1 == (s.size))
    {
        fprintf(op,"Stack %c is Overflowing", s.name);
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isUnderflowing(struct Stack s)       //A function to check underflowing of stack
{
    if((s.top) <-1)
    {
        fprintf(op,"Stack %c is Underflowing", s.name);
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(){
    if (isUnderflowing(A)<0)
    {
        /* code */
        printf("working\n");
    }
    if(isUnderflowing(A)>0){
        printf("also working");
    }
}