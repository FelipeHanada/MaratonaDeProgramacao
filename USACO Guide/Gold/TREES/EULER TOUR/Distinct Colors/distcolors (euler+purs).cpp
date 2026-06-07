#include <bits/stdc++.h>
using namespace std;


int n;
vector<vector<int>> adj;
vector<int> c, euler, el, er;
void dfs_euler(int i, int p) {
    el[i] = euler.size();
    euler.push_back(i);
    for (int neighbor : adj[i]) if (neighbor != p) {
        dfs_euler(neighbor, i);
    }
    euler.push_back(i);
    er[i] = euler.size();
}
struct SegTree {
    int size;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size * 2, 0);
    }
    void add(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] += v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) add(i, v, 2*x+1, lx, mid);
        else add(i, v, 2*x+2, mid, rx); 
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void add(int i, int v) { add(i, v, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx);
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
};
int main() {
    cin >> n;
    adj.resize(n); c.resize(n);
    for (int i=0; i<n; i++) cin >> c[i];
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    {
        set<int> s;
        for (int i=0; i<n; i++) s.insert(c[i]);
        map<int, int> comp;
        int id = 0;
        for (int x : s) comp[x] = id++;
        for (int i=0; i<n; i++) c[i] = comp[c[i]];
    }

    el.resize(n); er.resize(n);
    dfs_euler(0, -1);

    vector<bool> seen(n, 0);
    vector<int> last(n, -1), ans(n);
    SegTree segtree(euler.size());
    for (int i=0; i<euler.size(); i++) {
        int v = euler[i];
        if (!seen[v]) {
            seen[v] = 1;
            if (last[c[v]] != -1) segtree.add(last[c[v]], -1);
            last[c[v]] = i;
            segtree.add(last[c[v]], 1);
        } else {
            ans[v] = segtree.get(el[v], er[v]);
        }
    }

    for (int x : ans) cout << x << ' ';
    cout << '\n';
}
