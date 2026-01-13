// Problem: 42. Trapping Rain Water
// Link: https://leetcode.com/problems/trapping-rain-water/
// Approach: Two Pointers
// Time: O(n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] >= leftMax)
                    leftMax = height[l];
                else
                    water += leftMax - height[l];
                l++;
            } else {
                if (height[r] >= rightMax)
                    rightMax = height[r];
                else
                    water += rightMax - height[r];
                r--;
            }
        }
        return water;
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped Water: " << sol.trap(height) << endl;
    return 0;
}
