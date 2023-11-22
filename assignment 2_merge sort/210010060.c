/*DSA Assignment 2
210010060 Ashwin Waghmare
A program to sort inputs in ascending order given through input file., in an
output file named "mergesort.txt" . */
#include <stdio.h>
#include <stdlib.h>

void Merge(int l[], int ln, int r[], int rn, int t[]) // A function to merge array into a sorted one
{
    int lf = 0, rf = 0;

    for (int i = 0; i < (ln + rn); i++)
    {
        if (lf < ln && rf < rn)
        {
            if (l[lf] < r[rf])
            {
                t[i] = l[lf];
                lf++;
            }
            else
            {
                t[i] = r[rf];
                rf++;
            }
        }
        else if (lf < ln)
        {
            t[i] = l[lf];
            lf++;
        }
        else
        {
            t[i] = r[rf];
            rf++;
        }
    }
}

void mergesort(int n, int t[]) // A function to divide array into left and right
{
    if (n == 1)
    {
        return;
    }

    int l[n / 2], r[n - n / 2];
    for (int i = 0; i < n / 2; i++)
    {
        l[i] = t[i];
    }
                                                                      
    for (int i = 0; i < (n - n / 2); i++)
    {
        r[i] = t[i + n / 2];
    }
                     
    mergesort(n / 2, l);
    mergesort(n - n / 2, r);

    Merge(l, n / 2, r, n - n / 2, t);
}

int main(int argc, char *argv[])
{
    FILE *in, *op;
    in = fopen(argv[1], "r");
    op = fopen("mergesort.txt", "w");

    int i, cnt = 0;
    while ((fscanf(in, "%d", &i)) != EOF) // to calculate number of inputs in input file
    {
        cnt++;
    }
    rewind(in);

    int a[cnt];
    i = 0;
    while ((fscanf(in, "%d", &a[i])) != EOF)
    {
        i++;
    }
    fclose(in);

    mergesort(cnt, a);

    for (i = 0; i < cnt; i++) // to print sorted array in output file
    {
        fprintf(op, "%d\n", a[i]);
    }
}