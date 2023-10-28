#include <stdio.h>
#include <stdlib.h>
//Thomas Lavadinho
//10/28/23
int main(){
    struct Node* head = NULL;
    insertFront(&head,3);
    insertFront(&head,1);
    insertFront(&head,2);
    printf("Doubly Linked List:");
    printList(head);
    return 0;
}
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;

};
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertFront(struct Node** head, int data){
    struct Node* newNode = createNode(data);

    if(*head==NULL){
        *head = newNode;

    }else{
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void printList(struct Node* head){
    while (head != NULL){
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}