/*
LeetCode 347. Top K Frequent Elements
https://leetcode.com/problems/top-k-frequent-elements/

Given an integer array nums and an integer k, return the k most frequent elements.

Approach: Bucket Sort
1) Count frequency of each element using unordered_map.
2) Create buckets where index = frequency and value = list of numbers with that frequency.
3) Traverse buckets from highest frequency to lowest and collect k elements.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int n = nums.size();
        vector<vector<int>> bucket(n + 1);

        for (auto &it : freq) {
            int num = it.first;
            int f = it.second;
            bucket[f].push_back(num);
        }

        vector<int> result;
        for (int i = n; i >= 1 && result.size() < k; i--) {
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k)
                    break;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> ans = sol.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
