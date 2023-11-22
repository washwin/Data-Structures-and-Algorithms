/*DSA Assignment#3
Ashwin Waghmare 210010060
A program to sort numbers given through input file, using radix sort method*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void counting(int A[], int n, int s);

void radix(int A[], int n, int s);

int main(int argc, char *argv[])
{
    FILE *in, *op;
    in = fopen(argv[1], "r");
    op = fopen("radix.txt", "w");
    int n;
    n = atoi(argv[2]);

    int size = 0;
    int x;
    while ((fscanf(in, "%d", &x)) != EOF)
    {
        size++;
    }
    rewind(in);

    int i;
    i = 0;
    int A[size];
    while ((fscanf(in, "%d", &A[i])) != EOF)
    {
        i++;
    }

    radix(A, n, size);

    for (int i = 0; i < size; i++)
    {
        fprintf(op, "%d\n", A[i]);
    }

    fclose(in);
    fclose(op);
}

void radix(int A[], int n, int s)
{
    for (int i = 1; i <= n; i++)
    {
        counting(A, i, s);
    }
}

void counting(int A[], int n, int s)
{
    int ds[s], B[s];

    for (int i = 0; i < s; i++)
    {
        B[i] = A[i];
    }

    for (int i = 0; i < s; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ds[i] = B[i] % 10;
            B[i] = B[i] / 10;
        }
    }

    int dc[10];
    for (int i = 0; i < 10; i++)
    {
        dc[i] = 0;
    }

    for (int i = 0; i < s; i++)
    {
        dc[ds[i]]++;
    }

    for (int i = 1; i < 10; i++)
    {
        dc[i] = dc[i] + dc[i - 1];
    }

    int aux[s];
    for (int i = s - 1; i >= 0; i--)
    {
        aux[dc[ds[i]] - 1] = A[i];
        dc[ds[i]]--;
    }

    for (int i = 0; i < s; i++)
    {
        A[i] = aux[i];
    }
}
