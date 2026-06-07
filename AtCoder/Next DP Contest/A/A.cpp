#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> dp(n+1), dp0(n+1), dp1(n+1);
    dp[0] = dp0[0] = dp1[0] = 1;
    dp[1] = 1; dp0[1] = dp1[1] = 0;
    dp[2] = 2; dp0[2] = dp1[2] = 1;

    for (int i=3; i<=n; i++) {
        dp[i] = dp0[i-1] + dp1[i-1] + dp[i-1] + dp[i-2];
        dp0[i] = dp1[i-1] + dp[i-2];
        dp1[i] = dp0[i-1] + dp[i-2];
    }

    cout << dp[n] << '\n';
}