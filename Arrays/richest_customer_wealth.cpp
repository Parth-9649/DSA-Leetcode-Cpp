/*
Problem: Richest Customer Wealth
Link: https://leetcode.com/problems/richest-customer-wealth/
Approach: Iterate through each customer, sum their accounts, track maximum
Time Complexity: O(m*n) where m = #customers, n = #banks
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
    int maxWealth = 0;

    for(auto &customer : accounts) {
        int sum = 0;
        for(int money : customer) {
            sum += money;
        }
        maxWealth = max(maxWealth, sum);
    }

    return maxWealth;
}

int main() {
    vector<vector<int>> accounts = {{1,2,3},{3,2,1}};

    int ans = maximumWealth(accounts);

    cout << "Maximum Customer Wealth: " << ans;

    return 0;
}
