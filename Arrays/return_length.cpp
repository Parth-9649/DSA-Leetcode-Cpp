#include <bits/stdc++.h>
using namespace std;

/*
LeetCode 58: Length of Last Word
https://leetcode.com/problems/length-of-last-word/

Approach:
- Traverse from the end of the string
- Skip trailing spaces
- Count characters until a space is found

Time Complexity: O(n)
Space Complexity: O(1)
*/

int lengthOfLastWord(string s) {
    int i = s.length() - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ')
        i--;

    int len = 0;
    // Count characters of last word
    while (i >= 0 && s[i] != ' ') {
        len++;
        i--;
    }
    return len;
}

int main() {
    string s = "Hello World   ";
    cout << lengthOfLastWord(s);
    return 0;
}
