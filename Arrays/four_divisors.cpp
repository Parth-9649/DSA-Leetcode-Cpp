/*
Problem: Four Divisors
Link: https://leetcode.com/problems/four-divisors/
Difficulty: Medium
Time Complexity: O(N * sqrt(M))
Space Complexity: O(1) extra
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {21, 4, 7};
    long long total = 0;

    for (int num : nums) {
        vector<int> divs;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                divs.push_back(i);
                if (i != num / i) {
                    divs.push_back(num / i);
                }
            }
            if (divs.size() > 4) break;
        }
        if (divs.size() == 4) {
            for (int d : divs) total += d;
        }
    }

    cout << total << endl;
    return 0;
}
