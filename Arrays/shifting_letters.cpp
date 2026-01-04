// Problem: Shifting Letters II (Range Update)
// Approach: Difference array + prefix sum
// Time Complexity: O(n + m)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abc";
    vector<vector<int>> shifts = {{0,1,1},{1,2,0}};

    int n = s.size();
    vector<int> diff(n+1, 0);

    for(auto &op : shifts){
        int l = op[0], r = op[1], dir = op[2];
        int val = dir==1 ? 1 : -1;
        diff[l] += val;
        diff[r+1] -= val;
    }

    int cum = 0;
    for(int i=0;i<n;i++){
        cum += diff[i];
        int shift = (cum % 26 + 26) % 26;
        s[i] = ((s[i]-'a'+shift)%26)+'a';
    }

    cout << s;
    return 0;
}
