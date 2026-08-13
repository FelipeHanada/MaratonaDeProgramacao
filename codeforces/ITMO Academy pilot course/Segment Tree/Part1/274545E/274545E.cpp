#include <bits/stdc++.h>
using namespace std;


#define ll long long

struct SegTree {
    int size;
    vector<ll> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) { size *= 2; }
        tree.assign(size*2, 0);
    }
    void set(int i, ll v, int x, int lx, int rx) {
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
    void set(int i, ll v) { set(i, v, 0, 0, size); }
    ll get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx);
    }
    ll get(int l, int r) { return get(l, r, 0, 0, size); }
    ll get_e(int i) { return tree[size + i - 1]; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    SegTree segtree(n + 1);
    int x, l, r, v, i;
    while (m--) {
        cin >> x;
        if (x == 1) {
            cin >> l >> r >> v;
            segtree.set(l, segtree.get_e(l) + v);
            segtree.set(r, segtree.get_e(r) - v);
        } else {
            cin >> i;
            cout << segtree.get(0, i + 1) << '\n';
        }
    }
}
