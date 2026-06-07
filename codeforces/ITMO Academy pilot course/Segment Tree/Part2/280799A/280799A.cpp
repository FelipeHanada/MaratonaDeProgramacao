#include <bits/stdc++.h>
using namespace std;


using ll = long long;

struct SegTree {
    int size;
    vector<int> lazy;
    vector<bool> is_lazy;
    vector<ll> sum;
    vector<ll> prefix;
    vector<ll> suffix;
    vector<ll> seg;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        lazy.resize(size*2);
        is_lazy.assign(size*2, 0);
        sum.assign(size*2, 0);
        prefix.assign(size*2, 0);
        suffix.assign(size*2, 0);
        seg.assign(size*2, 0);
    }
    void push(int x, int lx, int rx) {
        if (!is_lazy[x]) return;
        sum[x] = ll(rx - lx) * lazy[x];
        prefix[x] = suffix[x] = seg[x] = max(0LL, sum[x]);
        if (rx - lx > 1) {
            lazy[2*x+1] = lazy[2*x+2] = lazy[x];
            is_lazy[2*x+1] = is_lazy[2*x+2] = 1;
        }
        is_lazy[x] = 0;
    }
    void set(int l, int r, int v, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            lazy[x] = v;
            is_lazy[x] = 1;
            push(x, lx, rx);
            return;
        }

        int mid = (lx + rx) / 2;
        set(l, r, v, 2*x+1, lx, mid);
        set(l, r, v, 2*x+2, mid, rx);
        sum[x] = sum[2*x+1] + sum[2*x+2];
        prefix[x] = max(prefix[2*x+1], sum[2*x+1] + prefix[2*x+2]);
        suffix[x] = max(suffix[2*x+2], suffix[2*x+1] + sum[2*x+2]);
        seg[x] = max(
            max(seg[2*x+1], seg[2*x+2]),
            suffix[2*x+1] + prefix[2*x+2]
        );
    }
    void set(int l, int r, int v) { set(l, r, v, 0, 0, size); }
};

int main() {
    int n, m;
    cin >> n >> m;
    SegTree segtree(n);
    while (m--) {
        int l, r, v;
        cin >> l >> r >> v;
        segtree.set(l, r, v);
        cout << segtree.seg[0] << '\n';
    }
}