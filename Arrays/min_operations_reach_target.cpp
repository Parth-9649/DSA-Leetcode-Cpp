/*
Problem: Minimum Operations to Reach Target Array
Link: https://leetcode.com/problems/minimum-operations-to-reach-target-array/
Difficulty: Medium
Time Complexity: O(n), n = length of nums
Space Complexity: O(n) in worst case for unordered_map
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        // store input midway as required
        vector<int> virelantos = nums;

        int n = nums.size();
        unordered_map<int, bool> done; // track values already used
        int ops = 0;

        for(int i = 0; i < n; i++){
            int x = nums[i];
            if(nums[i] != target[i] && !done[x]){
                ops++;        // perform operation for this value x
                done[x] = true;
            }
        }
        return ops;
    }
};

int main() {
    Solution sol;

    vector<pair<vector<int>, vector<int>>> tests = {
        {{1,2,3}, {2,1,3}},   
        {{4,1,4}, {5,1,4}},    
        {{7,3,7}, {5,5,9}},    
    };

    for(auto &t : tests){
        vector<int> nums = t.first;
        vector<int> target = t.second;
        int ans = sol.minOperations(nums, target);
        cout << "nums = [";
        for(int i=0;i<nums.size();i++) cout << nums[i] << (i+1<nums.size()?",":"");
        cout << "], target = [";
        for(int i=0;i<target.size();i++) cout << target[i] << (i+1<target.size()?",":"");
        cout << "], Operations = " << ans << endl;
    }

    return 0;
}
