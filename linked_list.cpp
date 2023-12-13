#include <bits/stdc++.h>
// #include "iostream"

using namespace std;



class MyLinkedList{
public:

    class node {
    public:
        int data;
        node *next;
    };

    node* head;
    MyLinkedList(){
        head = NULL;
    }

    // int get(int index) {
        
    // }
    
    void addAtHead(int val) {
        node moi;
        moi.data = val;
        moi.next = head;
        head = &moi;
    }
    void print_all(){
        node* a;
        a = head;
        while (a != NULL){
            cout << a->data << endl;
            a = a->next;
        }
    }
    
    // void addAtTail(int val) {
        
    // }
    
    // void addAtIndex(int index, int val) {
        
    // }
    
    // void deleteAtIndex(int index) {
        
    // }
};




int main(){

    // node aa;
    // aa.data = 4;
    // node* head;
    // head = &aa;
    // cout << head->data;

    MyLinkedList list;
    list.addAtHead(4);
    list.addAtHead(3);
    list.print_all();
    return 0;
}