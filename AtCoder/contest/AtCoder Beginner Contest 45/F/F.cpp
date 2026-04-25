#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


ll add(ll a, ll b, ll md) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

int main() { _
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (ll i=0; i<n; i++) cin >> a[i];

        ll ans = 0;
        vector<pair<ll,ll>> l, r;
        for (ll i=0; i<=n/2; i++) {
            ll j = n-1-i;

            if (a[i] == a[j]) {
                l.push_back({0, 0});
                r.push_back({0, 0});
            } else {
                ll lc = 0, rc = 0;
                if (a[i] >= m) {
                    lc++;
                    a[i] = add(a[i], 1, m);
                }
                if (a[j] >= m) {
                    rc++;
                    a[j] = add(a[j], 1, m);
                }

                if (a[i] < a[j]) {
                    l.push_back({ lc + a[j] - a[i], rc });
                    r.push_back({ lc, rc + a[i] - a[j] + m });
                } else {
                    l.push_back({ lc + a[j] - a[i] + m, rc });
                    r.push_back({ lc, rc + a[i] - a[j] });
                }
            }
        }

        vector<ll> dp1(l.size()), dp2(l.size());
        dp1[0] = l[0].first + l[0].second;
        dp2[0] = r[0].first + r[0].second;

        for (ll i=1; i<l.size(); i++) {
            dp1[i] = min(
                dp1[i-1] + (max(max(0LL, l[i].first-l[i-1].first), max(0LL, l[i].second - l[i-1].second))),
                dp2[i-1] + (max(max(0LL, l[i].first-r[i-1].first), max(0LL, l[i].second - r[i-1].second)))
            );

            dp2[i] = min(
                dp1[i-1] + (max(max(0LL, r[i].first-l[i-1].first), max(0LL, r[i].second - l[i-1].second))),
                dp2[i-1] + (max(max(0LL, r[i].first-r[i-1].first), max(0LL, r[i].second - r[i-1].second)))
            );
        }

        cout << min(dp1.back(), dp2.back()) << '\n';
    }
}
