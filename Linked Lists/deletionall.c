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
void delete(struct node* first)
{ struct node* new_node;
    struct node *temp;
    new_node=first;
    while(new_node!=NULL)
    {
        temp=new_node;
        new_node->next;
        free(temp);
    }
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
   delete(ps);
    PrintList(ps);
    return 0;
}