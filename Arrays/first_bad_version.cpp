/*
Problem Link: https://leetcode.com/problems/first-bad-version/
Approach: Binary Search
Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Dummy API for local testing
bool isBadVersion(int version) {
    int firstBad = 4;   
    return version >= firstBad;
}

int firstBadVersion(int n) {
    int low = 1, high = n;

    while(low < high){
        int mid = low + (high - low) / 2;

        if(isBadVersion(mid))
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    int n = 10;
    cout << "First bad version is: " << firstBadVersion(n);
    return 0;
}
