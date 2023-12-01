#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
struct queue
{
    int value[maxsize];
    int rear,front;
};
void PrintQueue(struct queue *a)
{
    int i;
    for(i=a->front; i<=a->rear; i++)
    {
        printf("%d ", a->value[i]);
    }
    printf("\n");
}
void insert(struct queue *a, int x)
{
    a->value[++a->rear]=x;
}
int delete(struct queue *b)
{
    return b->value[b->front++];
}
int main()
{
    struct queue *a;
    a->rear=-1;
    a->front=0;
    insert(a,6);
    insert(a,3);
    insert(a,1);
    insert(a,2);
    PrintQueue(a);
    delete(a);
    PrintQueue(a);
    return 0;
}