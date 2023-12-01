#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *next;
};
void insert(struct node **first, int n)
{
    struct node *new_node;
    new_node=malloc(sizeof(struct node));
    new_node->value=n;
    new_node->next=NULL;
    if(*first==NULL)
    {
        *first=new_node;
        return;
    }
    struct node *temp=*first;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}
void PrintList(struct node* first)
{
    while(first!=NULL)
    {
        printf("%d\n", first->value);
        first=first->next;
    }
}
struct node* con(struct node* a, struct node * b)
{
    struct node* nn=a;
    while(a->next!=NULL)
    {
        a=a->next;
    }
    a->next=b;
    return nn;
}
int main()
{
    struct node *ps=NULL;
    struct node* ps1=NULL;
    struct node* add=NULL;
int k=1;
int p;
printf("Enter list elements, and after adding each element press 1 to continue adding element and any other key to stop");
while(k==1)
{
    
    scanf("%d", &p);
    insert(&ps,p);
    scanf("%d",&k);
}
 k=1;
printf("add elements in the second list");
while(k==1)
{
   
    scanf("%d", &p);
    insert(&ps,p);
    scanf("%d",&k);
}
add=con(ps,ps1);
PrintList(add);
    return 0;
}