/*
Problem: Subarray Sum Equals K
Link: https://leetcode.com/problems/subarray-sum-equals-k/
Difficulty: Medium
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int currSum = 0;
        int count = 0;

        for (int num : nums) {
            currSum += num;

            if (mp.find(currSum - k) != mp.end()) {
                count += mp[currSum - k];
            }

            mp[currSum]++;
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << sol.subarraySum(nums, k);
    return 0;
}
