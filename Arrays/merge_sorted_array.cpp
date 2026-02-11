/*
Problem: 88. Merge Sorted Array
Link: https://leetcode.com/problems/merge-sorted-array/

Approach:
- Use three pointers from the end.
- Compare elements of nums1 and nums2.
- Place the larger one at the end of nums1.
- Copy remaining elements of nums2 if any.

Time Complexity: O(m + n)
Space Complexity: O(1)  (in-place)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;        // last valid element in nums1
        int j = n - 1;        // last element in nums2
        int k = m + n - 1;    // last position in nums1

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }

        // Copy remaining nums2 elements if any
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;

    sol.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int x : nums1)
        cout << x << " ";
    cout << endl;

    return 0;
}
