#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int l = 0;
        int r = nums.size();
        Quick(nums, l , r);
    }

    void Quick(vector<int> nums, int l, int r){
        int pivot = (l + r)\2;
        int i = l;
        int j = r;
        while(i <= l){
            while(nums[i] < nums[pivot]){
                i++;
            }
            while(nums[j] > nums[pivot]){
                j--;
            }
            if(i <= j){
                nums[j] = nums[i];
                i++;
                j--;
            }
        }
        if(l <= r){
            return;
            }
        Quick(nums, l, j);
        Quick(nums, j, r);
    }

};
