#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct SegTree {
    int size;
    vector<ll> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, 0);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2*x+1, lx, mid);
        } else {
            set(i, v, 2*x+2, mid, rx);
        }
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
    ll sum(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return 0;

        int mid = (lx + rx) / 2;
        return sum(l, r, 2*x+1, lx, mid) + sum(l, r, 2*x+2, mid, rx);
    }
    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    SegTree segtree(n);
    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        segtree.set(i, x);
    }

    int i, v, l, r;
    while (m--) {
        cin >> x;
        if (x == 1) {
            cin >> i >> v;
            segtree.set(i, v);
        } else {
            cin >> l >> r;
            cout << segtree.sum(l, r) << '\n';
        }
    }
}
