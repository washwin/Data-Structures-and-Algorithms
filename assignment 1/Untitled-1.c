#include<stdio.h>
#include<stdlib.h>
struct s
{
    /* data */
    int d;
};
int func(struct s e){
    e.d++;
    printf("%d\n",e.d);
}
int main()
{
    struct s a,b;
    a.d=3;
    b.d=9;
    printf("%d\n",a.d);
    printf("hello\n");
    func(b);
    printf("%d",b.d);
}