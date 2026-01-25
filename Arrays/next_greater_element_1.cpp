// LeetCode 496: Next Greater Element I
// Link: https://leetcode.com/problems/next-greater-element-i/
// Pattern: Monotonic Stack
// Time Complexity: O(n1 + n2)
// Space Complexity: O(n2)

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreater;
    stack<int> st;

    // Phase 1: preprocess nums2 using monotonic decreasing stack
    for (int i = 0; i < nums2.size(); i++) {
        int x = nums2[i];

        while (!st.empty() && x > st.top()) {
            int smaller = st.top();
            st.pop();
            nextGreater[smaller] = x;
        }

        st.push(x);
    }

    // Remaining elements have no next greater element
    while (!st.empty()) {
        int val = st.top();
        st.pop();
        nextGreater[val] = -1;
    }

    // Phase 2: build answer for nums1
    vector<int> ans(nums1.size());
    for (int i = 0; i < nums1.size(); i++) {
        ans[i] = nextGreater[nums1[i]];
    }

    return ans;
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = nextGreaterElement(nums1, nums2);

    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
