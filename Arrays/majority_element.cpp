/*
Problem: Majority Element
Link: https://leetcode.com/problems/majority-element/
Difficulty: Easy
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;

        for (int num : nums) {
            count[num]++;
            if (count[num] > nums.size() / 2) {
                return num;
            }
        }

        return -1; 
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "Majority Element: " << sol.majorityElement(nums) << endl;

    return 0;
}
