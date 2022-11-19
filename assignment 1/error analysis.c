#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
    FILE *a,*b;
    a=fopen(argv[1],"r");
    b=fopen(argv[2],"r");

    int n=0,m=0;
    char x[50],y[50];
    while(fscanf(a,"%c",&x)!=EOF)
    {
        n++;
        fscanf(b,"%c",&y);
        if(x!=y)      
        m++;
    }
    float ac,e;
    ac=(float)(m-n)/n;
    e=(float)(m)/n;
    printf("%d of %d correct\n",m-n,n);
    printf("Accuracy = %f\n %",ac*100);
    printf("%d of %d wrong\n",m,n);
    printf("Error = %f\n %",e*100);
}