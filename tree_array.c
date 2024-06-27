#include <bits/stdc++.h>

using namespace std;


const static int Max = 100;
const static int Null = -1;

class tree{
public:
    
    int Arr[Max];
    tree(){
        for (int i = 0; i < Max; i++)
            Arr[i] = Null;
        Arr[0] = 1;
        Arr[1] = 2;
        Arr[2] = 4;
        Arr[3] = 7;
        Arr[4] = 8;
        Arr[5] = 9;
        Arr[6] = 1;
    }
    void print_arr(){
        for (int i = 0; i < Max; i++)
            printf("%d  ", Arr[i]);
    }
    void pre_order(int index){
        if (index < Max && Arr[index] != Null){
            printf("%d  ", Arr[index]);
            pre_order(2 * index + 1);
            pre_order(2 * index + 2);
        }
    }
    void in_order(int index){
        if (index < Max && Arr[index] != Null){
            in_order(2 * index + 1);
            printf("%d  ", Arr[index]);
            in_order(2 * index + 2);
        }
    }
    void post_order(int index){
        if (index < Max && Arr[index] != Null){
            post_order(2 * index + 1);
            post_order(2 * index + 2);
            printf("%d  ", Arr[index]);
        }
    }

};

int main(){
    tree aa;
    aa.post_order(0);
}