#include <bits/stdc++.h>
using namespace std;


using ll = long long;

struct SegTree {
    int size;
    vector<bool> is_lazy;
    vector<int> lazy;
    vector<ll> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        is_lazy.assign(size*2, 0);
        lazy.resize(size*2);
        tree.assign(size*2, 0);
    }
    void push(int x, int lx, int rx) {
        if (!is_lazy[x]) return;
        tree[x] = ll(rx - lx) * lazy[x];
        if (rx - lx > 1) {
            lazy[2*x+1] = lazy[2*x+2] = lazy[x];
            is_lazy[2*x+1] = is_lazy[2*x+2] = 1;
        }
        is_lazy[x] = 0;
    }
    void set(int l, int r, int v, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            lazy[x] = v;
            is_lazy[x] = 1;
            push(x, lx, rx);
            return;
        }
        int mid = (lx + rx) / 2;
        set(l, r, v, 2*x+1, lx, mid);
        set(l, r, v, 2*x+2, mid, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void set(int l, int r, int v) { set(l, r, v, 0, 0, size); }
    ll get(int l, int r, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return tree[x];
        int mid = (lx + rx) / 2;
        return get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx);
    }
    ll get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    int n, m;
    cin >> n >> m;
    SegTree segtree(n);
    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            int v;
            cin >> v;
            segtree.set(l, r, v);
        } else {
            cout << segtree.get(l, r) << '\n';
        }
    }
}
