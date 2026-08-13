#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    for (int i=0; i<n; i++) if (a[i] > b[i]) swap(a[i], b[i]);

    auto check = [&](ll k) -> bool {
        vector<bool> x(n), y(n);
        for (int i=0; i<n; i++) x[i] = (a[i] >= k);
        for (int i=0; i<n; i++) y[i] = (b[i] >= k);

        int zero = 0, one = 0;
        bool last = 1;
        for (int i=0; i<n; i++) {
            if (x[i]) {
                one++;
                last = 1;
            } else if (!y[i]) {
                zero += last;
                last = 0;
            }
        }

        return one > zero;
    };

    ll l = INT64_MAX, r = INT64_MIN;
    for (int i=0; i<n; i++) {
        l = min(l, a[i]);
        r = max(r, b[i]);
    }
    r++;

    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) solve();
}
