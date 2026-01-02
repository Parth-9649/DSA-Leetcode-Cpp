/*
Problem: Contains Duplicate
Link: https://leetcode.com/problems/contains-duplicate/
Difficulty: Easy
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};

    cout << "Contains Duplicate? " << (sol.containsDuplicate(nums) ? "Yes" : "No") << endl;

    return 0;
}
