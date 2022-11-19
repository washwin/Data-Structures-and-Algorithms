#include<stdio.h>
#include<stdlib.h>

int main(){
    int i;
    for( i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(j==3)
            {
                break;
            }
        }
        printf("%d",i);
    }
    printf("%d",i);
}