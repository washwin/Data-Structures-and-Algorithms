/*Ashwin Waghamre 
210010060
A program to print anagrams and implement hashing*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void hash();
void print_words();
int anagram();

struct node{
    char word[20];
    struct node *next;             
};

int main(int argc, char *argv[])
{
    FILE *in1, *in2;
    int m,sum;
    m=atoi(argv[2]);
    FILE *op;
    op = fopen("anagrams.txt","w");
    fclose(op);

    struct node *head[m];
    for(int i=0; i<m; i++)
    {
        head[i] = NULL;
    }
    
    char word[30];
    in1= fopen(argv[1],"r");
    while (fgets(word, 30, in1) != NULL)
    {
        sum=0;
        word[strlen(word)-1]='\0';
        for(int i=0; i<strlen(word); i++) 
        {
            sum += word[i];
        }
        sum = sum%m;
        hash(&head[sum], word);
    }
    fclose(in1);
    
    in2= fopen(argv[3],"r");
    while (fgets(word, 20, in2) != NULL)
    {
        /* code */
        sum=0;
        word[strlen(word)-1]='\0';
        for(int i=0; i<strlen(word); i++)
        {
            sum += word[i];
        }
        sum = sum%m;
        print_words(&head[sum], word);
    }
    fclose(in2);
    return(0);
}

void hash(struct node **head, char *word)
{
    struct node *newnode = malloc(sizeof(struct node));

    newnode->next = NULL;
    strcpy(newnode->word, word);

    if (*head == NULL) 
    {                     
        *head = newnode;
    }

    else
    { 
        newnode->next = *head;
        *head = newnode;
    }
}

void print_words(struct node **head, char *word)
{
    FILE *op;
    op = fopen("anagrams.txt","a");
    struct node *tr;
    tr = *head;
    int f;
    char output[90];
    strcpy(output,"");

    char w1[30],w2[30];
    strcpy(w1,word);

    while (tr != NULL)
    {
        strcpy(w2,tr->word);
        f=anagram(w1,w2);
        if(f==1)
        {

            strcat(output,w2);
            strcat(output," ");

        }

        tr=tr->next;

    }
    output[strlen(output)-1]='\0';
    fprintf(op,"%s",output);
    fprintf(op,"\n");

    fclose(op);
}

int anagram(char word1[], char word2[])
{
    int w1[90]={0};
    int w2[90]={0};
    int i=0;

    while (word1[i]!= '\0')
    {
        /* code */
        if (word1[i]>=65)
        {
            w1[word1[i] - 65]++;
        }
        if(word1[i] >= 48 && word1[i] <= 57)
        {
            w1[word1[i] - 48 + 70]++;
        }
        if(word1[i] == '\'')
        {
            w1[89]++;
        }
        i++;
    }
    
    i=0;
    while (word2[i]!= '\0')
    {
        /* code */
        if (word2[i]>=65)
        {
            w2[word2[i] - 65]++;
        }
        
        if(word2[i] >= 48 && word2[i] <= 57)
        {
            w2[word2[i] - 48 + 70]++;
        }
        
        if(word2[i] == '\'')
        {
            w2[89]++;
        }
        i++;
    }

    for(i = 0; i < 90; i++)
    {
        if (w1[i] != w2[i])
        {
           return 0; 
        }
    }
    return 1;  
}