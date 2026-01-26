#include <bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Difficulty: Hard
// Concept: Monotonic Increasing Stack

int largestRectangleArea(vector<int>& heights) {
    stack<int> st; // stores indices of bars
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i < n; i++) {
        // Pop all bars taller than current, compute area
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int top = st.top(); st.pop();
            int height = heights[top];
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }

    // Process remaining bars in stack
    while (!st.empty()) {
        int top = st.top(); st.pop();
        int height = heights[top];
        int width = st.empty() ? n : n - st.top() - 1;
        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}

int main() {
    vector<vector<int>> testCases = {
        {2,1,5,6,2,3},
        {2,4},
        {6,2,5,4,5,1,6}
    };

    for (auto& heights : testCases) {
        cout << "Histogram: ";
        for (int h : heights) cout << h << " ";
        cout << "\nMax Rectangle Area: " << largestRectangleArea(heights) << "\n\n";
    }

    return 0;
}
