/*
Problem: 29. Divide Two Integers
Link: https://leetcode.com/problems/divide-two-integers/

Approach:
- Cannot use *, /, %.
- Convert dividend and divisor to positive long values.
- Repeatedly subtract the largest doubled divisor possible.
- Count how many times divisor fits using doubling.
- Apply correct sign at the end.
- Handle overflow case: INT_MIN / -1.

Time Complexity: O(log N)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long a = labs((long)dividend);
        long b = labs((long)divisor);
        long result = 0;

        while (a >= b) {
            long sum = b;
            long count = 1;

            while (a >= sum + sum) {
                sum += sum;
                count += count;
            }

            a -= sum;
            result += count;
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0))
            result = -result;

        return (int)result;
    }
};

int main() {
    Solution sol;

    cout << sol.divide(10, 3) << endl;   // Expected: 3
    cout << sol.divide(7, -3) << endl;   // Expected: -2
    cout << sol.divide(1, 1) << endl;    // Expected: 1

    return 0;
}
