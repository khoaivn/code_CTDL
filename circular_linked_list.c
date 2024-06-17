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

Node* addAtHead(Node *head, int val){
    Node *new_node = createNode(val);
    if (head == NULL){
        head = new_node;
        new_node->next = new_node;
    } else {
        Node *tmp = head;
        while (tmp->next != head)
            tmp = tmp->next;
        new_node->next = head;
        head = new_node;
        tmp->next = new_node;
    }
    return head;
}
Node* addAtTail(Node *head, int val) {
    Node *new_node = createNode(val);
    if (head == NULL){
        head = new_node;
        new_node->next = head;
    } else {
        Node *tmp = head;
        while (tmp->next != head)
            tmp = tmp->next;
        new_node->next = head;
        tmp->next = new_node;
    }
    return head;
}

Node* addAfterNode(Node *head, int data_flag, int val){
    Node *new_node = createNode(val);
    if (head == NULL){
        printf("Node does not exits!\n");
    } else {
        Node *tmp = head;
        while (tmp->next != head && tmp->data != data_flag)
            tmp = tmp->next;    
        if (tmp->data == data_flag) {
            new_node->next = tmp->next;
            tmp->next = new_node;
        } else
            printf("Node does not exits!\n");
    }
    return head;
}

Node* deleteAtHead(Node *head){
    if (head == NULL)
        printf("List is empty!");
    else if (head->next == head)
        head = NULL;
    else {
        Node *tmp = head;
        while (tmp->next != head)
            tmp = tmp->next;
        tmp->next = head->next;
        head = head->next;
    }
    return head;
}
Node* deleteAtTail(Node *head){
    if (head == NULL)
        printf("List is empty!");
    else if (head->next == head)
        head = NULL;
    else {
        Node *tmp = head;
        while (tmp->next->next != head)
            tmp = tmp->next;
        tmp->next = head;
    }
    return head;
}

Node* deleteAfterNode(Node *head, int flag){
    if (head == NULL){
        printf("List is empty!\n");
    } else {
        Node *tmp = head;
        while (tmp->next != head && tmp->data != flag)
            tmp = tmp->next;   
        if (tmp->next != head) {
            tmp->next = tmp->next->next;
        } else
            printf("Node does is exits!\n");
    }
    return head;
}
// int find(Node *head, int val){
    
// }
void printList(Node* head) {
    if (head == NULL)
        printf("list is empty!\n");
    else {
        Node *tmp = head;
        do {
            printf("%d -> ", tmp->data);
            tmp = tmp->next;
        } while (tmp != head);
        printf("head\n");
    }
}


int main(){
    Node *head = NULL;
    head = addAtHead(head, 10);
    head = addAtHead(head, 20);
    // head = addAtTail(head, 4);
    // head = addAtTail(head, 6);
    // head = addAtAnywhere(head, 10, 23);
    // head = deleteAtTail(head);
    head = deleteAfterNode(head, 3);
    

    printList(head);

    return 0;
}
