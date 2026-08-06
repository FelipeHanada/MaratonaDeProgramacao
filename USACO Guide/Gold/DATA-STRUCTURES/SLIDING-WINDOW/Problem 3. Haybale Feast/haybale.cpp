#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);

    ll n, m; cin >> n >> m;
    vector<ll> f(n), s(n);
    for (int i=0; i<n; i++) cin >> f[i] >> s[i];

    ll curr = 0;
    ll ans = INT64_MAX;
    multiset<ll> ms;
    int l = 0, r = 0;
    while (l < n) {
        while (r < n && curr < m) {
            curr += f[r];
            ms.insert(s[r]);
            r++;
        }

        if (curr >= m) ans = min(ans, *ms.rbegin());

        curr -= f[l];
        ms.extract(s[l]);
        l++;
    }

    cout << ans << '\n';
}
