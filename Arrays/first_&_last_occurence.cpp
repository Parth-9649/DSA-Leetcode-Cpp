/*
Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Approach: Binary Search (First Occurrence + Last Occurrence)
Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int findFirst(vector<int>& nums, int target){
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(nums[mid] == target){
            ans = mid;
            high = mid - 1;
        }
        else if(nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return ans;
}

int findLast(vector<int>& nums, int target){
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(nums[mid] == target){
            ans = mid;
            low = mid + 1;
        }
        else if(nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return ans;
}

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    int first = findFirst(nums, target);
    int last = findLast(nums, target);

    cout << "[" << first << ", " << last << "]";
    return 0;
}
