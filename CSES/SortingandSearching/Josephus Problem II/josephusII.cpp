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
    int get(int i, int x, int lx, int rx) {
        // get the position of the i'th bit 1
        if (rx - lx == 1) return lx;

        int mid = (lx + rx) / 2;
        if (i < tree[2*x+1]) {
            return get(i, 2*x+1, lx, mid);
        } else {
            return get(i-tree[2*x+1], 2*x+2, mid, rx);
        }
    }
    int get(int i) {
        return get(i, 0, 0, size);
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
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void set(int i, int v) {
        return set(i, v, 0, 0, size);
    }
};


int main() {
    int n, k;
    cin >> n >> k;

    SegTree segtree(n+1);
    for (int i=0; i<n; i++) segtree.set(i, 1);

    int curr = 0;
    while (segtree.tree[0] > 0) {
        curr = (curr + k) % segtree.tree[0];
        int next = segtree.get(curr);
        cout << next + 1 << ' ';
        segtree.set(next, 0);
    }

    cout << '\n';
}