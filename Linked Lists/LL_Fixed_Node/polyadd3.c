#include<stdio.h>
#include<stdlib.h>
struct PolyNode
{
    int cof,exp;
    struct PolyNode *link;
};
void CreateEmpty(struct PolyNode **a)
{
    *a=malloc(sizeof(struct PolyNode));
    (*a)->link=NULL;
}
void attach(struct PolyNode **list,int c, int e)
{
    struct PolyNode *new_node;
    new_node=malloc(sizeof(struct PolyNode));
    new_node->cof=c;
    new_node->exp=e;
    new_node->link=NULL;
    (*list)->link=new_node;
    *list=new_node;
    
}
void PrintPoly(struct PolyNode *poly)
{
    struct PolyNode *cur=poly->link;
    while(cur!=NULL)
    {
        if(cur->cof>0 && cur->exp>0) 
        {
            printf("+%dx^%d",cur->cof,cur->exp);
        }
        if(cur->cof<0 && cur->exp>0)
        {
            printf("%dx^%d",cur->cof,cur->exp);
        }
        if(cur->exp==0)
        {
            if(cur->cof>0) 
        {
            printf("+%d",cur->cof);
        }
        if(cur->cof<0)
        {
            printf("%d",cur->cof);
        }
        }
    cur=cur->link;
    }
    printf("\n");
}
void ReadPoly(struct PolyNode *a)
{int n,i;
    printf("enter no. of terms in your polynomial expression\n");
    scanf("%d", &n);
    int k,p;
    printf("Enter coeffecient and exponent of the terms\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &k,&p);
        attach(&a,k,p);
    }
}
struct PolyNode *PolyAdd(struct PolyNode *a, struct PolyNode *b)
{
    struct PolyNode *result;
    CreateEmpty(&result);
    struct PolyNode *cur1=a->link;
    struct PolyNode *cur2=b->link;

    while(cur1!=NULL && cur2!=NULL)
    {
        if(cur1->exp==cur2->exp)
        {
            attach(&result,cur1->cof+cur2->cof,cur1->exp);
            cur1=cur1->link;
            cur2=cur2->link;
        }
        else if(cur1->exp>cur2->exp)
        {
            attach(&result,cur1->cof,cur1->exp);
            cur1=cur1->link;
            
        }
        else if(cur1->exp<cur2->exp)
        {
            attach(&result,cur2->cof,cur2->exp);
            
            cur2=cur2->link;
        }
        else{
            while(cur1!=NULL)
    {
        attach(&result,cur1->cof,cur1->exp);
       cur1=cur1->link;
    }
    while(cur2!=NULL)
    {
        attach(&result,cur2->cof,cur2->exp);
        cur2=cur2->link;
    }
        }
    }
    
return result;
}
int main()

{
    struct PolyNode *add;
    
    struct PolyNode *a;
  CreateEmpty(&a);
  ReadPoly(a);
  PrintPoly(a);
  struct PolyNode *b;
  CreateEmpty(&b);
  ReadPoly(b);
  PrintPoly(b);
  add=PolyAdd(a,b);
  PrintPoly(add);
    
}