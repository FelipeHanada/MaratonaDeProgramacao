#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;
    while (tt--) {
        ll s, m;
        cin >> s >> m;

        auto check = [&](__int128_t n) -> bool {
            __int128_t rem = __int128_t(m) * n - s;
            if (rem < 0) return 0;
            for (ll i=62; i>=0; i--) if (m & (1LL<<i)) {
                rem -= min((rem>>i), n) * (1LL<<i);
            }

            return rem == 0;
        };

        // m * n - s >= 0
        // n >= (1e18 + s) / m
        __int128_t l = 0, r = __int128_t(1e19);
        if (!check(r)) {
            cout << "-1\n";
            continue;
        }
        while (r - l > 1) {
            __int128_t mid = (r + l) / 2;
            if (check(mid)) r = mid;
            else l = mid;
        }

        ll llr = r;
        cout << llr << '\n';
    }
}
