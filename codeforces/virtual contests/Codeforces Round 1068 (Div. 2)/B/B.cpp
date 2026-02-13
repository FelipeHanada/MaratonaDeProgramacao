#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define _1 first
#define _2 second

void precompute() {
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }

    vector<ll> dp[2] = {vector<ll>(n), vector<ll>(n)};
    // dp[0] max, dp[1] min
    dp[0][0] = max(-a[0], b[0]);
    dp[1][0] = min(-a[0], b[0]);
    for (int i=1; i<n; i++) {
        dp[0][i] = max(dp[0][i-1] - a[i], b[i] - dp[1][i-1]);
        dp[1][i] = min(dp[1][i-1] - a[i], b[i] - dp[0][i-1]);
    }

    cout << dp[0][n-1] << '\n';
}

int main() {
    #ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif

    int t;
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
}
