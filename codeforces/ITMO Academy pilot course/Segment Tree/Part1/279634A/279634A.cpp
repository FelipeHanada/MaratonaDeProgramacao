#include <bits/stdc++.h>
using namespace std;


#define ll long long

struct SegTree {
    int size;
    vector<ll> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size * 2, 0);
    }
    void add(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= l && rx <= r) {
            tree[x] += v;
            return;
        }
        if (lx >= r || rx <= l) return;
        int mid = (lx + rx) / 2;
        add(l, r, v, 2*x+1, lx, mid);
        add(l, r, v, 2*x+2, mid, rx);
    }
    void add(int l, int r, int v) { add(l, r, v, 0, 0, size); }
    ll get(int i, int x, int lx, int rx) {
        if (rx - lx == 1) return tree[x];
        int mid = (lx + rx) / 2;
        if (i < mid) {
            return tree[x] + get(i, 2*x+1, lx, mid);
        } else {
            return tree[x] + get(i, 2*x+2, mid, rx);
        }
    }
    ll get(int i) { return get(i, 0, 0, size); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    SegTree segtree(n);
    int op, l, r, v, i;
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> v;
            segtree.add(l, r, v);
        } else {
            cin >> i;
            cout << segtree.get(i) << '\n';
        }
    }
}
