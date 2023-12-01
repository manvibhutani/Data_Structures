#include<stdio.h>
#include<stdlib.h>
struct Tree
{
    int val;
    struct Tree *left, *right;
};

struct Tree *maketree(int value)
{
    struct Tree* t=malloc(sizeof(struct Tree));
    t->val=value;
    t->left=NULL;
    t->right=NULL;
    return t;
}
struct Tree *search(struct Tree *t, int val)
{
    if(t==NULL)
    {
        printf("Node not found\n");
        return NULL;
    }
    if(t->val==val)
    {
        return t;
    }
    if(val>t->val)
    {
        return search(t->right,val);
    }
    else{
        return search(t->left,val);
    }
}
struct Tree *insertBST(struct Tree* node, int key)
{
    if (node == NULL)
    {
        return maketree(key);
    }

    if(key<node->val)
    {
        node->left=insertBST(node->left,key);
    }
    if(key>node->val)
    {
        node->right=insertBST(node->right,key);
    }
    return node;
}
void preTrav(struct Tree* t)
{
    if(t!=NULL)
    {
        printf("%d ", t->val);
    preTrav(t->left);
    preTrav(t->right);
    }
}
int main()
{
 
struct Tree *BST=NULL;

int k=0;
while(k!=-1)
{
    int val;
   
    printf("Enter value to be inserted");
     scanf("%d", &val);
    BST=insertBST(BST,val);
    printf("Press -1 to exit and any other key to continue\n");
    scanf("%d", &k);
}
// BST=insertBST(BST,2);
// BST=insertBST(BST,9);
// BST=insertBST(BST,3);
// BST=insertBST(BST,1);
// BST=insertBST(BST,8);
// BST=insertBST(BST,11);
preTrav(BST);
printf("Enter a value to searched");
k=9;
while(k!=-1)
{
    int searchKey;
scanf("%d", &searchKey);

printf("\n%d", search(BST,searchKey)->val);
printf("Press -1 to exit and any other key to continue\n");
    scanf("%d", &k);
}


    return 0;
}

























