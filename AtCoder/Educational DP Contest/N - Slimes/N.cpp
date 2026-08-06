#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<ll> prefix(n+1);
    prefix[0] = 0;
    for (int i=1; i<=n; i++) prefix[i] = prefix[i-1] + a[i-1];
    vector<vector<ll>> dp(n+1, vector<ll>(n));

    fill(dp[0].begin(), dp[0].end(), 0);
    fill(dp[1].begin(), dp[1].end(), 0);

    for (int len=2; len<=n; len++) {
        for (int i=0; i+len <= n; i++) {
            dp[len][i] = INT64_MAX;
            for (int k=1; k<len; k++) {
                dp[len][i] = min(
                    dp[len][i],
                    dp[k][i] + dp[len-k][i+k] + prefix[i+len] - prefix[i]
                ); 
            }

        }
    }

    cout << dp[n][0] << '\n';
}