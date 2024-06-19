#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
Node* addAtHead(Node *head, int val){
    Node *new_node = createNode(val);
    if (head == NULL){
        head = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    return head;
}
Node* addAtTail(Node *head, int val) {
    Node *newNode = createNode(val);
    if (head == NULL)
        head = newNode;
    else {
        Node *tmp = head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
        newNode->prev = tmp;
    }
    return head;
}
void addAfterNode(Node *head, int data_flag, int val){
    Node *newNode = createNode(val);
    Node *tmp = head;
    while (tmp->next != NULL && tmp->data != data_flag)
        tmp = tmp->next;
    if (tmp->next == NULL && tmp->data == data_flag)
        head = addAtTail(head, val);
    else if (tmp->data == data_flag){
        newNode->next = tmp->next;
        newNode->prev = tmp;
        tmp->next = newNode;
        newNode->next->prev = newNode;
    } else 
        printf("Khong thay\n");
}
Node* addBeforeNode(Node *head, int data_flag, int val){
    Node *newNode = createNode(val);
    Node *tmp = head;
    while (tmp->next != NULL && tmp->data != data_flag)
        tmp = tmp->next;
    if (tmp->data == data_flag && tmp == head)
        head = addAtHead(head, val);
    else if (tmp->data == data_flag){
        newNode->next = tmp;
        newNode->prev = tmp->prev;
        tmp->prev = newNode;
        newNode->prev->next = newNode;
    } else 
        printf("Not found\n");
    return head;
}
Node* deleteAtHead(Node *head){
    if (head == NULL)
        printf("List is empty!\n");
    else if (head->next == NULL)
        head = NULL;
    else {
        head->next->prev = NULL;
        head = head->next;
    }
    return head;
}

Node* deleteAtTail(Node *head){
    if (head == NULL)
        printf("List is empty!\n");
    else if (head->next == NULL)
        head = NULL;
    else {
        Node *tmp = head;
        while (tmp->next->next != NULL)
            tmp = tmp->next;
        tmp->next->prev = NULL;
        tmp->next = NULL;
    }
    return head;
}
Node* deleteAfterNode(Node *head, int flag){
    if (head == NULL)
        printf("List is empty!\n");
    else {
        Node *tmp = head;
        while (tmp->next != NULL && tmp->data != flag){
            tmp = tmp->next;
        }
        if (tmp->next == NULL)
            printf("Not found!\n");
        else if (tmp->next->next == NULL)
            head = deleteAtTail(head);
        else {
            tmp->next = tmp->next->next;
            tmp->next->prev = tmp;
        } 
    }
    return head;
}
Node* deleteBeforeNode(Node *head, int flag){
    if (head == NULL)
        printf("List is empty!\n");
    else {
        Node *tmp = head;
        while (tmp->next != NULL && tmp->data != flag){
            tmp = tmp->next;
        }
        if (tmp->next == NULL && tmp->data != flag || head->data == flag)
            printf("Not found!\n");
        else if (head->next->data == flag)
            head = deleteAtHead(head);
        else {
            tmp->prev = tmp->prev->prev;
            tmp->prev->next = tmp;
        } 
    }
    return head;
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
    head = addAtTail(head, 20);
    head = addAtTail(head, 5);
    head = addAtTail(head, 16);
    head = addAtTail(head, 12);
    // head = addAtTail(head, 4);
    // head = addAtTail(head, 6);
    // head = addAtTail(head, 13);
    // head = addAtHead(head, 5);
    // addAfterNode(head, 5, 8);
    // head = addBeforeNode(head, 3, 10);
    head = deleteBeforeNode(head, 16);
    printList(head);
}