/* Problem: LeetCode 242 - Valid Anagram Link: https://leetcode.com/problems/valid-anagram/ 
Topic: Hashing 
/ Frequency Counting Complexity: Time - O(n)
 where n = length of string s Space - O(1)
(array of size 26) */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int count[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }

        for (int i = 0; i < t.length(); i++) {
            if (count[t[i] - 'a'] == 0) return false;
            count[t[i] - 'a']--;
        }

        return true;
    }
};

int main() {
    Solution sol;

    vector<pair<string, string>> tests = {
        {"anagram", "nagaram"},
        {"rat", "car"},
        {"listen", "silent"},
        {"hello", "bello"}
    };

    for (auto &p : tests) {
        cout << "s: \"" << p.first << "\", t: \"" << p.second << "\" -> ";
        cout << (sol.isAnagram(p.first, p.second) ? "True" : "False") << "\n";
    }

    return 0;
}
