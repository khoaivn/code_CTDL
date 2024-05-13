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
void addAtTall(Node **head, int val) {
    Node *newNode = createNode(val);
    if (*head == NULL)
        *head = newNode;
    else {
        Node *tmp = *head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}
void addAtAnywhere(Node *head, int data_flag, int val){
    Node *newNode = createNode(val);
    Node *tmp = head;
    while (tmp->next != NULL && tmp->data != data_flag)
        tmp = tmp->next;
    if (tmp->data == data_flag){
        newNode->next = tmp->next;
        tmp->next = newNode;
    } else 
        printf("Khong thay\n");
}
void printList(Node* head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main(){
    Node *head = NULL;
    addAtTall(&head, 4);
    addAtTall(&head, 5);
    addAtTall(&head, 8);
    addAtTall(&head, 9);
    addAtAnywhere(head, 8, 3);
    addAtAnywhere(head, 9, 12);
    addAtAnywhere(head, 6, 15);
    printList(head);
    return 0;
}
