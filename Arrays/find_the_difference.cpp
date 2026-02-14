/*
Problem: 389. Find the Difference
Link: https://leetcode.com/problems/find-the-difference/
Approach: XOR cancellation
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;

        for(char c : s)
            res ^= c;

        for(char c : t)
            res ^= c;

        return res;
    }
};

int main() {
    Solution sol;
    string s = "abcd";
    string t = "abcde";

    cout << sol.findTheDifference(s, t);
    return 0;
}
