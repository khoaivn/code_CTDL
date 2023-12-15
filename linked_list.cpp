#include <bits/stdc++.h>

using namespace std;

class MyLinkedList{
public:

    class node {
    public:
        int data;
        node *next;

        node(int val): data(val), next(NULL){}
    };

    node* head;
    MyLinkedList(){
        head = NULL;
    }
    int pullAtHead(){
        if (head == NULL)
            return -1;
        else {
            int val = head->data;
            head = head->next;
            return val;
        }
    }

    int get(int index) {
        node* cur;
        cur = head;
        for (int i = 0; i < index && cur != NULL; i++)
            cur = cur->next;
        if (cur != NULL)
            return cur->data;   
        else
            return -1;
    }
    
    void addAtHead(int val) {
        node* moi = new node(val);
        moi->next = head;
        head = moi;
        
    }
    void print_all(){
        node* cur;
        cur = head;
        while (cur != NULL){
            cout << cur->data << "  ";
            cur = cur->next;
        }
        cout << endl;
    }
    
    void addAtTail(int val) {
        node* moi = new node(val);
        if (head == NULL)
            head = moi;
        else {
            node* last;
            last = head;
            while (last->next != NULL){
                last = last->next;
            }
            last->next = moi;
        }
    }
    
    void addAtIndex(int index, int val) {
        node* moi = new node(val);
        if (index == 0){
            addAtHead(val);
        } else {
            node* cur;
            cur = head;
            for (int i = 0; i < index - 1 && cur != NULL; i++)
                cur = cur->next;
            if (cur != NULL){
                moi->next = cur->next;
                cur->next = moi;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        if (index == 0)
            head = head->next;
        else {
            node* cur;
            cur = head;
            for (int i = 0; i < index - 1 && cur !=NULL; i++)
                cur = cur->next;
            if (cur != NULL && cur->next != NULL){
                cur->next = cur->next->next;
            }
        }
    }
};




int main(){

    MyLinkedList list;
    list.addAtIndex(0,10);
    list.addAtIndex(0,20);
    list.addAtIndex(1,30);

    list.print_all();

    cout << list.pullAtHead() << endl;

    list.print_all();
    
    return 0;
}