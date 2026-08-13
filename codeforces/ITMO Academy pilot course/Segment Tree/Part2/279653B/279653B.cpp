#include <bits/stdc++.h>
using namespace std;


using ll = long long;
constexpr int md = int(1e9)+7;
int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
int mult(int a, int b) {
    return (ll(a) * b) % md;
}


struct SegTree {
    int size;
    vector<int> lazy;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        lazy.assign(size * 2, 1);
        tree.resize(size * 2);
        _setup(0, 0, size);
    }
    void _setup(int x, int lx, int rx) {
        tree[x] = rx - lx;
        if (rx - lx == 1) return;
        int mid = (lx + rx) / 2;
        _setup(2*x+1, lx, mid);
        _setup(2*x+2, mid, rx);
    }
    void push(int x, int lx, int rx) {
        if (lazy[x] == 1) return;

        tree[x] = mult(tree[x], lazy[x]);
        if (rx - lx > 1) {
            lazy[2*x+1] = mult(lazy[2*x+1], lazy[x]);
            lazy[2*x+2] = mult(lazy[2*x+2], lazy[x]);
        }
        lazy[x] = 1;
    }
    void make(int l, int r, int v, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            lazy[x] = mult(lazy[x], v);
            push(x, lx, rx);
            return;
        }
        int mid = (lx + rx) / 2;
        make(l, r, v, 2*x+1, lx, mid);
        make(l, r, v, 2*x+2, mid, rx);
        tree[x] = add(tree[2*x+1], tree[2*x+2]);
    }
    void make(int l, int r, int v) { make(l, r, v, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return tree[x];
        int mid = (lx + rx) / 2;
        return add(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    int n, m;
    cin >> n >> m;
    SegTree segtree(n);
    while (m--) {
        int op, l, r; cin >> op >> l >> r;
        if (op == 1) {
            int v;
            cin >> v;
            segtree.make(l, r, v);
        } else {
            cout << segtree.get(l, r) << '\n';
        }
    }
}
