// LeetCode 69. Sqrt(x)
// Link: https://leetcode.com/problems/sqrtx/
// Time Complexity: O(log x)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;

        int low = 1, high = x, ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid <= x / mid) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int x;
    cin >> x;
    cout << sol.mySqrt(x);
    return 0;
}
