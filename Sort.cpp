#include <stdio.h>

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
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
int main(){
    int A[] = { 0, 4, 2, 2, 0, 0, 1, 1, 0, 1, 0, 2, 4, 2};
    int n = 14;
    int k = 4;
    // insertionSort(A, n);
    countingSort(A, 14, 4);
    // swap(A[0], A[1]);
    for (int i = 0; i < n; i++)
        printf("%d  ", A[i]);
}