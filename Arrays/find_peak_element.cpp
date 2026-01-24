#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 162. Find Peak Element
Link: https://leetcode.com/problems/find-peak-element/

Approach:
Binary Search on slope.
Compare nums[mid] with nums[mid + 1]:
- If nums[mid] < nums[mid + 1], move right (low = mid + 1)
- Else move left (high = mid)

Time Complexity: O(log n)
Space Complexity: O(1)
*/

int findPeakElement(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] < nums[mid + 1]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

    int peakIndex = findPeakElement(nums);
    cout << "Peak Index: " << peakIndex << endl;
    cout << "Peak Value: " << nums[peakIndex] << endl;

    return 0;
}
