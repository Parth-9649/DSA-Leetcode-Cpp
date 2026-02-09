/*
Problem: 628. Maximum Product of Three Numbers
Link: https://leetcode.com/problems/maximum-product-of-three-numbers/

Approach:
1. Sort the array.
2. Maximum product comes from either:
   - Top three largest numbers
   - Two smallest (possibly negative) and the largest number.
3. Return the maximum of the two possibilities.

Time Complexity: O(n log n) due to sorting
Space Complexity: O(1) extra space (ignoring sort stack)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int option1 = nums[n-1] * nums[n-2] * nums[n-3];
        int option2 = nums[n-1] * nums[0] * nums[1];

        return max(option1, option2);
    }
};

// Driver code for local testing
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};

    cout << "Maximum Product: "
         << sol.maximumProduct(nums) << endl;

    return 0;
}
