// Problem: 503. Next Greater Element II
// Link: https://leetcode.com/problems/next-greater-element-ii/
// Approach: Monotonic Decreasing Stack + Circular Traversal (2N)
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st; // stores indices

        // Traverse array twice to simulate circular behavior
        for (int i = 0; i < 2 * n; i++) {
            int curr = nums[i % n];

            // Resolve next greater for elements in stack
            while (!st.empty() && nums[st.top()] < curr) {
                ans[st.top()] = curr;
                st.pop();
            }

            // Push index only in first pass
            if (i < n) {
                st.push(i);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};

    vector<int> result = sol.nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
