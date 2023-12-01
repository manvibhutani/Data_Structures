#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *next;
};
void PrintList(struct node* p)
{
    while(p!=NULL)
    {
        printf("%d\n",p->value);
        p=p->next;
    }
}
struct node *delete(struct node* first)
{
    struct node *new_node;
    new_node=first;
    first=new_node->next;
    free(new_node);
    return first; 
}
void insert(struct node **first,int n)
{
    struct node* new_node;
    new_node=malloc(sizeof(struct node));
    new_node->value=n;
    new_node->next=*first;
    *first=new_node;
}
int main()
{
    struct node *ps=NULL;
    insert(&ps,7);
    insert(&ps,2);
    insert(&ps,1);
    insert(&ps,3);
    PrintList(ps);
    ps=delete(ps);
    printf("The edited list is:\n");
    PrintList(ps);
    return 0;
}