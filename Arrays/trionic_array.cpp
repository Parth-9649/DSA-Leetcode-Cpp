/*
    Problem: Check if an array is Trionic
    A trionic array strictly:
        1) increases,
        2) then decreases,
        3) then increases again.

    Returns true if the whole array follows this pattern.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int i = 0;

        // Phase 1: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        if (i == 0 || i == n - 1) return false;
        int p = i;

        // Phase 2: strictly decreasing
        while (i + 1 < n && nums[i] > nums[i + 1]) {
            i++;
        }

        if (i == p || i == n - 1) return false;

        // Phase 3: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }

        return i == n - 1;
    }
};

/* -------- GitHub Test Driver -------- */
int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 5, 4, 2, 6, 8};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> nums3 = {5, 4, 3, 2, 1};
    vector<int> nums4 = {1, 4, 7, 3, 2, 5};

    cout << sol.isTrionic(nums1) << endl; // expected: 1
    cout << sol.isTrionic(nums2) << endl; // expected: 0
    cout << sol.isTrionic(nums3) << endl; // expected: 0
    cout << sol.isTrionic(nums4) << endl; // expected: 1

    return 0;
}
