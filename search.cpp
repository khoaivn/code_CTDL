#include <bits/stdc++.h>

using namespace std;

int tim_kiem_tuan_tu(int Arr[], int n, int x){
    for (int i = 0; i < n; i++)
        if (Arr[i] == x)
            return i;
    return -1;
}
int binarySearch(int arr[], int l, int r,int x){
    if (l <= r){
        int mid = ( l + r ) / 2;
        if (arr[mid] == x)
            return mid;
        else
            if(arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
            else
                return binarySearch(arr, mid + 1, r, x);
    }
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
    cout << Binary_Search(a, 0, 7, 523);

    
    return 0;
}