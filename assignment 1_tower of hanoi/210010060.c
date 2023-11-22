/*Assignment 1; 210010060; Ashwin Waghmare;
This is a program to solve the problem 'Tower of Hanoi' using
the concept of stacks. Three stacks are created namely, 'A', 'B',
'C' representing individual towers*/
#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    char name;
    int stack[];
};
struct Stack A, B, C; // Three towers respectively

int isOverflowing(struct Stack s) // A function to check overflowing of stack
{
    FILE *op;
    op = fopen("toh.txt", "a");
    if ((s.top) + 1 == (s.size))
    {
        fprintf(op, "Stack %c is Overflowing", s.name);
        return 1;
    }
    else
    {
        return 0;
    }
    fclose(op);
}

int isUnderflowing(struct Stack s) // A function to check underflowing of stack
{
    FILE *op;
    op = fopen("toh.txt", "a");
    if ((s.top) < -1)
    {
        fprintf(op, "Stack %c is Underflowing", s.name);
        return 1;
    }
    else
    {
        return 0;
    }
    fclose(op);
}

int Pop(struct Stack s, int n) // A fucntion to pop elements from stack
{
    FILE *op;
    op = fopen("toh.txt", "a");
    if (isUnderflowing)
    {
        exit;
    }
    fprintf(op, "Pop disk %d from Stack %c\n", n, s.name);
    fclose(op);
    s.top--;
}

int Push(struct Stack s, int n) // A function to push elements to stack
{
    FILE *op;
    op = fopen("toh.txt", "a");
    if (isOverflowing)
    {
        exit;
    }

    s.top++;
    s.stack[s.top] = n;
    fprintf(op, "Push disk %d to Stack %c\n", s.stack[s.top], s.name);
    fclose(op);
}

int TowerOfHanoi(int n, struct Stack from, struct Stack to, struct Stack temp) // A function to solve tower of hanoi
{
    if (n == 0)
        return 0;

    TowerOfHanoi(n - 1, from, temp, to);

    Pop(from, n);
    Push(to, n);

    TowerOfHanoi(n - 1, temp, to, from);
}

int main(int argc, char *argv[])
{
    int n;
    n = atoi(argv[1]);
    A.size = n; // maximum size set to n
    A.name = 'A';
    B.size = n; // maximum size set to n
    B.name = 'B';
    C.size = n; // maximum size set to n
    C.name = 'C';
    A.top = -1;
    B.top = -1;
    C.top = -1;
    FILE *op;
    op = fopen("toh.txt", "w");
    fclose(op);

    for (int i = n; i >= 1; i--) // initially all disks are pushed to tower A
    {
        Push(A, i);
    }

    TowerOfHanoi(n, A, C, B);

    return 1;
}