#include <bits/stdc++.h>
using namespace std;


struct SegTree {
    int size;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2*size, 0);
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
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return INT32_MIN;
        int mid = (lx + rx) / 2;
        return max(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int big = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        big = max(big, v[i]);
    }
    SegTree segtree(big+1);
    for (int x : v) {
        segtree.set(x, segtree.get(0, x) + 1);
    }

    cout << segtree.tree[0] << '\n';
}
