/*
Problem: 240. Search a 2D Matrix II
Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
Approach: Start from top-right, eliminate row/column each step.
Time Complexity: O(m + n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int r = 0, c = cols - 1;

        while(r < rows && c >= 0) {
            if(matrix[r][c] == target)
                return true;
            else if(matrix[r][c] > target)
                c--;
            else
                r++;
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    cout << sol.searchMatrix(matrix, 5) << endl; // 1 (true)
}
