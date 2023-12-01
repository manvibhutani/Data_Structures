#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *next;
};
void insert(struct node **first, int n)
{
    struct node *new_node;
    new_node=malloc(sizeof(struct node));
    new_node->value=n;
    new_node->next=NULL;
    if(*first==NULL)
    {
        *first=new_node;
        return;
    }
    struct node *temp=*first;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}
void PrintList(struct node* first)
{
    while(first!=NULL)
    {
        printf("%d\n", first->value);
        first=first->next;
    }
}
int main()
{
    struct node *ps=NULL;
    
   
    insert(&ps,8);
    insert(&ps,5);
    insert(&ps,2);
    insert(&ps,1);
    insert(&ps,7);
    insert(&ps,4);
      PrintList(ps);
    return 0;
}