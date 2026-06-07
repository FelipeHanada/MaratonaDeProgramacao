#include <bits/stdc++.h>
using namespace std;


struct SegTree {
    int size;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, 0);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = ((lx % 2) ? -1 : 1) * v;
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
    void set(int i, int v) { set(i, v, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx);
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    int x;
    SegTree segtree(n);
    for (int i=0; i<n; i++) {
        cin >> x;
        segtree.set(i, x);
    }

    int i, j, l, r;
    cin >> m;
    while (m--) {
        cin >> x;
        if (x == 0) {
            cin >> i >> j;
            segtree.set(i-1, j);
        } else {
            cin >> l >> r;
            cout << ((l % 2) ? 1 : -1) * segtree.get(l-1, r) << '\n';
        }
    }
}
