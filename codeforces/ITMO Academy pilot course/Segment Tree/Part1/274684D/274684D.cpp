#include <bits/stdc++.h>
using namespace std;


struct SegTree { // for OR
    int size;
    vector<bool> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, false);
    }
    void set(int i, bool v, int x, int lx, int rx) {
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
        tree[x] = tree[2*x+1] || tree[2*x+2];
    }
    void set(int i, bool v) { set(i, v, 0, 0, size); }
    bool get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return false;
        int mid = (lx + rx) / 2;
        return get(l, r, 2*x+1, lx, mid) || get(l, r, 2*x+2, mid, rx);
    }    
    bool get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<SegTree> in(40, SegTree(n));
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        v[i] = x-1;
        in[x-1].set(i, true);
    }

    int t, x, y;
    while (m--) {
        cin >> t >> x >> y;
        if (t == 1) {
            int ans = 0;
            for (int i=0; i<40; i++) {
                if (in[i].get(x-1, y)) ans++;
            }
            cout << ans << '\n';
        } else {
            in[v[x-1]].set(x-1, false);
            in[y-1].set(x-1, true);
            v[x-1] = y-1;
        }
    }
}
