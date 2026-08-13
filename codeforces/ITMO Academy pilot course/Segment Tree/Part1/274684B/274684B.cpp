#include <bits/stdc++.h>
using namespace std;


int r, n, m;
struct M22 {
    int a, b, c, d;
};

M22 mult(M22 a, M22 b) {
    return {
        ((a.a * b.a) % r + (a.b * b.c) % r) % r,
        ((a.a * b.b) % r + (a.b * b.d) % r) % r,
        ((a.c * b.a) % r + (a.d * b.c) % r) % r,
        ((a.c * b.b) % r + (a.d * b.d) % r) % r
    };
}

struct SegTree {
    int size;
    vector<M22> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, {1, 0, 0, 1});
    }
    void set(int i, M22 v, int x, int lx, int rx) {
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
        tree[x] = mult(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, M22 v) { set(i, v, 0, 0, size); }
    M22 get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return { 1, 0, 0, 1 };
        int mid = (lx + rx) / 2;
        return mult(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    M22 get(int l, int r) { return get(l, r, 0, 0, size); }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> n >> m;

    SegTree segtree(n);
    M22 x;
    for (int i=0; i<n; i++) {
        cin >> x.a >> x.b >> x.c >> x.d;
        segtree.set(i, x);
    }

    M22 ans;
    int left, right;
    while (m--) {
        cin >> left >> right;
        ans = segtree.get(left-1, right);

        cout << ans.a << ' ' << ans.b << '\n' << ans.c << ' ' << ans.d << "\n\n";
    }
}
