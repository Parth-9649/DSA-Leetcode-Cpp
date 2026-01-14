#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 525: Contiguous Array
https://leetcode.com/problems/contiguous-array/

Approach:
Prefix Sum + HashMap
0 -> -1, 1 -> +1
Same prefix sum repeating means balanced subarray

Time: O(n)
Space: O(n)
*/

int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> firstIndex;
    firstIndex[0] = -1;

    int sum = 0, maxLen = 0;

    for(int i = 0; i < nums.size(); i++) {
        sum += (nums[i] == 0 ? -1 : 1);

        if(firstIndex.count(sum)) {
            maxLen = max(maxLen, i - firstIndex[sum]);
        } else {
            firstIndex[sum] = i;
        }
    }
    return maxLen;
}

int main() {
    vector<int> nums = {0,1,0,1,1,1,0};
    cout << findMaxLength(nums);
    return 0;
}
