/*
Problem: Maximum Matrix Sum
Link: https://leetcode.com/problems/maximum-matrix-sum/
Difficulty: Medium
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> matrix = {
        {1, -2},
        {-3, -4}
    };

    long long sum = 0;
    int negativeCount = 0;
    int minAbs = INT_MAX;

    for (auto &row : matrix) {
        for (int val : row) {
            if (val < 0) negativeCount++;
            sum += abs(val);
            minAbs = min(minAbs, abs(val));
        }
    }

    if (negativeCount % 2 != 0)
        sum -= 2LL * minAbs;

    cout << sum << endl;
    return 0;
}
