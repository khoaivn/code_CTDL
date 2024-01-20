#include <bits/stdc++.h>

using namespace std;

void SelectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
                // swap(arr[j], arr[min]);
            }
        }
        swap(arr[i], arr[min]);
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
}
int heightChecker(vector<int>& heights) {
    vector<int> expected = heights;
    int count = 0;
    for(int i = 0; i < heights.size(); i++) {
        int min = i;
        for(int j = i + 1; j < heights.size(); j++) {
            if(heights[min] > heights[j]) {
                min = j;
            }
        }
        if (min != i){
            cout << i << " " << min << endl;
            int temp = heights[min];
            heights[min] = heights[i];
            heights[i] = temp;
            count++;
        }
        if (min != i && i == heights.size() - 2){
            count++;
        }
    }
    
    return count;
}


int thirdMax(vector<int>& nums) {
    int n = nums.size();
    for (int i = n - 1; i > 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (nums[i] < nums[j]) {
                swap(nums[i], nums[j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << nums[i] << "  ";
    cout << endl;

    int count = 1;
    int i = 0;
    while (i < n - 1 && count < 3) {
        if (nums[i] != nums[i + 1]) {
            count++;
        }
        i++;
        cout << i << "  " << nums[i] << "  " << count << endl;
    }

    if (count < 3)
        return nums[0];
    else 
        return nums[i];
    
}
int searchInsert(vector<int>& nums, int target){
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            return mid;
        } else if(nums[mid] < target){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}
void merge(vector<int>& nums, int start, int mid, int end) {
    vector<int> result;
    int i = start;
    int j = mid + 1;
    while(i <= mid && j <= end) {
        if(nums[i] <= nums[j]) {
            result.push_back(nums[i]);
            i++;
        } else {
            result.push_back(nums[j]);
            j++;
        }
    }
    while(i <= mid) {
        result.push_back(nums[i]);
        i++;
    }
    while(j <= end) {
        result.push_back(nums[j]);
        j++;
    }
    for (int i = start; i <= end; i++)
        nums[i] = result[i - start];
  
}
void mergeSort(vector<int>& nums, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
}


int main() {
    int Arr[] = {2, 7, 5, 2, 6, 7, 9, 0, 8, 5, 0, 0, 11, 0, 0, 4};
    // int Arr[] = {10, 9, 1, 3, 5, 6, 2, 8, 20, 20};
    vector<int> mot (Arr, Arr + sizeof(Arr) / sizeof(Arr[0]) );
    // int Brr[] = {1, 2, 90, 111};
    // vector<int> hai (Brr, Brr + sizeof(Brr) / sizeof(Brr[0]) );

    mergeSort(mot, 0, 15);
    for (int i = 0; i < mot.size(); i++)
        cout << mot[i] << "  ";

    

    return 0;
}
