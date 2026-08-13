#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ll n; int k;
    cin >> n >> k;
    vector<ll> a(k);
    for (int i=0; i<k; i++) cin >> a[i];

    ll ans = 0;
    for (int mask=1; mask<(1<<k); mask++) {
        __int128_t p = 1;
        for (int i=0; p <= n && i<k; i++) {
            if (mask & (1<<i)) p *= a[i];
        }

        ll size = n / p;
        ans += ((__builtin_popcount(mask) & 1) ? 1 : -1) * size;
    }

    cout << ans << '\n';
}
