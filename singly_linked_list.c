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
Node* addAtHead_01(Node *head, int val){
    Node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    return head;
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
Node* addAtTail_01(Node *head, int val) {
    Node *newNode = createNode(val);
    if (head == NULL)
        head = newNode;
    else {
        Node *tmp = head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    return head;
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
int pop(Node **head){
    if(*head != NULL){
        int tmp = (*head)->data;
        *head = (*head)->next;
        return tmp;
    } else {
        printf("List is empty!\n");
        return -1;
    }
}
Node* deleteAtHead_01(Node *head){
    if(head != NULL)
        head = head->next;
    else
        printf("DS rong nen khong xoa duoc\n");
    return head;
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
Node* deleteAtTail_01(Node *head){
    if (head == NULL)
        printf("DS rong nen khong xoa duoc\n");
    else if (head->next == NULL)
        head = NULL;
    else {
        Node *tmp = head;
        while (tmp->next->next != NULL)
            tmp = tmp->next;
        tmp->next = NULL;
    }
    return head;
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
Node* deleteAtIndex_01(Node *head, int index){
    if (head == NULL)
        printf("DS rong nen khong xoa duoc\n");
    else if (index == 1)
        head = head->next;
    else {
        Node *tmp = head;
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
    return head;
}
Node* deleteAfterNode(Node *head, int flag){
    if (head == NULL)
        printf("DS rong nen khong xoa duoc\n");
    else {
        Node *tmp = head;
        while (tmp->next != NULL && tmp->data != flag){
            tmp = tmp->next;
        }
        if (tmp->next != NULL)
            tmp->next = tmp->next->next;
        else 
            printf("Khong xoa duoc\n");
    }
    return head;
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
    // head = addAtHead_01(head, 10);
    head = addAtTail_01(head, 1);
    head = addAtTail_01(head, 3);
    head = addAtTail_01(head, 8);
    head = addAtTail_01(head, 2);
    // addAtAnywhere(head, 3, 9);
    // head = deleteAfterNode(head, 9);
    // addAtTail(&head, 4);
    // addAtTail(&head, 5);
    // addAtTail(&head, 8);
    // addAtTail(&head, 9);
    // addAtAnywhere(head, 8, 3);
    // addAtAnywhere(head, 9, 12);
    printf("%d\n", pop(&head));
    printf("%d\n", pop(&head));
    printf("%d\n", pop(&head));
    printf("%d\n", pop(&head));
    printf("%d\n", pop(&head));
    printList(head);

    return 0;
}
