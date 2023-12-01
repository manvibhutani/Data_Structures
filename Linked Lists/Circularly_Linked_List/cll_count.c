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
int count(NODEPTR a)
{
if(a==NULL)
{
    printf("empty list");
    return 0;
}
int k=0;
NODEPTR cur=a;
do{
    k+=1;
    cur=cur->next;
}while(cur!=a);
return k;
}
int main()
{
    NODEPTR a=NULL;
    a=InsertNode(a,9);
    
     a=InsertNode(a,3);
    
     a=InsertNode(a,4);
    printf("%d\n", count(a));


    return 0;
}
