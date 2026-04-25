#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        ll l, r, g;
        cin >> l >> r >> g;

        l = max(0LL, l / g + bool(l % g));
        r = max(0LL, r/g);

        pair<ll, ll> ans = { -1, -1 };
        for (ll size = r - l; ans.first == -1 && size >= 0; size--) {
            for (ll i = l; i + size <= r; i++) {
                if (__gcd(i, i + size) == 1) {
                    ans = { i, i + size };
                    break;
                }
            }
        }

        if (ans.first == -1) g = 1;
        cout << ans.first * g << ' ' << ans.second * g << '\n';
    }
}
