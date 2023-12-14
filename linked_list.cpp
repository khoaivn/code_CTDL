#include <bits/stdc++.h>

using namespace std;



class MyLinkedList{
public:

    class node {
    public:
        int data;
        node *next;

        node(int val): data(val){
        }
    };

    node* head;
    MyLinkedList(){
        head = NULL;
    }

    // int get(int index) {
        
    // }
    
    void addAtHead(int val) {
        node* moi = new node(val);
        moi->next = head;
        head = moi;
        
    }
    void print_all(){
        node* cur;
        cur = head;
        while (cur != NULL){
            cout << cur->data << endl;
            cur = cur->next;
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

    MyLinkedList list;
    list.addAtHead(4);
    list.addAtHead(3);
    list.addAtHead(9);

    list.print_all();
    return 0;
}