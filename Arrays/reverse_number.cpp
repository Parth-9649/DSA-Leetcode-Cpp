/*
Problem: 344. Reverse String
Link: https://leetcode.com/problems/reverse-string/
Approach: Two Pointers (swap from both ends)
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
};

int main() {
    Solution sol;

    vector<char> s = {'h','e','l','l','o'};
    sol.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) cout << c;
    cout << endl;

    return 0;
}
