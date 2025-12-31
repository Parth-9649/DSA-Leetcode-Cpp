/*
Problem: Running Sum of 1D Array
Link: https://leetcode.com/problems/running-sum-of-1d-array/
Approach: Prefix Sum
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    vector<int> result(nums.size());

    result[0] = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        result[i] = result[i - 1] + nums[i];
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    vector<int> ans = runningSum(nums);

    cout << "Running Sum: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
