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
    void flip(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = 1 - tree[x];
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            flip(i, 2*x+1, lx, mid);
        } else {
            flip(i, 2*x+2, mid, rx);
        }
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void flip(int i) { flip(i, 0, 0, size); }
    int get(int i, int x, int lx, int rx) {
        if (rx - lx == 1) return x - size + 1;

        int mid = (lx + rx) / 2;
        if (i < tree[2*x+1]) return get(i, 2*x+1, lx, mid);
        else return get(i - tree[2*x+1], 2*x+2, mid, rx);
    }
    int get(int i) { return get(i, 0, 0, size); }
};

int main() {
    int n, m;
    cin >> n >> m;

    int x;
    SegTree segtree(n);
    for (int i=0; i<n; i++) {
        cin >> x;
        if (x) segtree.flip(i);
    }

    int a, b;
    while (m--) {
        cin >> a >> b;
        if (a == 1) {
            segtree.flip(b);
        } else {
            cout << segtree.get(b) << '\n';
        }
    }
}