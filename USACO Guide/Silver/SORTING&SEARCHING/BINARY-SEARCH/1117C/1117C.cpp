#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
    ll x1, y1, x2, y2, n; string s;
    cin >> x1 >> y1 >> x2 >> y2 >> n >> s;

    vector<ll> pdx(n+1), pdy(n+1);
    pdx[0] = pdy[0] = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'U') {
            pdx[i+1] = pdx[i];
            pdy[i+1] = pdy[i] + 1;
        } else if (s[i] == 'D') {
            pdx[i+1] = pdx[i];
            pdy[i+1] = pdy[i] - 1;
        } else if (s[i] == 'L') {
            pdx[i+1] = pdx[i] - 1;
            pdy[i+1] = pdy[i];
        } else {
            pdx[i+1] = pdx[i] + 1;
            pdy[i+1] = pdy[i];
        }
    }

    x2 -= x1;
    y2 -= y1;

    auto check = [&](ll k) -> bool {
        ll x = pdx.back() * (k/n) + pdx[k%n];
        ll y = pdy.back() * (k/n) + pdy[k%n];
        ll dx = abs(x - x2), dy = abs(y - y2);
        return dx + dy <= k;
    };

    if (!x2 && !y2) {
        cout << "0\n";
        return 0;
    }

    ll l = 0, r = ll(2e14) + 100;
    if (!check(r)) {
        cout << "-1\n";
        return 0;
    }

    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }

    cout << r << '\n';
}
