#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* createNode(int Val){ 
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = Val;
    newNode->next = NULL;
    return newNode;
} 
void addAthead(Node **H, int val){
    Node* newNode = createNode(val);
    newNode->next = *H;
    *H = newNode;
}
void printLinkedList(Node *h){ 
    Node* tmp;
    tmp = h;
    while(tmp != NULL){
        printf("%d->",tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}    
void addAtTall(Node *head, int val) {
    Node* newNode = createNode(val);
    Node* tmp = head;
    while (tmp->next != NULL) { 
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
void addAtAnywhere(Node *head, int data_flag, int val){
    Node* newNode = createNode(val);
    Node* tmp = head;
    while (tmp->next != NULL && tmp->data != data_flag)
        tmp = tmp->next;
    if (tmp->next == NULL)
        tmp->next = newNode;
    else {
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}
int main(){
    Node *head = NULL;
    Node *node1 = createNode(8);
    head = node1;

    addAthead(&head,1);
    addAtTall(head, 9);
    addAthead(&head,2);
    addAthead(&head,3);
    addAtAnywhere(head, 5, 10);
    printLinkedList(head);
}