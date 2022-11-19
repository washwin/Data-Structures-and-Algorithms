#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[])
{
    FILE *a,*b;
    a=fopen(argv[1],"r");
    b=fopen(argv[2],"r");

    float n=0,m=0;
    int x,y,x1,x2,y1,y2;
int q=0;
    while(fscanf(a,"%d %d %d",&x1,&x2,&x)!=EOF)
    {
        n++;
        //printf("%c ",x);
        fscanf(b,"%d %d %d",&y1,&y2,&y);
        //printf("%c\n",y);
        //if(x=='\n')
        //q++;

        if(x!=y)  
        {
            printf("%d\n",q);
            m++;
            //printf("```%c```%c```%f\n",x,y,n);
        }    
     
    }
    float ac,e;
    ac=(n-m)/n;
    e=(m)/n;
    printf("%f of %f correct\n",n-m,n);
    printf("Accuracy = %f\n %",ac*100);
    printf("%f of %f wrong\n",m,n);
    printf("Error = %f\n %",e*100);
}