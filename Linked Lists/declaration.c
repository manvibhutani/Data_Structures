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
int main()
{
    struct node *ps=NULL;
    
    
    struct node *new_node;
    new_node=malloc(sizeof(struct node));
    new_node->value=10;
    new_node->next=ps;
    ps=new_node;
    new_node=malloc(sizeof(struct node));
    new_node->value=20;
    new_node->next=ps;
    ps=new_node;
    PrintList(ps);
    return 0;
}