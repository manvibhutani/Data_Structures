#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int value;
    struct tree *left;
    struct tree *right;
};
typedef struct tree *NODEPTR;
NODEPTR maketree(int val)
{
    NODEPTR p;
    p = malloc(sizeof(struct tree));
    p->value = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}
NODEPTR makebst(NODEPTR node, int key)
{
    if (node == NULL)
    {
        return maketree(key);
    }

    if(key<node->value)
    {
        node->left=makebst(node->left,key);
    }
    if(key>node->value)
    {
        node->right=makebst(node->right,key);
    }
    return node;
}
NODEPTR delete(NODEPTR tree, int n)
{
    if(tree==NULL)
    {
        return NULL;
    }
    if(tree->value>n)
    {
        tree->left=delete(tree->left,n);
        return tree;
    }
    else if(tree->value<n)
    {
        tree->right = delete(tree->right,n);
        return tree;
    }
    if(tree->left==NULL)
    {
        NODEPTR temp = tree->right;
        free(tree);
        return temp;
    }
    else if(tree->right==NULL)
    {
        NODEPTR temp = tree->left;
        free(tree);
        return temp;
    }
    else{
        NODEPTR succParent = tree;
        NODEPTR succ=tree->right;
        while(succ->left!=NULL)
        {
            succParent=succ;
            succ=succ->left;
        }
        if(succParent!=NULL)
        {
            succParent->left=succ->right;
        }
        else{
            succParent->right=succ->right;
        }
        tree->value=succ->value;
        free(succ);
        return tree;
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

NODEPTR a=NULL;
a=makebst(a,6);
a=makebst(a,5);
a=makebst(a,4);
a=makebst(a,1);
a=makebst(a,2);
a=makebst(a,56);
intrav(a);
a=delete(a,2);
intrav(a);
    return 0;
}
