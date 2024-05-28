#include <bits/stdc++.h>

using namespace std;

int tim_kiem_tuan_tu(int Arr[], int n, int x){
    for (int i = 0; i < n; i++)
        if (Arr[i] == x)
            return i;
    return -1;
}
int Binary_Search_DQ(int Arr[], int l, int r, int x){
    if (l <= r){
        int mid = (l + r) / 2;
        if (Arr[mid] == x)
            return mid;
        else if (Arr[mid] > x)
            return Binary_Search_DQ(Arr, l, mid - 1, x);
        else 
            return Binary_Search_DQ(Arr, mid + 1, r, x);
    } else 
        return -1;
}
int Binary_Search(int Arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = (l + r) /2;
        if (Arr[mid] == x)
            return mid;
        else 
            if (Arr[mid] > x) 
                r = mid -1;
            else 
                l = mid + 1;
    }
    return -1;
}

int main(){

    int a[] = {5, 29, 110, 400, 459, 490, 510, 523};
    // int a[] = {1, 2, 4, 8, 9, 10};

    printf("ket qua la %d", BS(a, 0, 7, 510));

    
    return 0;
}