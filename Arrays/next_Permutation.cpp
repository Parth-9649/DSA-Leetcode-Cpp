// Problem: Next Permutation
// Link: https://leetcode.com/problems/next-permutation/
// Approach: Find first decreasing index + swap + reverse
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1,2,3};
    int n = nums.size(), i = n-2;

    // Step 1: Find first decreasing element from right
    while(i >= 0 && nums[i] >= nums[i+1]) i--;

    if(i >= 0){
        // Step 2: Find smallest number > nums[i] to the right
        int j = n-1;
        while(nums[j] <= nums[i]) j--;
        swap(nums[i], nums[j]);
    }

    // Step 3: Reverse subarray to the right of i
    reverse(nums.begin()+i+1, nums.end());

    // Print result
    for(int x : nums) cout << x << " ";
    return 0;
}
