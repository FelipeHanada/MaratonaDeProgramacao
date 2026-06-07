#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    auto check = [&](ll target) -> bool {
        // check if we can get a min atleast target
        ll cost = 0;
        for (ll i=0; i<n; i++) {
            cost += max(0LL, (target - a[i] + i)/(i+1));
            if (cost > k) return 0;
        }

        return cost <= k;
    };

    ll l = 0, r = (INT64_MAX>>2);
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    cout << l << '\n';
}
