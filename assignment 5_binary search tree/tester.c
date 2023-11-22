#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    FILE *in;
    in=fopen(argv[1],"r");
    char x[10];
    int i=0,j=0;
    while(fscanf(in,"%s",x)!=EOF)
    { 
        j++;
        if(x=="w")
        {
            i++;
        }
    }
    printf("%s",x);
}