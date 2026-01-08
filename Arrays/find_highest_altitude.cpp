// Problem: Find the Highest Altitude
// Link: https://leetcode.com/problems/find-the-highest-altitude/
// Time: O(n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> gain = {-5, 1, 5, 0, -7};

    int curr = 0, maxAlt = 0;
    for (int g : gain) {
        curr += g;
        maxAlt = max(maxAlt, curr);
    }

    cout << maxAlt;
    return 0;
}
