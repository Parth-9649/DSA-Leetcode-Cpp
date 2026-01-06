// Problem: 167. Two Sum II - Input Array Is Sorted
// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Concept: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target)
            return {left + 1, right + 1};
        else if (sum < target)
            left++;
        else
            right--;
    }
    
    return {};
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> res = twoSum(numbers, target);

    cout << "Indices: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
