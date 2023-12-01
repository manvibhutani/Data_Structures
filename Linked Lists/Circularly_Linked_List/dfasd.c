#include <stdio.h>

#include <stdlib.h>

 

struct Node {

    int data;

    struct Node* next;

};

 

void deleteAtEnd(struct Node* header) {

    struct Node* current = header->next;

    struct Node* prev = header;

 

    // Traverse to the second-to-last node

    while (current->next != NULL) {

        prev = current;

        current = current->next;

    }

 

    // Update the second-to-last node's next pointer

    prev->next = NULL;

 

    // Free the memory of the last node

    free(current);

}

 

void printLinkedList(struct Node* header) {

    struct Node* current = header->next;

    while (current != NULL) {

        printf("%d ", current->data);

        current = current->next;

    }

    printf("\n");

}

 

int main() {

    struct Node* header = (struct Node*)malloc(sizeof(struct Node));

    header->next = NULL;

 

    // Inserting elements

    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));

    node1->data = 1;

    node1->next = NULL;

    header->next = node1;

 

    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));

    node2->data = 2;

    node2->next = NULL;

    node1->next = node2;

 

    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));

    node3->data = 3;

    node3->next = NULL;

    node2->next = node3;