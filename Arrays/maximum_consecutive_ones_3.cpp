/*
LeetCode 1004: Max Consecutive Ones III
https://leetcode.com/problems/max-consecutive-ones-iii/

Medium - Sliding Window Pattern (Contest-style)

Problem:
Given a binary array nums and an integer k, return the maximum number of consecutive 1s
in the array if you can flip at most k zeros to 1s.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int l = 0, zeroCount = 0, maxLen = 0;
    
    for (int r = 0; r < nums.size(); r++) {
        if (nums[r] == 0) zeroCount++;
        
        while (zeroCount > k) {
            if (nums[l] == 0) zeroCount--;
            l++;
        }
        
        maxLen = max(maxLen, r - l + 1);
    }
    
    return maxLen;
}

int main() {
    vector<int> nums = {1,0,0,1,1,0,1,1,1};
    int k = 2;
    
    cout << "Maximum consecutive ones with at most " << k << " flips: ";
    cout << longestOnes(nums, k) << endl;
    
    return 0;
}
