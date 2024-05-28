#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
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
void duyet_tien_thu_tu(Node *nowNode){
    if (nowNode != NULL){
        printf("%d ", nowNode->data);
        duyet_tien_thu_tu(nowNode->left);
        duyet_tien_thu_tu(nowNode->right);
    } 
}
void duyet_trung_thu_tu(Node *nowNode){
    if (nowNode != NULL){
        duyet_trung_thu_tu(nowNode->left);
        printf("%d ", nowNode->data);
        duyet_trung_thu_tu(nowNode->right);
    } 
}
void duyet_hau_thu_tu(Node *nowNode){
    if (nowNode != NULL){
        duyet_hau_thu_tu(nowNode->left);
        duyet_hau_thu_tu(nowNode->right);
        printf("%d ", nowNode->data);
    } 
}
void insertNodeBST(Node **nowNode, Node *newNode){
    if (*nowNode == NULL)
        *nowNode = newNode;
    else if ((*nowNode)->data < newNode->data)
        insertNodeBST(&(*nowNode)->right, newNode);
    else
        insertNodeBST(&(*nowNode)->left, newNode);

}
Node* insertNodeBST2(Node *nowNode, Node *newNode){
    if (nowNode == NULL)
        return newNode;
    else if (nowNode->data < newNode->data){
        nowNode->right = insertNodeBST2(nowNode->right, newNode);
        return nowNode;
    } else {
        nowNode->left = insertNodeBST2(nowNode->left, newNode);
        return nowNode;
    }

}
void deleteNode(Node **nodeD){// khong xoa o vong lap thu hai
    if ((*nodeD)->left == NULL){
        *nodeD = (*nodeD)->right;
    } else if ((*nodeD)->right == NULL){
        *nodeD = (*nodeD)->left;
    } else {
        Node *tmp = (*nodeD)->right;
        while (tmp->left != NULL)
            tmp = tmp->left;
        (*nodeD)->data = tmp->data;
        deleteNode(&tmp);
    }
}
Node* findNode(Node *root, int key){
    if (root == NULL)
        return NULL;
    else if (root->data < key)
        return findNode(root->right, key);
    else if (root->data > key)
        return findNode(root->left, key);
    else
        return root;
}
Node* deleteNodeTree(Node* root, int key) {
    if (root == NULL)
        return root;
    if (root->data < key){
        root->right = deleteNodeTree(root->right, key);
        return root;
    } else if (root->data > key){
        root->left = deleteNodeTree(root->left, key);
        return root;
    } else {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        else {
            Node *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;
            root->right = deleteNodeTree(root->right, temp->data);
            return root;
        }
    }
}

void nullNode(Node **aaa){
    (*aaa) = NULL;
}
int main(){
    // Node *uu = createNode(44);
    // printf("%d \n", uu->data);
    // nullNode(&uu);
    // if (uu == NULL)
    //     printf("yyyy");
    Node *rootBST = NULL;
    insertNodeBST(&rootBST, createNode(34));
    insertNodeBST(&rootBST, createNode(17));
    insertNodeBST(&rootBST, createNode(66));
    insertNodeBST(&rootBST, createNode(25));
    insertNodeBST(&rootBST, createNode(50));
    insertNodeBST(&rootBST, createNode(71));
    insertNodeBST(&rootBST, createNode(45));
    insertNodeBST(&rootBST, createNode(56));
    insertNodeBST(&rootBST, createNode(68));
    insertNodeBST(&rootBST, createNode(94));
    insertNodeBST(&rootBST, createNode(70));
    // // 34 17 25 66 50 45 56 71 68 94 70

    deleteNodeTree(rootBST, 45);
    deleteNodeTree(rootBST, 17);
    deleteNodeTree(rootBST, 66);

    
    

    duyet_tien_thu_tu(rootBST);

    
    return 1;
}