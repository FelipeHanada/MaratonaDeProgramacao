#include <bits/stdc++.h>
using namespace std;


using ll = long long;

struct SegTree {
    int size;
    vector<pair<ll, ll>> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size * 2, { 0, 0 });
    }
    void add(int l, int r, int a, int d, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            tree[x].first += a;
            tree[x].second += d;
            return;
        }
        int mid = (lx + rx) / 2;
        add(l, r, a, d, 2*x+1, lx, mid);
        add(l, r, a + (mid - l) * d, d, 2*x+2, mid, rx);
    }
    void add(int l, int r, int a, int d) { add(l, r, a, d, 0, 0, size); }
    ll get(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            return tree[x].first;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            return get(i, 2*x+1, lx, mid) + (tree[x].first + (i - lx) * tree[x].second);
        } else {
            return get(i, 2*x+2, mid, rx) + (tree[x].first + (i - lx) * tree[x].second);
        }
    }
    ll get(int i) { return get(i, 0, 0, size); }

};

int main() {
    int n, m;
    cin >> n >> m;
    SegTree segtree(n);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, a, d;
            cin >> l >> r >> a >> d;
            segtree.add(l, r, a, d);
        } else {
            int i;
            cin >> i;
            cout << segtree.get(i-1) << '\n';
        }
    }
}