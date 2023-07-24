#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> A;
    // A[10] = 9;
    A.push_back(3);
    A.push_back(1);
    A.push_back(8);
    A.push_back(8);
    A.push_back(8);
    A.push_back(8);
    A.push_back(8);

    int v = A.back();
    // printf("%d", A.);
    // printf("%lu", A.size());

    for (int i = 0; i < A.size(); i++){
        printf("%d ", A[i]);
    }
    return 0;
}
    
