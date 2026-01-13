// Problem: 739. Daily Temperatures
// Link: https://leetcode.com/problems/daily-temperatures/
// Approach: Jump Technique (DP-style, No Stack)
// Time Complexity: O(n)
// Space Complexity: O(1) extra (excluding output array)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);

        // Traverse from right to left
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;

            // Jump ahead using previously computed answers
            while (j < n && temperatures[j] <= temperatures[i] && ans[j] != 0) {
                j = j + ans[j];
            }

            // Check if a warmer day is found
            if (j < n && temperatures[j] > temperatures[i]) {
                ans[i] = j - i;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> result = sol.dailyTemperatures(temperatures);

    cout << "Result: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
