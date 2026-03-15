#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() { _
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n, m, l;
        cin >> n >> m >> l;
        vector<ll> a(n+1);
        a[0] = 0;
        for (ll i=1; i<=n; i++) cin >> a[i];
        a.push_back(l);
        vector<ll> b(n+1);
        for (ll i=0; i<n+1; i++) b[i] = a[i+1] - a[i];

        map<ll, ll> cnt; cnt[0] = min(m, n+1);
        for (ll i=0; i<n; i++) {
            while (b[i]) {
                auto it = cnt.begin();
                auto itn = it; itn++;
                auto [k, v] = *it;
                ll limit;
                if (itn == cnt.end()) limit = INT64_MAX;
                else {
                    auto [kn, vn] = *itn;
                    limit = kn;
                }

                ll inc = min((b[i]+v-1)/v, limit - k);
                ll x = max(0LL, min(b[i] - inc * v + v, v));

                cnt[k + inc] += x;
                cnt[k + inc - 1] += v - x;
                cnt[k] -= v;
                if (!cnt[k + inc]) cnt.erase(k + inc);
                if (!cnt[k + inc - 1]) cnt.erase(k + inc - 1);
                if (!cnt[k]) cnt.erase(k);

                b[i] -= x * inc + (v - x) * (inc - 1);
            }

            if (!(--cnt[cnt.rbegin()->first])) {
                cnt.erase(cnt.rbegin()->first);
            }
            if (i<n-min(n+1, m)+1) cnt[0]++;
        }

        cout << cnt.rbegin()->first + b.back() << '\n';
    }
}
