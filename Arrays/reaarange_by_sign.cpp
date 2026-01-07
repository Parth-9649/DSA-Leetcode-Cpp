// Problem: 2149. Rearrange Array Elements by Sign
// Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
// Approach: Two pointers + extra array
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int posIdx = 0, negIdx = 1;

        for (int x : nums) {
            if (x > 0) {
                res[posIdx] = x;
                posIdx += 2;
            } else {
                res[negIdx] = x;
                negIdx += 2;
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    Solution sol;
    vector<int> ans = sol.rearrangeArray(nums);

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
