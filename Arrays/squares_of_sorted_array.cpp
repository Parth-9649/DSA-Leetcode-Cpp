/*
Problem: Squares of a Sorted Array
Link: https://leetcode.com/problems/squares-of-a-sorted-array/
Difficulty: Easy
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    int n = nums.size();
    vector<int> result(n);
    int l = 0, r = n - 1, idx = n - 1;

    while (l <= r) {
        if (abs(nums[l]) > abs(nums[r])) {
            result[idx--] = nums[l] * nums[l];
            l++;
        } else {
            result[idx--] = nums[r] * nums[r];
            r--;
        }
    }

    for (int x : result) cout << x << " ";
    return 0;
}
