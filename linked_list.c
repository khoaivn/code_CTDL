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
void deleteAtHead(Node **head){
    if (*head != NULL)
        *head = (*head)->next;
    else 
        printf("Danh sach trong\n");
}

void deleteAtTall(Node **head){
    Node *tmp = *head;
    while (tmp != NULL && tmp->next != NULL && tmp->next->next != NULL)
        tmp = tmp->next;
    if (tmp == NULL)
        printf("Danh sach rong\n");
    else if (tmp->next == NULL)
        *head = NULL;
    else 
        tmp->next = NULL;
}
void deleteAtAnywhere(Node **head, int data_flag){
    Node *tmp = *head;
    if (*head == NULL)
        printf("Danh sach rong\n");
    else if ((*head)->data == data_flag)
        *head = (*head)->next;
    else {
        while (tmp->next != NULL && tmp->next->data != data_flag)
            tmp = tmp->next;
        if (tmp->next != NULL)
            tmp->next = tmp->next->next;
        else
            printf("Khong tim thay\n");
    }
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
    deleteAtAnywhere(&head, 12);
    printList(head);
    return 0;
}
