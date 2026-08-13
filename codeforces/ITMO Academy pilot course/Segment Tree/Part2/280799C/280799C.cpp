#include <bits/stdc++.h>
using namespace std;


struct SegTree {
    int size;
    vector<int> lazy;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        lazy.assign(size*2, 0);
        tree.assign(size*2, 0);
    }
    void push(int x, int lx, int rx) {
        if (!lazy[x]) return;

        tree[x] += lazy[x];
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
        tree[x] = max(tree[2*x+1], tree[2*x+2]);
    }
    void add(int l, int r, int v) { add(l, r, v, 0, 0, size); }
    int get(int v, int l, int x, int lx, int rx) {
        push(x, lx, rx);
        if (rx <= l || tree[x] < v) return INT32_MAX;
        if (rx - lx == 1) return lx;
        int mid = (lx + rx) / 2;

        push(2*x+1, lx, mid);
        if (lx >= l) return (tree[2*x+1] >= v ? get(v, l, 2*x+1, lx, mid) : get(v, l, 2*x+2, mid, rx));
        return min(get(v, l, 2*x+1, lx, mid), get(v, l, 2*x+2, mid, rx));
    }
    int get(int v, int l) { return get(v, l, 0, 0, size); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    SegTree segtree(n);
    while (m--) {
        int op, l, r, v, x;
        cin >> op;

        if (op == 1) {
            cin >> l >> r >> v;
            segtree.add(l, r, v);
        } else {
            cin >> v >> l;
            int ans = segtree.get(v, l);
            cout << (ans == INT32_MAX ? -1 : ans) << '\n';
        }
    }
}