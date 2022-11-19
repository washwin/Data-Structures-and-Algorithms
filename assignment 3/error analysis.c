#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
    FILE *a,*b;
    a=fopen(argv[1],"r");
    b=fopen(argv[2],"r");

    float n=0,m=0;
    char x,y;

    while(fscanf(a,"%c",&x)!=EOF)
    {
        n++;
        printf("%c ",x);
        fscanf(b,"%c",&y);
        printf("%c\n",y);
        if(x!=y)      
        m++;
    }
    float ac,e;
    ac=(n-m)/n;
    e=(m)/n;
    printf("%f of %f correct\n",n-m,n);
    printf("Accuracy = %f\n %",ac*100);
    printf("%f of %f wrong\n",m,n);
    printf("Error = %f\n %",e*100);
}