#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct SegTreeMax {
    int size;
    vector<ll> tree;
    vector<ll> lazy;
    SegTreeMax(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(size<<1, 0);
        lazy.assign(size<<1, 0);
    }
    void push(int x, int lx, int rx) {
        tree[x] += lazy[x];
        if (rx - lx > 1) {
            lazy[2*x+1] += lazy[x];
            lazy[2*x+2] += lazy[x];
        }
        lazy[x] = 0;
    }
    void add(int l, int r, ll v, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            lazy[x] += v;
            push(x, lx, rx);
            return;
        }
        int mid = (lx + rx) / 2;
        add(l, r, v, 2*x+1, lx, mid);
        add(l, r, v, 2*x+2, mid, rx);
        tree[x] = max(tree[2*x+1], tree[2*x+2]);
    }
    void add(int l, int r, ll v) { add(l, r, v, 0, 0, size); }
    ll get_max(int l, int r, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return INT64_MIN;
        int mid = (lx + rx) / 2;
        return max(get_max(l, r, 2*x+1, lx, mid), get_max(l, r, 2*x+2, mid, rx));
    }
    ll get_max(int l, int r) { return get_max(l, r, 0, 0, size); }
};

struct SegTreeSum {
    int size;
    vector<ll> tree;
    SegTreeSum(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(size<<1, 0);
    }
    void add(int i, ll v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] += v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) add(i, v, 2*x+1, lx, mid);
        else add(i, v, 2*x+2, mid, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void add(int i, ll v) { add(i, v, 0, 0, size); }
    ll get_sum(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return get_sum(l, r, 2*x+1, lx, mid) + get_sum(l, r, 2*x+2, mid, rx);
    }
    ll get_sum(int l, int r) { return get_sum(l, r, 0, 0, size); }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    SegTreeMax st_max(n);
    SegTreeSum st_sum(n);
    for (int i=0; i<n; i++) {
        st_max.add(i, n, a[i]);
        st_sum.add(i, a[i]);
    }

    while (q--) {
        int op; cin >> op;

        if (op == 1) {
            int k; ll u; cin >> k >> u; k--;
            st_max.add(k, n, u - a[k]);
            st_sum.add(k, u - a[k]);
            a[k] = u;
        } else {
            int l, r; cin >> l >> r; l--;
            cout << max(0LL, st_max.get_max(l, r) - st_sum.get_sum(0, l)) << '\n';
        }
    }
}

/*
8 4
1 2 -1 3 1 -5 1 4
2 2 6
1 4 -2
2 2 6
2 3 4

1 2 -1 3 1 -5 1 4

*/