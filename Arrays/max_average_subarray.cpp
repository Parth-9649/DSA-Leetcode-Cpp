// Problem: 643. Maximum Average Subarray I
// Link: https://leetcode.com/problems/maximum-average-subarray-i/
// Concept: Sliding Window (Fixed Size)
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;

    for (int i = 0; i < k; i++)
        sum += nums[i];

    int maxSum = sum;

    for (int i = k; i < n; i++) {
        sum += nums[i] - nums[i - k]; // slide window
        if (sum > maxSum)
            maxSum = sum;
    }

    return (double)maxSum / k;
}

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double result = findMaxAverage(nums, k);

    cout << "Maximum Average Subarray: " << result << endl;
    return 0;
}
