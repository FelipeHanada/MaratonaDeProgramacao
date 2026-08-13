#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int size;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2*size, INT32_MIN);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2*x+1, lx, mid);
        else set(i, v, 2*x+2, mid, rx);
        tree[x] = max(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return INT32_MIN;
        int mid = (lx + rx) / 2;
        return max(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
};

vector<vector<int>> adj;
vector<int> parent, depth, heavy;
int dfs(int i) {
    int size = 1;
    pair<int, int> h = { -1, -1 };
    for (int j : adj[i]) if (j != parent[i]) {
        parent[j] = i;
        depth[j] = depth[i] + 1;

        int c_size = dfs(j);
        size += c_size;
        h = max(h, { c_size, j });
    }
    heavy[i] = h.second;
    return size;
}

int curr_pos;
vector<int> head, pos;
void decompose(int i, int h) {
    head[i] = h; pos[i] = curr_pos++;
    if (heavy[i] != -1) decompose(heavy[i], h);
    for (int j : adj[i]) if (j != parent[i] && j != heavy[i]) {
        decompose(j, j);
    }
}
int query(SegTree &st, int u, int v) {
    int ans = INT32_MIN;
    for (; head[u] != head[v]; v = parent[head[v]]) {
        if (depth[head[u]] > depth[head[v]]) swap(u, v);
        ans = max(ans, st.get(pos[head[v]], pos[v]+1));
    }

    if (depth[u] > depth[v]) swap(u, v);
    ans = max(ans, st.get(pos[u], pos[v]+1));
    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    adj.resize(n);
    for (int i=0; i<n-1; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    parent.resize(n); parent[0] = -1;
    depth.resize(n); depth[0] = 0;
    heavy.assign(n, -1);
    dfs(0);
    curr_pos = 0;
    head.resize(n);
    pos.resize(n);
    decompose(0, 0);

    SegTree st(curr_pos);
    for (int i=0; i<n; i++) st.set(pos[i], a[i]);

    vector<int> ans;
    while (q--) {
        int op, x, y; cin >> op >> x >> y;

        if (op == 1) {
            x--;
            st.set(pos[x], y);
        } else {
            x--; y--;
            ans.push_back(query(st, x, y));
        }
    }

    for (int x : ans) cout << x << ' ';
    cout << '\n';
}
