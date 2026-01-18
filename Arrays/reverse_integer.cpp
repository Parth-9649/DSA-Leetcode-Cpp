#include <bits/stdc++.h>
using namespace std;

/*
LeetCode Problem 7: Reverse Integer
Link: https://leetcode.com/problems/reverse-integer/

Time Complexity: O(log10(n))
Space Complexity: O(1)
*/

class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            if (rev > INT_MAX || rev < INT_MIN) return 0;
            x /= 10;
        }
        return (int)rev;
    }
};

int main() {
    Solution sol;
    cout << sol.reverse(123) << endl;
    cout << sol.reverse(-123) << endl;
    cout << sol.reverse(1534236469) << endl;
    return 0;
}
