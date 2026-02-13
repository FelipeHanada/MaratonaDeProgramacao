#include <bits/stdc++.h>
using namespace std;


#define ll long long

struct SegTree {
    int size;
    vector<ll> seg;
    vector<ll> prefix;
    vector<ll> suffix;
    vector<ll> sums;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        seg.assign(2*size, 0);
        prefix.assign(2*size, 0);
        suffix.assign(2*size, 0);
        sums.assign(2*size, 0);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] = prefix[x] = suffix[x] = max(0, v);
            sums[x] = v;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2*x+1, lx, mid);
        } else {
            set(i, v, 2*x+2, mid, rx);
        }
        // updates
        seg[x] = max(max(seg[2*x+1], seg[2*x+2]), suffix[2*x+1] + prefix[2*x+2]);
        prefix[x] = max(prefix[2*x+1], sums[2*x+1] + prefix[2*x+2]);
        suffix[x] = max(suffix[2*x+2], sums[2*x+2] + suffix[2*x+1]);
        sums[x] = sums[2*x+1] + sums[2*x+2];
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    SegTree segtree(n);
    int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        segtree.set(i, x);
    }

    cout << segtree.seg[0] << '\n';
    int i, v;
    while (m--) {
        cin >> i >> v;
        segtree.set(i, v);
        cout << segtree.seg[0] << '\n';
    }
}
