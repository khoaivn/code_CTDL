#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addAtHead(Node **head, int val){
    Node *newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
}
void addAtTall(Node **head, int val){
    Node *newNode = createNode(val);
    if (*head == NULL){
        *head = newNode;
    } else {
        Node *lastNode = *head;
        while (lastNode->next != NULL)
            lastNode = lastNode->next;
        lastNode->next = newNode;
    }
}
void insertAfter(Node* prevNode, int data) {
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}




int main(){
    Node *head = NULL;
    addAtHead(&head, 1);
    addAtHead(&head, 2);
    addAtHead(&head, 3);
    addAtTall(&head, 8);
    printList(head);
    printf("aaaa");
    return 0;
}
