#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    int n;
    cin >> n;
    deque<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    ll ans = INT64_MAX;
    for (int i=0; i<3; i++) {
        vector<ll> dp(n+1, INT32_MAX);
        dp[0] = 0;
        for (int i=2; i<=n; i++) {
            if (dp[i-2] != INT64_MAX) dp[i] = dp[i-2] + abs(a[i-2]-a[i-1]);
            if (i > 2 && dp[i-3] != INT64_MAX) {
                int x1 = abs(a[i-3]-a[i-2]) + abs(a[i-3]-a[i-1]);
                int x2 = abs(a[i-2]-a[i-3]) + abs(a[i-2]-a[i-1]);
                int x3 = abs(a[i-1]-a[i-3]) + abs(a[i-1]-a[i-2]);
                dp[i] = min(dp[i], dp[i-3] + min(x1, min(x2, x3)));
            }
        }
    
        ans = min(ans, dp[n]);
        a.push_front(a.back());
        a.pop_back();
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
