// Problem: 3. Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Concept: Sliding Window (Variable Size)
// Time Complexity: O(n)
// Space Complexity: O(min(n, charset))

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;
    int left = 0, right = 0, maxLen = 0;
    int n = s.size();

    while (right < n) {
        if (window.find(s[right]) == window.end()) {
            window.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        } else {
            window.erase(s[left]);
            left++;
        }
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    cout << "Length of Longest Substring Without Repeating Characters: " << result << endl;
    return 0;
}
