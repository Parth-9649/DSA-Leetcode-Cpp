/*
Problem: LeetCode 242 - Valid Anagram
Link: https://leetcode.com/problems/valid-anagram/
Topic: Hashing / Frequency Counting
Complexity: 
    Time  - O(n) where n = length of string s
    Space - O(1) (array of size 26)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        int count[26] = {0};

        // Count letters in s
        for(int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';
            count[idx]++;
        }

        // Subtract letters in t
        for(int i = 0; i < t.length(); i++) {
            int idx = t[i] - 'a';
            if(count[idx] == 0) return false; // extra letter in t
            count[idx]--;
        }

        return true;
    }
};

// GitHub-ready main function
int main() {
    Solution sol;

    vector<pair<string,string>> tests = {
        {"anagram", "nagaram"},
        {"rat", "car"},
        {"listen", "silent"},
        {"hello", "bello"}
    };

    for(auto &[s, t] : tests) {
        cout << "s: \"" << s << "\", t: \"" << t << "\" -> ";
        cout << (sol.isAnagram(s, t) ? "True" : "False") << "\n";
    }

    return 0;
}
