/*
Problem: LeetCode 12 - Integer to Roman
Link: https://leetcode.com/problems/integer-to-roman/

Approach:
Use greedy strategy with predefined Roman values including
subtractive combinations. Always subtract the largest possible
value and append corresponding symbol.

Time Complexity: O(1)
(Values array size is constant)

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values =
        {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        vector<string> symbols =
        {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string result = "";

        for(int i = 0; i < values.size(); i++) {
            while(num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    int num = 1994;
    cout << sol.intToRoman(num) << endl;
    return 0;
}
