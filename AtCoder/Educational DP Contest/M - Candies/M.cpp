#include <bits/stdc++.h>
using namespace std;


constexpr int MOD = 1e9+7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(k+2, 0));
    dp[0][0] = 0;
    for (int i=1; i<=k+1; i++) dp[0][i] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=k+1; j>0; j--) {
            dp[i][j] = (MOD + (dp[i][j] + (dp[i-1][j] - dp[i-1][max(0, j-a[i-1]-1)]) % MOD) % MOD) % MOD;
        }
        for (int j=1; j<=k+1; j++) {
            dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << (MOD + dp[n][k+1] - dp[n][k]) % MOD << '\n';
}