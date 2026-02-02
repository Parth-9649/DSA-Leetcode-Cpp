// Problem: LeetCode 20 - Valid Parentheses
// Link: https://leetcode.com/problems/valid-parentheses/
// Complexity: O(n) time, O(n) space

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char c : s) {
            // If opening bracket, push to stack
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                // Closing bracket: check top
                if(st.empty()) return false;
                
                char top = st.top();
                if((c == ')' && top == '(') ||
                   (c == '}' && top == '{') ||
                   (c == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        // If stack empty, all brackets matched
        return st.empty();
    }
};

int main() {
    Solution sol;
    vector<string> tests = {"()", "()[]{}", "(]", "([)]", "{[]}", "(((())))", "[({})]"};

    for(auto &s : tests) {
        cout << "Input: " << s 
             << " -> " << (sol.isValid(s) ? "Valid" : "Invalid") 
             << endl;
    }

    return 0;
}
