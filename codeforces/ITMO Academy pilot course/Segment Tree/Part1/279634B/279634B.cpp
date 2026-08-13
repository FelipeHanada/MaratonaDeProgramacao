#include <bits/stdc++.h>
using namespace std;

/*
MAX is both associative and commutative

max(a, max(b, c)) = max(max(a, b), c) (associative property)
max(a, b) = max(b, a) (commutative property)

just use range update + point query
*/


struct SegTree {
    int size;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size * 2, 0);
    }
    void apply(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= l && rx <= r) {
            tree[x] = max(tree[x], v);
            return;
        }
        if (lx >= r || rx <= l) return;
        int mid = (lx + rx) / 2;
        apply(l, r, v, 2*x+1, lx, mid);
        apply(l, r, v, 2*x+2, mid, rx);
    }
    void apply(int l, int r, int v) { apply(l, r, v, 0, 0, size); }
    int get(int i, int x, int lx, int rx) {
        if (rx - lx == 1) return tree[x];
        int mid = (lx + rx) / 2;
        if (i < mid) {
            return max(tree[x], get(i, 2*x+1, lx, mid));
        } else {
            return max(tree[x], get(i, 2*x+2, mid, rx));
        }
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
            segtree.apply(l, r, v);
        } else {
            cin >> i;
            cout << segtree.get(i) << '\n';
        }
    }
}
