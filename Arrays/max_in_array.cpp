/*
Problem: Find Maximum in Array
Link: Self practice
Approach: Iterate through array and keep track of max
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int findMaximum(vector<int>& nums) {
    int maxVal = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }

    return maxVal;
}

int main() {
    vector<int> nums = {3, 7, 2, 9, 4};

    int ans = findMaximum(nums);

    cout << "Maximum Element: " << ans;

    return 0;
}
