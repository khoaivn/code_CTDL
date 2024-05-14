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
void addAtTail(Node **head, int val) {
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
    if(*head != NULL)
        *head = (*head)->next;
    else
        printf("DS rong nen khong xoa duoc\n");
}
void deleteAtTail(Node **head){
    if (*head == NULL)
        printf("DS rong nen khong xoa duoc\n");
    else if ((*head)->next == NULL)
        *head = NULL;
    else {
        Node *tmp = *head;
        while (tmp->next->next != NULL)
            tmp = tmp->next;
        tmp->next = NULL;
    }
}
void deleteAtIndex(Node **head, int index){
    if (*head == NULL)
        printf("DS rong nen khong xoa duoc\n");
    else if (index == 1)
        *head = (*head)->next;
    else {
        Node *tmp = *head;
        int count = 1;
        while (tmp->next != NULL && count != index - 1){
            tmp = tmp->next;
            count++;
        }
        if (tmp->next != NULL)
            tmp->next = tmp->next->next;
        else 
            printf("index khong ton tai\n");
    }
}
int find(Node *head, int val){
    Node *tmp = head;
    int index = 1;
    while (tmp != NULL && tmp->data != val){
        tmp = tmp->next;
        index++;
    }
    if (tmp == NULL) return -1;
    else return index;
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
    addAtTail(&head, 4);
    addAtTail(&head, 5);
    addAtTail(&head, 8);
    addAtTail(&head, 9);
    addAtAnywhere(head, 8, 3);
    addAtAnywhere(head, 9, 12);
    
    printList(head);
    printf("%d", find(head, 12));
    return 0;
}
