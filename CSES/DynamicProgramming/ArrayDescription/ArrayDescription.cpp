#include <bits/stdc++.h>
using namespace std;


constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 1e5;
constexpr int MAX_M = 100;

int x[MAX_N];
int dp[MAX_M + 1][MAX_N + 1];
// dp[m][n] = number of arrays until n that ends on m 

int main() {
    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++)
        cin >> x[i];

    for (int i=0; i<=m; i++) {
        fill_n(dp[i], n + 1, 0);
    }

    if (x[0] == 0) {
        for (int i=0; i<=m; i++)
            dp[i][1] = 1;
    } else {
        dp[x[0]][1] = 1;
    }

    for (int i=1; i<n; i++) {
        if (x[i] != 0) {
            if (x[i] > 1) dp[x[i]][i + 1] = (dp[x[i]][i + 1] + dp[x[i] - 1][i]) % MOD;
            if (x[i] < m) dp[x[i]][i + 1] = (dp[x[i]][i + 1] + dp[x[i] + 1][i]) % MOD;
            dp[x[i]][i + 1] = (dp[x[i]][i + 1] + dp[x[i]][i]) % MOD;
        } else {
            dp[1][i + 1] = (dp[1][i + 1] + dp[1][i]) % MOD;
            dp[2][i + 1] = (dp[2][i + 1] + dp[1][i]) % MOD;

            dp[m][i + 1] = (dp[m][i + 1] + dp[m][i]) % MOD;
            dp[m - 1][i + 1] = (dp[m - 1][i + 1] + dp[m][i]) % MOD;

            for (int j=2; j<m; j++) {
                dp[j - 1][i + 1] = (dp[j - 1][i + 1] + dp[j][i]) % MOD;
                dp[j + 1][i + 1] = (dp[j + 1][i + 1] + dp[j][i]) % MOD;

                dp[j][i + 1]     = (dp[j][i + 1]     + dp[j][i]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i=1; i<=m; i++) {
        ans = (ans + dp[i][n]) % MOD;
    }
    cout << ans << "\n";
}