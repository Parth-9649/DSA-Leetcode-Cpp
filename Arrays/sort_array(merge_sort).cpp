/*
LeetCode 912 - Sort an Array
https://leetcode.com/problems/sort-an-array/

Algorithm: Merge Sort (Divide and Conquer)
Time Complexity: O(n log n)
Space Complexity: O(n) - extra arrays for merging
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() <= 1) return nums;

        int mid = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        left = sortArray(left);
        right = sortArray(right);

        vector<int> result;
        int i = 0, j = 0;

        while(i < left.size() && j < right.size()) {
            if(left[i] <= right[j]) result.push_back(left[i++]);
            else result.push_back(right[j++]);
        }

        while(i < left.size()) result.push_back(left[i++]);
        while(j < right.size()) result.push_back(right[j++]);

        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {5, 2, 4, 1, 3},
        {10, -1, 2, 5, 0},
        {3, 3, 2, 1, 4}
    };

    for(auto &nums : testCases) {
        vector<int> sorted = sol.sortArray(nums);
        for(int x : sorted) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
