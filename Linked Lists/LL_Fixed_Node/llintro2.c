#include<stdio.h>
#include<stdlib.h>
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
void insert(struct node **list,int x)
{
    struct node* new_node;
    new_node->value=x;
    new_node->next=NULL;
    if(*list==NULL)
    {
        CreateEmpty(list);
        (*list)->next=new_node;
    }
    new_node->value = x;
	  (*list)->next = new_node;
	  *list = new_node;

}
void delete(struct node *list)
{
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
    insert(&first,9);
    insert(&first,1);
    insert(&first,12);
    insert(&first,4);
    
    PrintList(first);
    return 0;
}