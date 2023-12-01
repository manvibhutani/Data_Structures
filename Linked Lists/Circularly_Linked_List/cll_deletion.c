#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
};
typedef struct node *NODEPTR;
NODEPTR InsertNode(NODEPTR a,int x)
{
    NODEPTR new_node;
    new_node=malloc(sizeof(struct node));
    new_node->value=x;
    if(a==NULL)
    {
        new_node->next=new_node;
        a=new_node;
        return a;
    }
    else
    {
        new_node->next=a->next;
        a->next=new_node;
        return a;
    }
}
NODEPTR DeleteNode(NODEPTR a)
{
    if(a==NULL)
    {
        printf("List is empty");
    }
    else if(a==a->next)
    {
        NODEPTR temp=a;
        a=NULL;
        free(temp);
        return a;
    }
    else{
        NODEPTR temp=a->next;
        a->next=temp->next;
    }
}
void PrintList(NODEPTR a)
{
if(a==NULL)
{
    printf("empty list");
    return;
}
NODEPTR cur=a;
do{
    printf("%d ",cur->value);
    cur=cur->next;
}while(cur!=a);
printf("\n");
}
int main()
{
    NODEPTR a=NULL;
    a=InsertNode(a,9);
    PrintList(a);
     a=InsertNode(a,3);
    PrintList(a);
     a=InsertNode(a,4);
    PrintList(a);
    a=InsertNode(a,5);
    PrintList(a);
    a=InsertNode(a,1);
    PrintList(a);
    PrintList(a->next);
    PrintList(a->next->next);
    a=DeleteNode(a);
    PrintList(a);
    a=DeleteNode(a);
    PrintList(a);
    a=DeleteNode(a);
    PrintList(a);
    a=DeleteNode(a);
    PrintList(a);
    a=DeleteNode(a);
    PrintList(a);
    
    

    return 0;
}
