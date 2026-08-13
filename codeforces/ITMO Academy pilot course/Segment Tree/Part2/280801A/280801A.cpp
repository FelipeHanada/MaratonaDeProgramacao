#include <bits/stdc++.h>
using namespace std;


using ll = long long;

struct SegTree {
    int size;
    vector<pair<int, ll>> lazy;
    vector<ll> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        lazy.assign(size*2, make_pair(-1, 0));
        tree.assign(size*2, 0);
    }
    void push(int x, int lx, int rx) {
        auto [op, v] = lazy[x];
        if (op == -1) return;

        if (op == 0) tree[x] = ll(rx - lx) * lazy[x].second;
        else tree[x] += ll(rx - lx) * lazy[x].second;

        if (rx - lx > 1) {
            if (op == 0) { // assign
                lazy[2*x+1] = lazy[x];
                lazy[2*x+2] = lazy[x];
            } else { // sum
                lazy[2*x+1].second += lazy[x].second;
                lazy[2*x+2].second += lazy[x].second;

                if (lazy[2*x+1].first == -1) lazy[2*x+1].first = 1;
                if (lazy[2*x+2].first == -1) lazy[2*x+2].first = 1;
            }
        }

        lazy[x] = make_pair(-1, 0);
    }
    void set(int l, int r, int v, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            lazy[x] = make_pair(0, v);
            push(x, lx, rx);
            return;
        }

        int mid = (lx + rx) / 2;
        set(l, r, v, 2*x+1, lx, mid);
        set(l, r, v, 2*x+2, mid, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void add(int l, int r, int v, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            if (lazy[x].first == -1) lazy[x].first = 1;
            lazy[x].second += v;
            push(x, lx, rx);
            return;
        }

        int mid = (lx + rx) / 2;
        add(l, r, v, 2*x+1, lx, mid);
        add(l, r, v, 2*x+2, mid, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    ll get(int l, int r, int x, int lx, int  rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return tree[x];
        int mid = (lx + rx) / 2;
        return get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx);
    }
    void set(int l, int r, int v) { set(l, r, v, 0, 0, size); }
    void add(int l, int r, int v) { add(l, r, v, 0, 0, size); }
    ll get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    SegTree segtree(n);
    while (m--) {
        int op, l, r, v;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> v;
            segtree.set(l, r, v);
        } else if (op == 2) {
            cin >> v;
            segtree.add(l, r, v);
        } else {
            cout << segtree.get(l, r) << '\n';
        }
    }
}