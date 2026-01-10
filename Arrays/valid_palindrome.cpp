// Problem: Valid Palindrome
// Link: https://leetcode.com/problems/valid-palindrome/
// Approach: Two Pointers
// Time: O(n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;

    while (l < r) {
        while (l < r && !isalnum(s[l])) l++;
        while (l < r && !isalnum(s[r])) r--;

        if (tolower(s[l]) != tolower(s[r]))
            return false;

        l++;
        r--;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    cout << (isPalindrome(s) ? "true" : "false");
    return 0;
}
