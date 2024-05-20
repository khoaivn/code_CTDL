#include <stdio.h>
#include <stdlib.h>
int max = 100;

// void tien_thu_tu(int vi_tri_cha, int Arr[], int max){
//     if (Arr[vi_tri_cha] != -1 && vi_tri_cha <= max){
//         printf("%d ", Arr[vi_tri_cha]);
//         tien_thu_tu(2 * vi_tri_cha + 1, Arr, max);
//         tien_thu_tu(2 * vi_tri_cha + 2, Arr, max);
//     }
// }
// void trung_thu_tu(int vi_tri_cha, int Arr[], int max){
//     if (Arr[vi_tri_cha] != -1 && vi_tri_cha <= max){
//         trung_thu_tu(2 * vi_tri_cha + 1, Arr, max);
//         printf("%d ", Arr[vi_tri_cha]);
//         trung_thu_tu(2 * vi_tri_cha + 2, Arr, max);
//     }
// }
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void tien_thu_tu(Node *root){
    if (root != NULL){
        printf("%d ", root->data);
        tien_thu_tu(root->left);
        tien_thu_tu(root->right);
    } 
}
int main(){
    Node *root = NULL;
    Node *node0 = createNode(2);
    Node *node1 = createNode(7);
    Node *node2 = createNode(5);
    Node *node3 = createNode(2);
    Node *node4 = createNode(6);
    Node *node5 = createNode(9);
    Node *node6 = createNode(5);
    Node *node7 = createNode(11);
    Node *node8 = createNode(4);
    root = node0;
    node0->left = node1;
    node0->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->right = node5;
    node4->left = node6;
    node4->right = node7;
    node5->left = node8;

    tien_thu_tu(root);
    
    // max = 14;
    // int A[] = {2, 7, 5, 2, 6, -1, 9, -1, -1, 5,	11, -1, -1,	4, -1};
    // trung_thu_tu(0, A, max);
    return 1;
}