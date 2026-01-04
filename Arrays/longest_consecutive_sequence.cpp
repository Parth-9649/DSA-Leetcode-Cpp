// Problem: Longest Consecutive Sequence
// Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Approach: Hash Set + sequence detection
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    unordered_set<int> st(nums.begin(), nums.end());

    int longest = 0;

    for (int num : st) {
        if (!st.count(num - 1)) {
            int current = num;
            int length = 1;

            while (st.count(current + 1)) {
                current++;
                length++;
            }
            longest = max(longest, length);
        }
    }

    cout << longest;
    return 0;
}
