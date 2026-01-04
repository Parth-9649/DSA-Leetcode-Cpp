// Problem: Find All Duplicates in an Array
// Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Approach: Index marking / in-place negation
// Time Complexity: O(n)
// Space Complexity: O(1) (ignoring output)

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> res;

    for (int num : nums) {
        int idx = abs(num) - 1;
        if (nums[idx] < 0)
            res.push_back(abs(num));
        else
            nums[idx] = -nums[idx];
    }

    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size() - 1) cout << ",";
    }
    cout << "]";
    return 0;
}
