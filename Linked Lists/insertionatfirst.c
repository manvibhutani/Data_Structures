#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *next;
};
struct node* insert(struct node *first,int n)
{
    struct node* new_node;
    new_node=malloc(sizeof(struct node));
    new_node->value=n;
    new_node->next=first;
    first=new_node;
    return first;
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
    ps=insert(ps,4);
    ps=insert(ps,6);
    PrintList(ps);
    return 0;
}