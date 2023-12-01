#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *next;
};
void insert(struct node **first,int n)
{
    struct node* new_node;
    new_node=malloc(sizeof(struct node));
    new_node->value=n;
    new_node->next=*first;
    *first=new_node;
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
    insert(&ps,7);
    insert(&ps,5);
    insert(&ps,9);
    insert(&ps,1);
    insert(&ps,2);
    PrintList(ps);
    return 0;
}