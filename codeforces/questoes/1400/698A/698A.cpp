#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // dp[4][101] def.: maximum number of rests taken on the jth day
    // where on the day before Vasya done:
    // 0. nothing
    // 1. contest
    // 2. gym
    // 3. both

    vector<vector<int>> dp(4, vector<int>(n+1, INT32_MAX));
    int x;
    dp[0][0] = dp[1][0] = dp[2][0] = dp[3][0] = 0;
    for (int i=1; i<=n; i++) {
        cin >> x;

        // you always can do nothing
        dp[0][i] = min(min(dp[0][i-1], dp[1][i-1]), min(dp[2][i-1], dp[3][i-1])) + 1;

        if (x & 1) {
            // contest
            dp[1][i] = min(dp[0][i-1], dp[2][i-1]);
            // the day before she did nothing or she only went to the gym
        }

        if (x & 2) {
            // gym open
            dp[2][i] = min(dp[0][i-1], dp[1][i-1]);
        }

        if (x == 3) {
            dp[3][i] = dp[0][i-1];
        }
    }

    int ans = min(min(dp[0][n], dp[1][n]), min(dp[2][n], dp[3][n]));
    cout << ans << '\n';
}
