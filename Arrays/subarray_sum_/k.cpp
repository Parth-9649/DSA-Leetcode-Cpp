/*
Problem: 974. Subarray Sums Divisible by K
Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/

Approach:
- Use Prefix Sum + HashMap
- If two prefix sums have the same remainder when divided by K,
  the subarray between them has sum divisible by K.

Time Complexity: O(n)
Space Complexity: O(k) (worst O(n))
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;

            int rem = (prefixSum % k + k) % k;

            count += freq[rem];
            freq[rem]++;
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    cout << sol.subarraysDivByK(nums, k) << endl;
    return 0;
}
