#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct Fenwick {
    int n;
    vector<int> a;
    vector<ll> t;
    Fenwick(int n) : n(n), a(n, 0), t(n, 0) { }
    void add(int i, int v) {
        a[i] += v;
        for (; i < n; i = i | (i + 1)) {
            t[i] += v;
        }
    }
    void set(int i, int v) {
        int delta = v - a[i];
        add(i, delta);
    }
    ll get(int r) {
        ll ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += t[r];
        }
        return ans;
    }
    ll get(int l, int r) { return get(r) - get(l - 1); }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int tt; cin >> tt;
    int test_id = 1;
    while (tt--) {
        cout << "Case " << test_id++ << ":\n";
        int n, q; cin >> n >> q;
        Fenwick ft(n);
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            ft.add(i, x);
        }

        while (q--) {
            int op; cin >> op;
            if (op == 1) {
                int i; cin >> i;
                cout << ft.a[i] << '\n';
                ft.set(i, 0);
            } else if (op == 2) {
                int i, v; cin >> i >> v;
                ft.add(i, v);
            } else {
                int i, j; cin >> i >> j;
                cout << ft.get(i, j) << '\n';
            }
        }
    }
}
