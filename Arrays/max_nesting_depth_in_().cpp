/*
LeetCode 1614: Maximum Nesting Depth of the Parentheses
Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

Approach:
- Use a counter to track current depth of '('
- Increment on '(' and decrement on ')'
- Keep updating the maximum depth encountered

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int currDepth = 0;

        for (char c : s) {
            if (c == '(') {
                currDepth++;
                maxDepth = max(maxDepth, currDepth);
            } else if (c == ')') {
                currDepth--;
            }
        }
        return maxDepth;
    }
};

int main() {
    Solution sol;

    string s1 = "(1+(2*3)+((8)/4))+1";
    string s2 = "()";
    string s3 = "((()))";

    cout << sol.maxDepth(s1) << endl; // 3
    cout << sol.maxDepth(s2) << endl; // 1
    cout << sol.maxDepth(s3) << endl; // 3

    return 0;
}
