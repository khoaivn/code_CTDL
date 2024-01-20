#include <bits/stdc++.h>
using namespace std;

class Tree{
public:
    class node{
    public:
        node* left;
        int data;
        node* right;
        node(int val): left(NULL), data(val), right(NULL){}
    };
    node* root;
    Tree(){
        root = NULL;
        node* mot = new node(2);
        root = mot;
        node* hai = new node(7);
        mot->left = hai;
        node* ba = new node(5);
        mot->right = ba;
        node* bon = new node(2);
        hai->left = bon;
        node* nam = new node(6);
        hai->right = nam;
        node* sau = new node(9);
        ba->right = sau;
        node* bay = new node(5);
        nam->left = bay;
        node* tam = new node(11);
        nam->right = tam;
        node* chin = new node(4);
        sau->left = chin;
    }
    void duyet_tien_thu_tu(node* cur_node){
        if (cur_node != NULL){
            cout << cur_node->data << "  ";
            duyet_tien_thu_tu(cur_node->left);
            duyet_tien_thu_tu(cur_node->right);
        }
    }
    void duyet_trung_thu_tu(node* cur_node){
        if (cur_node != NULL){
            duyet_trung_thu_tu(cur_node->left);
            cout << cur_node->data << "  ";
            duyet_trung_thu_tu(cur_node->right);
        }
    }
    void duyet_hau_thu_tu(node* cur_node){
        if (cur_node != NULL){
            duyet_hau_thu_tu(cur_node->left);
            duyet_hau_thu_tu(cur_node->right);
            cout << cur_node->data << "  ";
        }
    }
};
int main(){
    Tree cay;
    cay.duyet_hau_thu_tu(cay.root);
    return 0;
}