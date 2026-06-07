#include <bits/stdc++.h>
using namespace std;


struct SegTree {
    int size;
    vector<int> tree;
    vector<int> lazy;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, 0);
        lazy.assign(size*2, false);
        lazy[0] = true;
    }
    void push(int x) {
        if (!lazy[x]) return;
        tree[2*x+1] = tree[2*x+2] = tree[x];
        lazy[2*x+1] = lazy[2*x+2] = true;
        lazy[x] = false;
    }
    void set(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            tree[x] = v;
            lazy[x] = true;
            return;
        }
        push(x);
        int mid = (lx + rx) / 2;
        set(l, r, v, 2*x+1, lx, mid);
        set(l, r, v, 2*x+2, mid, rx);
    }
    void set(int l, int r, int v) { set(l, r, v, 0, 0, size); }
    int get(int i, int x, int lx, int rx) {
        if (rx - lx == 1) return tree[x];
        push(x);
        int mid = (lx + rx) / 2;
        if (i < mid) return get(i, 2*x+1, lx, mid);
        else return get(i, 2*x+2, mid, rx);
    }
    int get(int i) { return get(i, 0, 0, size); }
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
            segtree.set(l, r, v);
        } else {
            cin >> i;
            cout << segtree.get(i) << '\n';
        }
    }
}
