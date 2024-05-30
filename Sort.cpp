#include <bits/stdc++.h>

using namespace std;

// void swap(int &a, int &b){
//     int tmp = a;
//     a = b;
//     b = tmp;
// }
void seletionSort(int Arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int min_index = i;
        for (int j = i + 1; j < n; j++)
            if (Arr[j] < Arr[min_index])
                min_index = j;
        swap(Arr[i], Arr[min_index]);
    }
}
void insertionSort(int Arr[], int n){
    for (int i = 1; i < n; i++){
        int tmp = Arr[i];
        int j = i - 1;
        while (j >= 0 && Arr[j] > tmp){
            Arr[j + 1] = Arr[j];
            j--;
        }
        Arr[j + 1] = tmp;
    }
}
void countingSort(int Arr[], int n, int k){
    int C[k + 1];
    int O[n];
    for (int i = 0; i < n; i++)
        C[Arr[i]]++;
    int index = 0;
    for (int i = 0; i <= k; i++)
        for (int j = 0; j < C[i]; j++){
            O[index] = i;
            index++;
        }
    for (int i = 0; i < n; i++)
        Arr[i] = O[i];
}
int lomutoPartition(int Arr[], int low, int high){
    int pivot = Arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++){
        if (Arr[j] < pivot){
            i++;
            swap(Arr[i], Arr[j]);
        }
    }
    swap(Arr[i + 1], Arr[high]);
    return i + 1;
}
int hoarePartition(int Arr[], int low, int high){
    int pivot = Arr[low];
    int i = low - 1;
    int j = high + 1;
    while (true){
        do {
            i++;
        } while (Arr[i] < pivot);
        do {
            j--;
        } while (Arr[j] > pivot);
        if (i >= j)
            return j;
        swap(Arr[i], Arr[j]);
    }
}
void quickSort(int Arr[], int low, int high){
    if (low < high){
        int pi = lomutoPartition(Arr, low, high);
        quickSort(Arr, low, pi - 1);
        quickSort(Arr, pi + 1, high);
    }
}
int hoarePartition_vector(vector<int> &nums, int low, int high){
    int pivot = nums[low];
    int i = low - 1;
    int j = high + 1;
    while (true){
        do{
            i++;
        } while (nums[i] < pivot);
        do{
            j--;
        } while (nums[j] > pivot);
        printf("low= %d high=%d pivot=%d   %d  %d\n", low, high, pivot, i, j);
        if (i >= j)
            return j;
        swap(nums[i], nums[j]);
    }
}
int hoarePartition2(vector<int> &nums, int low, int high){
    int pivot = nums[low];
    int i = low;
    int j = high;
    while (true){
        while (nums[i] < pivot) i++;
        while (nums[j] > pivot) j--;
        printf("low= %d high=%d pivot=%d   %d  %d\n", low, high, pivot, i, j);
        if (i < j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        } else
            return j;
    }
}
void quickSort_vector(vector<int> &nums, int low, int high){
    if (low < high){
        int pi = hoarePartition2(nums, low, high);
        quickSort_vector(nums, low, pi);
        quickSort_vector(nums, pi + 1, high);
    }
}
int main(){
    // int A[] = {10, 7, 8, 9, 1, 5};
    int A[] = {5, 1, 1, 2, 0, 0};
    int n = sizeof(A) / sizeof(A[0]); 
    quickSort(A, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d  ", A[i]);

    
    
}
