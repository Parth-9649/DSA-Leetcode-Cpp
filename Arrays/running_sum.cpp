/*
Problem: Running Sum of 1D Array
Link: https://leetcode.com/problems/running-sum-of-1d-array/
Difficulty: Easy
Time Complexity: O(n)
Space Complexity: O(1) extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i - 1];
        }
        return nums;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = sol.runningSum(nums);

    cout << "Running Sum: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
