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

    int n;
    cin >> n;
    vector<int> left(n+1, -1);
    vector<int> ans(n+1, false);
    SegTree segtree(2*n);
    int x;
    for (int i=0; i<2*n; i++) {
        cin >> x;
        if (left[x] >= 0) {
            ans[x] = segtree.get(left[x], i);
            segtree.set(left[x], 1);
        }
        left[x] = i;
    }

    for (int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}