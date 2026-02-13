#include <bits/stdc++.h>
using namespace std;


#define ll long long
constexpr int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> val(n);
    for (int i=0; i<n; i++) cin >> val[i];

    vector<array<ll,3>> edges;
    vector<map<ll, int>> dp(n);
    // dp[{y, val}] = number of paths that ends on y and the previous value is x
    for (int i=0; i<m; i++) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        edges.push_back({val[y], x, y});

        dp[y][val[x]]++;
    }

    sort(edges.begin(), edges.end());

    int ans = m;
    for (auto [_, x, y] : edges) {
        // this edge can be added to paths that ends on x iff.
        // val = val[y] - val[x]
        if (dp[x].count(val[y] - val[x])) {
            ll delta = dp[x][val[y] - val[x]];
            dp[y][val[x]] = (dp[y][val[x]] + delta) % MOD;
            ans = (ans + delta) % MOD;
        }
    }

    cout << ans << '\n';
}

int main() {
    int tt;
    cin >> tt;

    while (tt--) solve();
}
