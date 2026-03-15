#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    map<int, pair<ll, ll>> s;
    for (int i=0; i<n; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        s[l].first += v;
        s[r].first -= v;
    }

    ll acc = 0;
    for (auto &[x, p] : s) {
        p.first = acc = p.first + acc;
    }

    acc = 0;
    ll v = 0;
    int last = 0;
    for (auto &[x, p] : s) {
        acc += (x - last) * v;
        p.second = acc;

        v = p.first;
        last = x;
    }

    auto get = [&](int i) -> ll {
        auto it = s.upper_bound(i);

        if (it == s.begin()) return 0;
        auto [x, p] = *(--it);

        return p.second + (i - x + 1) * p.first;
    };

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << get(r-1) - get(l-1) << '\n';
    }
}
