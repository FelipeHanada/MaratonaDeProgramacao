#include <bits/stdc++.h>
using namespace std;


#define ll long long

struct SegTree {
    int size;
    vector<int> leafs;
    vector<vector<int>> count;
    vector<ll> inv;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        leafs.assign(size, 0);
        count.assign(size * 2, vector<int>(41, 0));
        inv.assign(size * 2, 0);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            count[x][leafs[i]] = 0;
            count[x][v] = 1;
            leafs[i] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2*x+1, lx, mid);
        } else {
            set(i, v, 2*x+2, mid, rx);
        }
        for (int i=0; i<=40; i++) {
            count[x][i] = count[2*x+1][i] + count[2*x+2][i];
        }
        inv[x] = inv[2*x+1] + inv[2*x+2];
        for (int j=0; j<=40; j++) {
            for (int i=j+1; i<=40; i++) {
                inv[x] += count[2*x+1][i] * count[2*x+2][j];
            }
        }
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    void get_count(int l, int r, int x, int lx, int rx, vector<int>& out) {
        if (lx >= l && rx <= r) {
            for (int i=0; i<=40; i++) {
                out[i] += count[x][i];
            }
            return;
        }
        if (lx >= r || rx <= l) return;
        int mid = (lx + rx) / 2;
        get_count(l, r, 2*x+1, lx, mid, out);
        get_count(l, r, 2*x+2, mid, rx, out);
    }
    ll get_inv(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return inv[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        ll ans = get_inv(l, r, 2*x+1, lx, mid) + get_inv(l, r, 2*x+2, mid, rx);
        // + todas as inversões que ocorrem entre elementos de max(lx,l)..mid -> mid..min(rx,r)
        vector<int> a(41), b(41);
        get_count(l, r, 2*x+1, lx, mid, a);
        get_count(l, r, 2*x+2, mid, rx, b);
        for (int j=0; j<=40; j++) {
            for (int i=j+1; i<=40; i++) {
                ans += a[i] * b[j];
            }
        }
        return ans;
    }
    ll get_inv(int l, int r) { return get_inv(l, r, 0, 0, size); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    int v;
    SegTree segtree(n);
    for (int i=0; i<n; i++) {
        cin >> v;
        segtree.set(i, v);
    }

    int t, x, y;
    while (q--) {
        cin >> t >> x >> y;
        if (t == 1) {
            cout << segtree.get_inv(x-1, y) << '\n';
        } else {
            segtree.set(x-1, y);
        }
    }
}
