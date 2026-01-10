// Problem: Fruit Into Baskets
// Link: https://leetcode.com/problems/fruit-into-baskets/
// Approach: Sliding Window
// Time: O(n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> mp;
    int l = 0, ans = 0;

    for (int r = 0; r < fruits.size(); r++) {
        mp[fruits[r]]++;

        while (mp.size() > 2) {
            mp[fruits[l]]--;
            if (mp[fruits[l]] == 0)
                mp.erase(fruits[l]);
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> fruits(n);
    for (int i = 0; i < n; i++) cin >> fruits[i];
    cout << totalFruit(fruits);
    return 0;
}
