//Manvi, 12213106
#include<stdio.h>
#include<stdlib.h>
struct tree{
    int value;
    struct tree *left;
    struct tree *right;
};
typedef struct tree* NODEPTR;
NODEPTR maketree(int val)
{
    NODEPTR p;
    p=malloc(sizeof(struct tree));
    p->value=val;
    p->left=NULL;
    p->right=NULL;
    return p;
    }
void setleft(NODEPTR a, int x)
{
    if(a==NULL)
    {
        printf("Void!");
        return;
    }
    if(a->left!=NULL)
    {
        printf("Invalid insertion");
        return;
    }
    else{
        a->left=maketree(x);
    }
}
void setright(NODEPTR a, int x)
{
    if(a==NULL)
    {
        printf("Void!");
        return;
    }
    if(a->right!=NULL)
    {
        printf("Invalid insertion");
        return;
    }
    else{
        a->right=maketree(x);
    }
}
void pretrav(NODEPTR p)
{
    if(p!=NULL)
    {
        printf("%d ",p->value);
    pretrav(p->left);
    pretrav(p->right);
    }
   
}
void intrav(NODEPTR p)
{
    if(p!=NULL)
    {
        intrav(p->left);
        printf("%d ",p->value);
    intrav(p->right);
    }
    
}
void postrav(NODEPTR p)
{
    if(p!=NULL)
    {
        postrav(p->left);
    postrav(p->right);
        printf("%d ",p->value);
    
    }
   
}
int main()
{
    NODEPTR a;
    a=maketree(7);
    setleft(a,6);
    setright(a,4);
    setleft(a->left,3);
    setright(a->left,2);
    setleft(a->left->left,9);
    setright(a->left->left,11);
    pretrav(a);
    printf("\n");
    intrav(a);
    printf("\n");
    postrav(a);
    return 0;
    
}
