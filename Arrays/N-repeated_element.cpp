/*
Problem: N-Repeated Element in Size 2N Array
Link: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
Difficulty: Easy-Medium
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> count;

        for(int num : nums){
            count[num]++;
            if(count[num] > 1) return num;
        }

        return -1; // never reached
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,1,2,5,3,2};

    cout << "N-Repeated Element: " << sol.repeatedNTimes(nums) << endl;

    return 0;
}
