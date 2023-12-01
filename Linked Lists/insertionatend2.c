#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node* next;
};
struct node *insert(struct node* ps, int x)
{
    struct node *a;
    a=malloc(sizeof(struct node));
    a->value=x;
    a->next=NULL;
    if(ps==NULL)
    {
        ps=a;
        return ps;
    }
    else{
        struct node *temp;
        temp=ps;
        while(ps->next!=NULL)
        {
            ps=ps->next;
        }
        ps->next=a;
        ps=temp;
        return temp;
    }
}
void delete(struct node **ps)
{
    struct node *a;
    a=*ps;
    (*ps)=(*ps)->next;
    free(a);
}
void PrintList(struct node* ps)
{
while(ps!=NULL)
{
    printf("%d ",ps->value);
    ps=ps->next;
}
}
int main()
{
    struct node *a;
    struct node *b=NULL;
    a=malloc(sizeof(struct node));
    a->value=10;
    a->next=b;
    b=a;
    b=malloc(sizeof(struct node));
    b->value=9;
    b->next=a;
    a=b;
    a=insert(a,8);
    a=insert(a,1);
    PrintList(a);
delete(&a);
PrintList(a);
    return 0;
}