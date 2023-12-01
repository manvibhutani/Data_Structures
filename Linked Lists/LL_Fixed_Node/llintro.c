#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int value;
    struct node *next;
};
void CreateEmpty(struct node **a)
{
    *a=malloc(sizeof(struct node));
    (*a)->next=NULL;
}
void insert(struct node *ptr,struct node *list,int x)
{
    struct node *cur=list;
    
    struct node *new_node;
    new_node=malloc(sizeof(struct node));
    new_node->value=x;

    new_node->next=cur->next;
    list->next=new_node;
}
bool isEmpty(struct node* first)
{
    if(first->next==NULL)
    return true;
    else 
    return false;
}
void delete(struct node* ptr,struct node *list)
{
    if(isEmpty(ptr))
    {
        printf("cannot delete elements from empty list");
        return;
    }
    struct node *cur=list;
    cur=cur->next;
    list->next=cur->next;
    free(cur);
}

void PrintList(struct node *NODE)
{
    struct node *cur;
    cur=NODE->next;
    while(cur!=NULL)
    {
        printf("%d ", cur->value);
        cur=cur->next;
    }
}
int main()
{
    struct node *first;
    CreateEmpty(&first);
    insert(first,first,9);
    insert(first,first,1);
    insert(first,first,12);
    insert(first,first,4);
    
    PrintList(first);
    delete(first,first);
    PrintList(first);
    
    return 0;
}