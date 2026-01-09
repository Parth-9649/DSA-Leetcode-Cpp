// Problem: Sliding Window Maximum
// Link: https://leetcode.com/problems/sliding-window-maximum/
// Approach: Deque to maintain max in O(1)
// Time: O(n), Space: O(k)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        
        for(int i = 0; i < nums.size(); i++) {
            if(!dq.empty() && dq.front() == i - k) dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            
            dq.push_back(i);
            
            if(i >= k - 1) result.push_back(nums[dq.front()]);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = sol.maxSlidingWindow(nums, k);
    cout << "Sliding Window Maximums: ";
    for(int val : result) cout << val << " ";
    cout << endl;
    return 0;
}
