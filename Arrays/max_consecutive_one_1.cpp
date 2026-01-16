/*
LeetCode 485: Max Consecutive Ones
https://leetcode.com/problems/max-consecutive-ones/

Easy sliding window variant (no flips)

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxCount = 0, currentCount = 0;
    
    for (int num : nums) {
        if (num == 1) currentCount++;
        else currentCount = 0;
        
        maxCount = max(maxCount, currentCount);
    }
    
    return maxCount;
}

int main() {
    vector<int> nums = {1,1,0,1,1,1};
    cout << findMaxConsecutiveOnes(nums);
    return 0;
}
