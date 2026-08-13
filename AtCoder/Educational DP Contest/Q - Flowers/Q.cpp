#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct SegTree {
    int size;
    vector<ll> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, INT64_MIN);
    }
    void set(int i, ll v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = max(tree[x], v);
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2*x+1, lx, mid);
        else set(i, v, 2*x+2, mid, rx);
        tree[x] = max(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, ll v) { set(i, v, 0, 0, size); }
    ll get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return INT64_MIN;
        int mid = (lx + rx) / 2;
        return max(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    ll get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    int n; cin >> n;
    vector<ll> h(n); for (int i=0; i<n; i++) cin >> h[i];
    vector<ll> a(n); for (int i=0; i<n; i++) cin >> a[i];

    SegTree dp(n+6); dp.set(0, 0);
    for (int i=0; i<n; i++) {
        dp.set(h[i], dp.get(0, h[i]) + a[i]);
    }

    cout << dp.get(0, n+6) << '\n';
}
