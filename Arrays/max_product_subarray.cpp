// Problem: Maximum Product Subarray
// Link: https://leetcode.com/problems/maximum-product-subarray/
// Approach: Dynamic Programming (tracking max and min products)
// Time: O(n), Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) swap(maxProd, minProd);
            
            maxProd = max(nums[i], nums[i] * maxProd);
            minProd = min(nums[i], nums[i] * minProd);
            
            result = max(result, maxProd);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,3,-2,4};
    cout << "Maximum Product Subarray: " << sol.maxProduct(nums) << endl;
    return 0;
}
