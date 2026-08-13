#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    auto solve = [&](int k) -> int {
        vector<vector<int>> dp(k+1, vector<int>(n, INT32_MAX));
        // dp[i][j] = least number of inconsistent logs
        //            for i breakouts s.t. the last breakout happened at j

        /*
        dp[kk][last] = min(
            prev[kk][last] + int(a[i] != i - last)

            // happened a breakout
            prev[kk-1][j < last] + int(a[i] != 0)
        )
        */

        dp[0][0] = int(a[0] != 0);
        for (int i=1; i<n; i++) {
            for (int kk=k; kk>=0; kk--) {
                for (int last = 0; last < i; last++) {
                    if (dp[kk][last] != INT32_MAX)
                        dp[kk][last] += int(a[i] != i - last);

                    if (kk && dp[kk-1][last] != INT32_MAX)
                        dp[kk][i] = min(dp[kk][i], dp[kk-1][last] + int(a[i] != 0));
                }
            }
        }

        int ans = INT32_MAX;
        for (int i=0; i<n; i++) ans = min(ans, dp[k][i]);
        return ans;
    };

    for (int i=0; i<n; i++) {
        cout << solve(i) << '\n';
    }
}