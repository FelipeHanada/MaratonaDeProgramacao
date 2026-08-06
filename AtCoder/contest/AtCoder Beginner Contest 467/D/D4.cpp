#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _f first
#define _s second

#define pll pair<ll, ll>

ll dot(pll u, pll v) {
    return u._f * v._f + u._s * v._s;
}
pll rot90(pll v) {
    return { v._s, -v._f };
}

int main() {
    int tt; cin >> tt;
    while (tt--) {
        pll p, q, r, s;
        cin >> p._f >> p._s >> q._f >> q._s;
        cin >> r._f >> r._s >> s._f >> s._s;

        pll u = make_pair(p._f - q._f, p._s - q._s);
        pll v = make_pair(r._f - s._f, r._s - s._s);

        if (dot(u, rot90(v)) == 0) {
            pll x = { p._f + q._f, p._s + q._s };
            pll y = { r._f + s._f, r._s + s._s };
            
            if (abs(dot(u, { y._f - x._f, y._s - x._s })) == 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else {
            cout << "Yes\n";
        }
    }
}


