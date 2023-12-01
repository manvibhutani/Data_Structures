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

int countnode(NODEPTR a)
{
    if(a==NULL)
    {
        return 0;
    }
    if(a!=NULL)
    {
        return 1;
    }
    
}
int count(NODEPTR a)
{
    if(a!=NULL)
    {
        return countnode(a)+count(a->left)+count(a->right);
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
   
    printf("%d ",count(a));
    return 0;
    
}
