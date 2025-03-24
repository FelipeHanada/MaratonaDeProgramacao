#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e6;
constexpr int MOD = 1e9+7;

int main() {
    int n;
    cin >> n;

    vector<int> dp(MAXN+1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    for (int i=7; i<=n; i++) {
        dp[i] = 0;
        for (int j=1; j<=6; j++)
            dp[i] = (dp[i] + dp[i-j]) % MOD;
    }

    cout << dp[n] << "\n";
}