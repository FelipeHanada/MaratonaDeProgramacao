#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int size;
    vector<ll> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size * 2, 0);
    }
    void set(int i, ll v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2*x+1, lx, mid);
        else set(i, v, 2*x+2, mid, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void set(int i, ll v) { set(i, v, 0, 0, size); }
    ll get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx);
    }
    ll get(int l, int r) { return get(l, r, 0, 0, size); }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i=0; i<n; i++) reverse(adj[i].begin(), adj[i].end());

    vector<int> l(n), r(n);
    stack<array<int,3>> dfs; dfs.push({ 0, -1, 0 });
    int id = 0;
    while (!dfs.empty()) {
        auto [curr, p, state] = dfs.top(); dfs.pop();
        if (!state) {
            l[curr] = id++;
            dfs.push({ curr, p, 1 });
            for (int neighbor : adj[curr]) if (neighbor != p) {
                dfs.push({ neighbor, curr, 0 });
            }
        } else {
            r[curr] = id;
        }
    }

    SegTree segtree(id+5);
    for (int i=0; i<n; i++) segtree.set(l[i], a[i]);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int s, x; cin >> s >> x; s--;
            segtree.set(l[s], x);
        } else {
            int s; cin >> s; s--;
            cout << segtree.get(l[s], r[s]) << '\n';
        }
    }
}
