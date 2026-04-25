#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    ll tt;
    cin >> tt;
    while (tt--) {
        ll c, s, r;
        cin >> c >> r >> s;

        ll tot = (c + r + s - 1) / s;
        cout << tot - (r + s - 1) / s << ' ' << max(0LL, tot - r) << '\n';
    }
}