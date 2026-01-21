/*
Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Approach: Binary Search on Rotated Array
Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] <= nums[high]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return nums[low];
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << "Minimum element is: " << findMin(nums);
    return 0;
}
