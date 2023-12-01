#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node* next;
    struct node* prev;
};
struct node* insert(struct node *a, int x)
{
    struct node* nn;
    nn=malloc(sizeof(struct node));
    nn->val=x;
    if(a==NULL)
    {
        nn->prev=NULL;
        nn->next=NULL;
    }
    else{
        nn->next=a;
        a->prev=nn;
        a=nn;
    }
}
void PrintList(struct node *a)
{
    while(a!=NULL)
    {
        printf("%d ",a->val);
        a=a->next;
    }
}
int main()
{
    struct node* first;
    first=malloc(sizeof(struct node));
    first=insert(first,5);
    PrintList(first);
    return 0;
}