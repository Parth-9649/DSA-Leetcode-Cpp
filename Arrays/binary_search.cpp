/*
Problem Link: https://leetcode.com/problems/binary-search/
Approach: Standard Binary Search
Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] == target)
            return mid;          // target found
        else if(nums[mid] < target)
            low = mid + 1;       // search right half
        else
            high = mid - 1;      // search left half
    }

    return -1;                   // target not found
}

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;

    int index = binarySearch(nums, target);

    if(index != -1)
        cout << "Target " << target << " found at index: " << index << endl;
    else
        cout << "Target " << target << " not found" << endl;

    return 0;
}
