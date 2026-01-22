/*
Problem: LeetCode 33 - Search in Rotated Sorted Array
Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

Approach:
Binary Search with rotation awareness.
At each step:
1) Identify which half is sorted.
2) Check if target lies inside that sorted half.
3) Discard the other half.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int searchRotated(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = searchRotated(nums, target);
    cout << "Index of target: " << result << endl;

    return 0;
}
