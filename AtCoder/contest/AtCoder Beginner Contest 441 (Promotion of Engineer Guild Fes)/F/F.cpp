#include <bits/stdc++.h>
using namespace std;

#define ll long long

/*
1) an item (pi,vi) must be chosen iff. 


idea: count the number of ways to achieve the maximum
    also, count the number of ocurrences of each element for each solution
    O(n^2m) => TLE


*/

void solve() {
    int n, M;
    cin >> n >> M;
    vector<array<int,2>> items(n);
    for (int i=0; i<n; i++) {
        cin >> items[i][0] >> items[i][1];
    }

    int opt = 0;
    vector<int> ans(n);
    vector<array<int,2>> dp(M+1);
    for (int i=0; i<n; i++) {
        int m = M - items[i][0];
        fill(dp.begin(), dp.end(), (array<int,2>){INT32_MIN, 0});
        dp[0] = {0, 1};
        for (int j=0; j<n; j++) if (j != i) {
            for (int w = m; w>=items[j][0]; w--) {
                if (dp[w-items[j][0]][0] + items[j][1] == dp[w][0]) {
                    dp[w][1] += dp[w-items[j][0]][1];
                } else {
                    dp[w] = {dp[w-items[j][0]][0] + items[j][1], dp[w-items[j][0]][1]};
                }
            }
        }
        ans[i] = 0;
        for (int w=1; w<=m; w++) {
            if (dp[w][0] > opt) {
                opt = dp[w][0];
                ans[i] = dp[w][1];
            }
        }
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();    
    return 0;
}
