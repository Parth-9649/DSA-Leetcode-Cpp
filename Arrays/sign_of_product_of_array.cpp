// Problem: 1822. Sign of the Product of an Array
// Link: https://leetcode.com/problems/sign-of-the-product-of-an-array/
// Approach: Count negatives + zero check
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negCount = 0;

        for (int x : nums) {
            if (x == 0) return 0;
            if (x < 0) negCount++;
        }

        return (negCount % 2 == 0) ? 1 : -1;
    }
};

int main() {
    vector<int> nums = {-1, -2, -3, -4, 3};

    Solution sol;
    cout << sol.arraySign(nums) << endl;

    return 0;
}
