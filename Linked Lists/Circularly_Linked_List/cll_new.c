#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
};
typedef struct node *NODEPTR;
void insertAtEnd(struct node** head, int data) {
    struct node* newNode = 
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
}
void deleteAtEnd(struct node** head) {
    if (*head == NULL) {
        printf("Circular linked list is empty. Cannot delete.\n");
    } else {
        struct node* current = *head;
        struct node* previous = NULL;

       
        while (current->next != *head) {
            previous = current;
            current = current->next;
        }

       
        if (previous == NULL) {
            *head = NULL;
        } else {
            previous->next = *head;
        }

        free(current);
    }
}
void PrintList(NODEPTR a)
{
if(a==NULL)
{
    printf("empty list");
    return;
}
NODEPTR cur=a;
do{
    printf("%d ",cur->value);
    cur=cur->next;
}while(cur!=a);
printf("\n");
}
int main()
{
    NODEPTR a=NULL;
    insertAtEnd(&a,9);
    insertAtEnd(&a,1);
    insertAtEnd(&a,2);
    insertAtEnd(&a,3);
    insertAtEnd(&a,4);
    PrintList(a);
    



    return 0;
}
