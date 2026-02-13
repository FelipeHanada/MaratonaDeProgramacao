#include <bits/stdc++.h>
using namespace std;


using ll = long long;

struct SegTree {
    int size;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, 0);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2*x+1, lx, mid);
        else set(i, v, 2*x+2, mid, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx);
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    SegTree st(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        st.set(i, a[i]);
    }

    int t, x, l, r;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> x; x--;
            swap(a[x], a[x+1]);
            st.set(x, a[x]);
            st.set(x+1, a[x+1]);
        } else {
            cin >> l >> r; l--;
            cout << st.get(l, r) << '\n';
        }
    }
}
