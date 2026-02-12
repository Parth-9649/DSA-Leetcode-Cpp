/*
Problem: LeetCode 198 - House Robber
Link: https://leetcode.com/problems/house-robber/
Complexity: Time O(n), Space O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];

    int prev2 = nums[0];              // dp[i-2]
    int prev1 = max(nums[0], nums[1]); // dp[i-1]

    for(int i = 2; i < n; i++){
        int curr = max(prev1, nums[i] + prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    vector<int> nums = {2,7,9,3,1};
    cout << "Maximum money that can be robbed: " << rob(nums) << endl;
    return 0;
}
