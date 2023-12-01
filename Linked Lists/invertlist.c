#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *next;
};
struct node* insert(struct node *first,int n)
{
    struct node* new_node;
    new_node=malloc(sizeof(struct node));
    new_node->value=n;
    new_node->next=first;
    first=new_node;
    return first;
}



void invertLinkedList(struct node **head) {
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next = NULL;

    while (current != NULL) {
        
        next = current->next;

       
        current->next = prev;

        
        prev = current;
        current = next;
    }

    *head = prev;
}
void PrintList(struct node* first)
{
    while(first!=NULL)
    {
        printf("%d\n", first->value);
        first=first->next;
    }
}
int main()
{
    struct node *ps=NULL;
    ps=insert(ps,4);
    ps=insert(ps,6);
    ps=insert(ps,1);
    ps=insert(ps,3);
    ps=insert(ps,5);
    ps=insert(ps,10);
    PrintList(ps);
    printf("\n");
    invertLinkedList(&ps);
    PrintList(ps);

    return 0;
}