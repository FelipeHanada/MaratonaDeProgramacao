#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;
#define _0 first
#define _1 second

int main() {
    ll l, r, d, u;
    cin >> l >> r >> d >> u;

    ll ans = 0;
    for (ll x = l+(abs(l)%2); x<=r; x+=2) {
        if (min(abs(x), u) >= max(-abs(x), d))
            ans += min(abs(x), u) - max(-abs(x), d) + 1;
    }

    for (ll y = d+(abs(d)%2); y<=u; y+=2) {
        if (min(abs(y), r) >= max(-abs(y), l))
            ans += min(abs(y), r) - max(-abs(y), l) + 1;
    }

    for (ll x = l+(abs(l)%2); x<=r; x+=2) {
        if (-x >= d && -x <= u) ans--;
        if (x >= d && x <= u) ans--;
    }
    if (l <= 0 && r >= 0 && d <= 0 && u >= 0) ans++;

    cout << ans << '\n';
}
