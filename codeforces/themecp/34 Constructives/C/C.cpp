#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i] >> b[i];

    // we can take a greedy strategy
    // we can caracterize each run by the first monster to die

    ll tot = 0;
    vector<ll> cost(n, 0);
    for (int i=1; i<n; i++) tot += cost[i] = max(0LL, a[i] - b[i-1]);
    tot += cost[0] = max(0LL, a[0] - b[n-1]);

    ll ans = INT64_MAX;
    for (int i=0; i<n; i++) {
        ans = min(ans, tot - cost[i] + a[i]);
    }

    cout << ans << '\n';
}

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}