#include <bits/stdc++.h>

using namespace std;

const int maxN = 3;
class Stack{
public:
    int A[maxN];
    int top;
    Stack(): top(-1){
        for (int i = 0; i < maxN; i++)
            A[i] = 0;
    }
    bool isFull(){
        if (top == maxN - 1) return true;
        else return false;
    }
    void push(int val){
        if (isFull())
            cout << "Stack full!";
        else {
            top++;
            A[top] = val;
        }
    }
    bool isEmpty(){
        if (top < 0) return true;
        else return false;
    }
    int pop(){
        if (isEmpty()){
            cout << "Stack empty!";
            return -1;
        } else {
            int u = A[top];
            top--;
            return u;
        }
    }

};

class Queue{
public:
    int A[maxN];
    int left;
    int right;
    int size;

    Queue(): left(0), right(-1), size(0){
        for (int i = 0; i < maxN; i++)
            A[i] = 0;
    }
    bool isEmpty(){
        if (size == 0) return true;
        else return false;
    }
    bool isFull(){
        if (size == maxN) return true;
        else return false;
    }
    void push(int val){
        if (isFull())
            cout << "Queue full!";
        else {
            if (right == maxN - 1) right = 0;
            else right++;
            size++;
            A[right] = val;
        }
    }
    int pop(){
        if (isEmpty()){
            cout << "Queue empty!";
            return -1;
        } else {
            int u = A[left];
            if (left == maxN - 1) left = 0;
            else left++;
            size--;
            return u;
        }
    }
    void print_queue(){
        for (int i = 0; i < maxN; i++)
            cout << A[i] << "  ";
        cout << endl;
    }
};
int main(){
    Queue qu;
    qu.push(2);
    qu.push(7);
    qu.push(9);
    qu.pop();
    qu.push(1);
    qu.print_queue();
    // cout << qu.pop() << endl;


    
    
    return 0;
}