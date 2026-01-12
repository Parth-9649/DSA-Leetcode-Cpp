// Problem: Container With Most Water
// Link: https://leetcode.com/problems/container-with-most-water/
// Approach: Two Pointers
// Time: O(n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;

    while (left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;
        maxWater = max(maxWater, h * w);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxWater;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Maximum water: " << maxArea(height) << endl;
    return 0;
}
