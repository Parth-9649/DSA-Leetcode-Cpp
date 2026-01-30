/*
LeetCode 448: Find All Numbers Disappeared in an Array
Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

Approach:
- Use index marking by negating values
- For each number x, mark nums[x-1] as negative
- Indices with positive values represent missing numbers

Time Complexity: O(n)
Space Complexity: O(1) [excluding output array]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,3,2,7,8,2,3,1};

    vector<int> result = sol.findDisappearedNumbers(nums);

    for (int x : result) {
        cout << x << " ";
    }
    // Output: 5 6

    return 0;
}
