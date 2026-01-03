/*
Problem: Single Number
Link: https://leetcode.com/problems/single-number/
Approach: Bitwise XOR

Explanation:
- XOR of same numbers = 0
- XOR with 0 = number itself
- All duplicates cancel out, leaving the unique number

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,1,2,1,2};
    cout << sol.singleNumber(nums);
    return 0;
}
