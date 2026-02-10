/*
LeetCode 541 — Reverse String II
Problem Link: https://leetcode.com/problems/reverse-string-ii/

Approach:
For every block of 2k characters, reverse the first k characters.
If remaining characters < k, reverse all.
If between k and 2k, reverse first k only.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();

        for (int i = 0; i < n; i += 2 * k) {
            int l = i;
            int r = min(i + k - 1, n - 1);

            while (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};

/* ---------- Driver Code for Local Testing ---------- */
int main() {
    Solution sol;

    string s = "abcdefg";
    int k = 2;

    cout << sol.reverseStr(s, k) << endl;  // Expected: bacdfeg
    return 0;
}
