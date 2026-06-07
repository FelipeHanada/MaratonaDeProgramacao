#include <bits/stdc++.h>
using namespace std;


using ll = long long;

struct SegTree {
    int size;
    vector<ll> lazy;
    vector<ll> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        lazy.assign(size*2, 0);
        tree.assign(size*2, 0);
    }
    void push(int x, int lx, int rx) {
        if (!lazy[x]) return;

        tree[x] += (rx - lx) * lazy[x];
        if (rx - lx > 1) {
            lazy[2*x+1] += lazy[x];
            lazy[2*x+2] += lazy[x];
        }
        lazy[x] = 0;
    }
    void add(int l, int r, int v, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            lazy[x] += v;
            push(x, lx, rx);
            return;
        }
        int mid = (lx + rx) / 2;
        add(l, r, v, 2*x+1, lx, mid);
        add(l, r, v, 2*x+2, mid, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void add(int l, int r, int v) { add(l, r, v, 0, 0, size); }
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
            segtree.add(l, r, v);
        } else {
            cout << segtree.get(l, r) << '\n';
        }
    }
}