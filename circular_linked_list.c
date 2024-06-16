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
// void addAtTail(Node **head, int val) {
   
// }

// void addAtAnywhere(Node *head, int data_flag, int val){
    
// }
// void deleteAtHead(Node **head){
   
// }
// Node* deleteAtHead_01(Node *head){
    
// }
// void deleteAtTail(Node **head){
    
// }
// Node* deleteAtTail_01(Node *head){
    
// }
// void deleteAtIndex(Node **head, int index){
    
// }
// Node* deleteAtIndex(Node *head, int index){
    
// }
// int find(Node *head, int val){
    
// }
void printList(Node* head) {
    Node *tmp = head;
    while (tmp->next != head) {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}


int main(){
    Node *head = NULL;
    head = addAtHead(head, 10);
    head = addAtHead(head, 20);
    // head = addAtTail_01(head, 1);
    // head = addAtTail_01(head, 3);
    // addAtTail(&head, 4);
    // addAtTail(&head, 5);
    // addAtTail(&head, 8);
    // addAtTail(&head, 9);
    // addAtAnywhere(head, 8, 3);
    // addAtAnywhere(head, 9, 12);
    
    printList(head);

    return 0;
}
