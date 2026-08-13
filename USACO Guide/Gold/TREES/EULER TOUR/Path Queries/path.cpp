#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int size;
    vector<ll> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(size * 2, 0);
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
    ll get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx);        
    }
    ll get(int l, int r) { return get(l, r, 0, 0, size); }
};
int n, q;
vector<int> a;
vector<vector<int>> adj;
vector<int> euler, el, er;
void get_euler(int i, int p) {
    el[i] = euler.size();
    euler.push_back(i);
    for (int neighbor : adj[i]) if (neighbor != p) {
        get_euler(neighbor, i);
    }
    er[i] = euler.size();
    euler.push_back(i);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> q;
    a.resize(n);
    for (int i=0; i<n; i++) cin >> a[i];
    adj.resize(n);
    for (int i=1; i<n; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    el.resize(n), er.resize(n);
    get_euler(0, -1);

    SegTree segtree(euler.size());
    for (int i=0; i<n; i++) {
        segtree.set(el[i], a[i]);
        segtree.set(er[i], -a[i]);
    }

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int s, x; cin >> s >> x; s--;
            segtree.set(el[s], x);
            segtree.set(er[s], -x);
        } else {
            int s; cin >> s; s--;
            cout << segtree.get(0, er[s]) << '\n';
        }
    }
}