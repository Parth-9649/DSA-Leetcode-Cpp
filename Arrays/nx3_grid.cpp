/*
Problem: Number of Ways to Paint N x 3 Grid
Link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
Difficulty: Hard
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        const long MOD = 1000000007;
        long A = 6;
        long B = 6;

        for (int i = 2; i <= n; i++) {
            long newA = (2 * A + 2 * B) % MOD;
            long newB = (2 * A + 3 * B) % MOD;
            A = newA;
            B = newB;
        }

        return (int)((A + B) % MOD);
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter n: ";
    cin >> n;
    cout << "Number of ways: " << sol.numOfWays(n) << endl;

    return 0;
}
