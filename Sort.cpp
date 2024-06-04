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
void quickSort(int Arr[], int low, int high){
    if (low < high){
        int pi = lomutoPartition(Arr, low, high);
        quickSort(Arr, low, pi - 1);
        quickSort(Arr, pi + 1, high);
    }
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
void meger(int Arr[], int left, int mid, int right){
    int C[right + 1];
    int i = left;
    int j = mid + 1;
    int v = left;
    while (i <= mid && j <= right){
        if (Arr[i] < Arr[j]){
            C[v] = Arr[i];
            i++;
        } else {
            C[v] = Arr[j];
            j++;
        }
        v++;
    }
    while (i <= mid){
        C[v] = Arr[i];
        i++;
        v++;
    }
    while (j <= right){
        C[v] = Arr[j];
        j++;
        v++;
    }  
    for (i = left; i <= right; i++)
        Arr[i] = C[i];

}
void megerSort(int Arr[], int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        megerSort(Arr, left, mid);
        megerSort(Arr, mid + 1, right);
        meger(Arr, left, mid, right);
    }
}
void pushDown(int Arr[], int root, int max_index){
    int i = root;
    while (2 * i + 1 <= max_index){
        int tmp = 2 * i + 1;
        if (2 * i + 2 <= max_index && Arr[tmp] < Arr[2 * i + 2])
            tmp++;
        if (Arr[tmp] > Arr[i]){
            swap(Arr[tmp], Arr[i]);
            i = tmp;
        } else
            i = max_index;
    }
}
void heapSort(int Arr[], int n){
    int par = (n - 2) / 2;
    for (int i = par; i >=0; i--)
        pushDown(Arr, i, n - 1);
    for (int i = n - 1; i > 0; i--){
        swap(Arr[0], Arr[i]);
        pushDown(Arr, 0, i - 1);
    }
}
void pushUp(int Arr[], int max_index){
    int par = (max_index - 1) / 2;
    for (int i = par; i >= 0; i--){
        int tmp = 2 * i + 1;
        int right_index = 2 * i + 2;
        if (right_index <= max_index && Arr[tmp] < Arr[right_index])
            tmp++;
        if (Arr[tmp] > Arr[i])
            swap(Arr[tmp], Arr[i]);
    }
}
void heapSort_pushup(int Arr[], int n){
    for (int i = n - 1; i > 0; i--){
        pushUp(Arr, i);
        swap(Arr[0], Arr[i]);
    }
}
int main(){
    // int A[] = {10, 7, 8, 9, 1, 5};
    int A[] = {1, 3, 7, 9, 2, 6};
    int n = sizeof(A) / sizeof(A[0]); 
    heapSort_pushup(A, 6);
    for (int i = 0; i < n; i++)
        printf("%d  ", A[i]);
    
}
