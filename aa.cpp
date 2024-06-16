#include <bits/stdc++.h>

using namespace std;



int main(){
    int n = 5;
    int *p;
    p = &n;
    n = 8;
    printf("%d\n", p);
    printf("%d\n", *p);
}