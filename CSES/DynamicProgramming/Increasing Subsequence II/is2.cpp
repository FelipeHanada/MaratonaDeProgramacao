#include <bits/stdc++.h>
using namespace std;

constexpr int md = int(1e9) + 7;
inline int addmd(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}
struct SegTree {
    int size;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, 0);
    }
    void add(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = addmd(tree[x], v);
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) add(i, v, 2*x+1, lx, mid);
        else add(i, v, 2*x+2, mid, rx);
        tree[x] = addmd(tree[2*x+1], tree[2*x+2]);
    }
    void add(int i, int v) { add(i, v, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return addmd(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    {
        set<int> s;
        for (int i=0; i<n; i++) s.insert(a[i]);
        map<int, int> comp;
        int id = 0;
        for (int x : s) comp[x] = id++;
        for (int i=0; i<n; i++) a[i] = comp[a[i]];
    }

    SegTree segtree(n);
    for (int i=0; i<n; i++) {
        segtree.add(a[i], addmd(segtree.get(0, a[i]), 1));
    }

    cout << segtree.get(0, n+1) << '\n';
}