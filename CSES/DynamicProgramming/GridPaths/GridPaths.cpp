#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 1000;

int dp[MAX_N][MAX_N];

int solve(int i, int j) {
    if (dp[i][j] >= 0) return dp[i][j];

    int ans = 0;
    if (i > 0) ans = (ans + solve(i-1, j)) % MOD;
    if (j > 0) ans = (ans + solve(i, j-1)) % MOD;
    return dp[i][j] = ans;
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++)
        fill_n(dp[i], n, -1);

    dp[0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++){
            char c; cin >> c;
            if (c == '*')
                dp[i][j] = 0;
        }
    }

    cout << solve(n-1, n-1) << "\n";
}
