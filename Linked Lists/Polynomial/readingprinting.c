#include<stdio.h>
#include<stdlib.h>
struct PolyNode{
    int cof;
    int exp;
    struct PolyNode *link;
};

void insert(struct PolyNode **a, int c, int e)
{
    struct PolyNode *b;
    b=malloc(sizeof(struct PolyNode));
    b->cof=c;
    b->exp=e;
    b->link=NULL;
    if(*a==NULL)
    {
        *a=b;
        return;
    }

    struct PolyNode *temp;
    temp=*a;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=b;
    

}
void ReadPoly(struct PolyNode **poly)
{
    int n,c,d;
    printf("Enter no. of terms in your polynomial expression\n");
    scanf("%d", &n);
    printf("Enter coeffecients and exponenets\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &c,&d);
        insert(poly,c,d);
    }

}
void PrintPoly(struct PolyNode *poly)
{
    while(poly!=NULL)
    {
        if(poly->cof>0 && poly->exp>0) 
        {
            printf("+%dx^%d",poly->cof,poly->exp);
        }
        if(poly->cof<0 && poly->exp>0)
        {
            printf("-%dx^%d",poly->cof,poly->exp);
        }
        if(poly->exp==0)
        {
            if(poly->cof>0) 
        {
            printf("+%d",poly->cof);
        }
        if(poly->cof<0)
        {
            printf("-%d",poly->cof);
        }
        }
    poly=poly->link;
    }
}

int main()
{
    struct PolyNode *b=NULL;
    struct PolyNode *c=NULL;
   
    
    
    ReadPoly(&b);
    PrintPoly(b);
    ReadPoly(&c);
    PrintPoly(c);
    
    return 0;
}