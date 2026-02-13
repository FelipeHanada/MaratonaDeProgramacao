#include <bits/stdc++.h>
using namespace std;


struct SegTree {
    int size;
    vector<int> mintree;
    vector<int> buildings;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        mintree.assign(size*2, INT32_MAX);
        buildings.assign(size*2, 0);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            mintree[x] = v;
            buildings[x] = 1;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2*x+1, lx, mid);
        else set(i, v, 2*x+2, mid, rx);
        mintree[x] = min(mintree[2*x+1], mintree[2*x+2]);
        buildings[x] = buildings[2*x+1] + buildings[2*x+2];
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    int earthquake(int l, int r, int v, int x, int lx, int rx) {
        if (!buildings[x]) return 0;
        if (lx >= r || rx <= l || mintree[x] > v) return 0;
        if (rx - lx == 1) {
            if (!buildings[x] || mintree[x] > v) {
                return 0;
            }
            mintree[x] = INT32_MAX;
            buildings[x] = 0;
            return 1;
        }
        
        int mid = (lx + rx) / 2;
        int ans = earthquake(l, r, v, 2*x+1, lx, mid) + earthquake(l, r, v, 2*x+2, mid, rx);
        mintree[x] = min(mintree[2*x+1], mintree[2*x+2]);
        buildings[x] = buildings[2*x+1] + buildings[2*x+2];
        return ans;
    }
    int earthquake(int l, int r, int v) {
        return earthquake(l, r, v, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    SegTree segtree(n);
    while (m--) {
        int op, i, h, l, r, p;
        cin >> op;
        if (op == 1) {
            cin >> i >> h;
            segtree.set(i, h);
        } else {
            cin >> l >> r >> p;
            cout << segtree.earthquake(l, r, p) << '\n';
        }
    }
}
