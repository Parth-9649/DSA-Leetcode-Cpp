// Problem: 1005. Maximize Sum Of Array After K Negations
// Link: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
// Approach: Greedy + Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() && k > 0 && nums[i] < 0; i++) {
            nums[i] = -nums[i];
            k--;
        }

        if (k % 2 == 1) {
            int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
            nums[minIdx] = -nums[minIdx];
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};

int main() {
    vector<int> nums = {3, -1, 0, 2};
    int k = 3;

    Solution sol;
    cout << sol.largestSumAfterKNegations(nums, k) << endl;

    return 0;
}
