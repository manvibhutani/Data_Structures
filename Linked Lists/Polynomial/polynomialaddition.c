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
            printf("%dx^%d",poly->cof,poly->exp);
        }
        if(poly->exp==0)
        {
            if(poly->cof>0) 
        {
            printf("+%d",poly->cof);
        }
        if(poly->cof<0)
        {
            printf("%d",poly->cof);
        }
        }
    poly=poly->link;
    }
    printf("\n");
}
struct PolyNode *PolyAdd(struct PolyNode *a, struct PolyNode *b)
{
    struct PolyNode *result=NULL;
    while(a!=NULL && b!=NULL)
    {
        if(a->exp==b->exp)
        {
            insert(&result,a->cof+b->cof,a->exp);
            a=a->link;
            b=b->link;
        }
        else if(a->exp>b->exp)
        {
            insert(&result,a->cof,a->exp);
            a=a->link;
            
        }
        else if(a->exp<b->exp)
        {
            insert(&result,b->cof,b->exp);
            
            b=b->link;
        }
        else{
            while(a!=NULL)
    {
        insert(&result,a->cof,a->exp);
        a=a->link;
    }
    while(b!=NULL)
    {
        insert(&result,b->cof,b->exp);
        b=b->link;
    }
        }
    }
    
return result;
}
int main()
{
    struct PolyNode *b=NULL;
    struct PolyNode *c=NULL;
    struct PolyNode *add=NULL;
    
    
    ReadPoly(&b);
    PrintPoly(b);
    ReadPoly(&c);
    PrintPoly(c);
    add=PolyAdd(b,c);
    PrintPoly(add);
    
    return 0;
}
// The above code adds the two polynomials, However this method doesn't happen to be efficient. We know that the insertatlast function takes O(n) time to get to the last node. since this function is called as many times as the approximately the terms in the polynomials, it's efficiency decreases. So we define another function which returns the pointer of the last node itself. We didn't use the function as such in the insertatlast before because in that case the pointer of the first node would have been lost. But in the case of polynomial addition we don't really require the lost pointer and the additon can still take place and moreover increase the efficiency of the program.