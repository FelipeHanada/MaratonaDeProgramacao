#include <bits/stdc++.h>
using namespace std;


struct SegTree {
    int size;
    vector<bool> lazy;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        lazy.assign(size*2, 0);
        tree.assign(size*2, 0);
    }
    void push(int x, int lx, int rx) {
        if (!lazy[x]) return;
        tree[x] = (rx - lx) - tree[x];
        if (rx - lx > 1) {
            lazy[2*x+1] = !lazy[2*x+1];
            lazy[2*x+2] = !lazy[2*x+2];
        }
        lazy[x] = 0;
    }
    void flip(int l, int r, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            lazy[x] = 1;
            push(x, lx, rx);
            return;
        }
        int mid = (lx + rx) / 2;
        flip(l, r, 2*x+1, lx, mid);
        flip(l, r, 2*x+2, mid, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void flip(int l, int r) { flip(l, r, 0, 0, size); }
    int get(int i, int x, int lx, int rx) {
        push(x, lx, rx);
        if (rx - lx == 1) return lx;
        int mid = (lx + rx) / 2;
        push(2*x+1, lx, mid);
        if (tree[2*x+1] > i) return get(i, 2*x+1, lx, mid);
        else return get(i - tree[2*x+1], 2*x+2, mid, rx);
    }
    int get(int i) { return get(i, 0, 0, size); }
};

// 0 1 1 0 0
// 1 0 1 0 0

int main() {
    int n, m;
    cin >> n >> m;
    SegTree segtree(n);
    while (m--) {
        int op, k, l, r;
        cin >> op;
        if (op == 1) {
            cin >> l >> r;
            segtree.flip(l, r);
        } else {
            cin >> k;
            cout << segtree.get(k) << '\n';
        }
    }
}