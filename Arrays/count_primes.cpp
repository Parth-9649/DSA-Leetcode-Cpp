/*
LeetCode Problem: 204. Count Primes
Problem Link: https://leetcode.com/problems/count-primes/

Approach:
Use Sieve of Eratosthenes to mark non-prime numbers and count primes
strictly less than n.

Time Complexity: O(n log log n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        int cnt = 0;
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;

        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                cnt++;
                for (int j = i * 2; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Number of primes less than " << n << " = "
         << sol.countPrimes(n) << endl;

    return 0;
}
