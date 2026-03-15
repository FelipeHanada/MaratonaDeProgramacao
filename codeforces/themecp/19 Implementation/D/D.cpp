#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    
    a[0] = 0;
    for (int i=1; i<=n; i++) a[i] += a[i-1];

    vector<vector<ll>> dp(k+1, vector<ll>(n+1, 0));

    for (int i=1; i<=k; i++) {
        for (int j=1; j<=n; j++) {
            if (j - m >= 0) {
                dp[i][j] = dp[i-1][j - m] + a[j] - a[j - m];
            }

            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }

    cout << dp[k][n] << '\n';
}