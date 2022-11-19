#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
    FILE *in, *op;
    in=fopen(argv[1],"r");
    op=fopen("output.txt","w");
    int cnt=0;
    int x;

    while((fscanf(in,"%d",&x)) != EOF)
        cnt++;

    fprintf(op,"%d\n",cnt);
    fclose(in);
    in=fopen(argv[1],"r");


    int mi,ma;
    fscanf(in,"%d",&mi);
    while(fscanf(in,"%d",&x) != EOF)
    {
        if(mi>x)
            mi=x;
    }
    fprintf(op,"%d\n",mi);
    fclose(in);
    in=fopen(argv[1],"r");


    fscanf(in,"%d",&ma);
    while(fscanf(in,"%d",&x) != EOF)
    {
        if(ma<x)
            ma=x;
    }
    fprintf(op,"%d\n",ma);
    fclose(in);
    in=fopen(argv[1],"r");

    float sum=0;
    while(fscanf(in,"%d",&x) != EOF)
        sum+=x;

    fprintf(op,"%0.0f\n",sum);

    float avg;
    avg=sum/cnt;
    fprintf(op,"%0.2f",avg);

}
