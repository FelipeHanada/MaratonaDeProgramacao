#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<vector<int>> dp(3, vector<int>(n+1));
    dp[0][0] = dp[1][0] = dp[2][0] = 0;
    for (int i=1; i<=n; i++) {
        dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + a[i-1];
        dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + b[i-1];
        dp[2][i] = max(dp[0][i-1], dp[1][i-1]) + c[i-1];
    }

    cout << max(max(dp[0][n], dp[1][n]), dp[2][n]) << '\n';
}
