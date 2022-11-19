#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int anagram(char word1[], char word2[])
{
    int w1[60],w2[60];
    int i=0;

    while (word1[i]!= '\0')
    {
        /* code */
        w1[word1[i] - 65]++;
        i++;
        if(word1[i] == '\'')
        {
            w1[100]++;
        }
        if(word1[i] >= 48 && word1[i] <= 57)
        {
            w1[word1[i] - 48 + 80]++;
        }
    }

    while (word2[i]!= '\0')
    {
        /* code */
        w1[word2[i] - 65]++;
        i++;
        if(word2[i] == '\'')
        {
            w1[100]++;
        }
        if(word2[i] >= 48 && word2[i] <= 57)
        {
            w1[word2[i] - 48 + 80]++;
        }
    }

    for(i = 0; i < 52; i++)
    {
        if (w1[i] != w2[i])
        {
           return 0; 
        }
    }
    return 1;  
}
int main(int argc, char *argv[])
{
    int a;
    char w[10],q[10];
    strcpy(w,"ashwin");
    strcpy(q,"niwhsa");
    a=anagram(w,q);
    printf(a);
}