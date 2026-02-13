#include <bits/stdc++.h>
using namespace std;



struct SegTree {
    int size;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size * 2, -1);
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
        tree[x] = max(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    int get(int v, int x, int lx, int rx) {
        if (tree[x] < v) return -1;
        if (rx - lx == 1) return lx;

        int mid = (lx + rx) / 2;
        if (tree[2*x+1] >= v) {
            return get(v, 2*x+1, lx, mid);
        } else {
            return get(v, 2*x+2, mid, rx);
        }
    }
    int get(int v) {
        return get(v, 0, 0, size);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int x;
    SegTree segtree(n);
    for (int i=0; i<n; i++) {
        cin >> x;
        segtree.set(i, x);
    }

    int v;
    while (m--) {
        cin >> x;
        if (x == 1) {
            cin >> x >> v;
            segtree.set(x, v);
        } else {
            cin >> x;
            cout << segtree.get(x) << '\n';
        }
    }
}