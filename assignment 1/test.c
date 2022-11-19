#include<stdio.h>
#include<stdlib.h>
struct sll{

int data;
struct sll *next;

};
int a[5];
void cs201()
{
struct sll *sllnewnode=(struct sll*)malloc(sizeof(struct sll));
printf("%d\n", sizeof(a));
printf("%d\n", sizeof(sllnewnode));
printf("%d\n", sizeof(sllnewnode)*5);
}
int main() {
cs201();
return 0;
}