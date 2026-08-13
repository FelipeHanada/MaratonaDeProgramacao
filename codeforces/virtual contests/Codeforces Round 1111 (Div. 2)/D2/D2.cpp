#include <bits/stdc++.h>
using namespace std;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);


struct SegTree {
    int size;
    vector<int> small, big, tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        small.assign(size*2, INT32_MAX);
        big.assign(size*2, INT32_MAX);
        tree.assign(size*2, 0);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            small[x] = big[x] = v;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2*x+1, lx, mid);
        else set(i, v, 2*x+2, mid, rx);

        small[x] = min(small[2*x+1], small[2*x+2]);
        big[x] = max(big[2*x+1], big[2*x+2]);
        tree[x] = max(tree[2*x+1], tree[2*x+2]);
        if (big[2*x+1] > small[2*x+2]) tree[x] = rx - lx;
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
};

int main() { _
    int tt; cin >> tt;
    while (tt--) {
        int n, q; cin >> n >> q;
        SegTree st(n);
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            st.set(i, x);
        }

        cout << st.tree[0]/2 << '\n';
        while (q--) {
            int x, y; cin >> x >> y;
            st.set(x, y);
            cout << st.tree[0]/2 << '\n';
        }
    }
}
