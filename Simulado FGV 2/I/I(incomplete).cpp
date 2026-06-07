#include <bits/stdc++.h>
using namespace std;


struct SegTree {
    int X;
    int size;
    vector<int> tree;
    vector<pair<int, int>> prefix, suffix;
    vector<int> ans;
    SegTree(int n, int x) {
        X = x;
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, -1);
        prefix.resize(size*2, { 0, -1 });
        suffix.resize(size*2, { 0, -1 });
        ans.assign(size*2, 0);
    }
    int gcd(int a, int b) {
        if (a == -1) return b;
        if (b == -1) return a;
        return __gcd(a, b);
    }
    void merge(int x, int lx, int rx) {
        ans[x] = ans[2*x+1] + ans[2*x+2];
        if (gcd(suffix[2*x+1].second, prefix[2*x+2].second) == X) {
            ans[x] += suffix[2*x+1].first * prefix[2*x+2].first;
        }

        if (!(tree[2*x+1] % X))
            prefix[x] = {(rx - lx) / 2 + prefix[2*x+2].first, gcd(tree[2*x+1], prefix[2*x+2].second)};
        else prefix[x] = prefix[2*x+1];

        if (!(tree[2*x+2] % X))
            suffix[x] = {suffix[2*x+1].first + (rx - lx) / 2, gcd(suffix[2*x+1].second, tree[2*x+2])};
        else suffix[x] = suffix[2*x+2];

        tree[x] = gcd(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            if (!(v % x)) {
                prefix[x] = suffix[x] = { 1, v };
            }
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2*x+1, lx, mid);
        else set(i, v, 2*x+2, mid, rx);
        merge(x, lx, rx);
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return -1;
        int mid = (lx + rx) / 2;
        return gcd(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
    auto get_ans(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return make_tuple(ans[x], lx, rx, prefix[x], suffix[x]);
        if (lx >= r || rx <= l) return make_tuple(0, 0, 0, make_pair(0, -1), make_pair(0, -1));

        int mid = (lx + rx) / 2;
        auto [ ansl, lxl, rxl, prefixl, suffixl ] = get_ans(l, r, 2*x+1, lx, mid);
        auto [ ansr, lxr, rxr, prefixr, suffixr ] = get_ans(l, r, 2*x+2, mid, rx);

        pair<int, int> pre, suf;
        int a = ansl + ansr;
        if (gcd(suffixl.second, prefixr.second) == X) a += 

        return ;
    }
    auto get_ans(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    int n, q, x;
    cin >> n >> q >> x;
    SegTree segtree(n, x);
    for (int i=0; i<n; i++) {
        int ai;
        cin >> ai;
        segtree.set(i, ai);
    }

    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            segtree.set(a-1, b);
        } else {
            cout << segtree.ans[0] << '\n';
        }
    }
}