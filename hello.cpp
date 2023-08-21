#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct P{
    int x, t, y1, y2;
};
vector<P> point;

int main() {
    vector<int> A;

    struct P aaa = {1,2,3,4};

    point.push_back(aaa);

    int pos = 4;
    pos = pos + (pos & -pos); 
    cout << pos;
    return 0;
}
    
