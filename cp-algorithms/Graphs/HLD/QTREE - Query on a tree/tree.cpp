#include <bits/stdc++.h>
using namespace std;


struct SegTree {
    int size;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
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
        tree[x] = max(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) const {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return INT32_MIN;
        int mid = (lx + rx) / 2;
        return max(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    int get(int l, int r) const { return get(l, r, 0, 0, size); }
};

int n;

vector<vector<int>> adj;
vector<int> parent, depth, heavy;
int dfs(int i) {
    int size = 1;
    pair<int, int> h = { -1, -1 };
    for (int j : adj[i]) if (j != parent[i]) {
        depth[j] = depth[i] + 1;
        parent[j] = i;
        int c_size = dfs(j);
        h = max(h, { c_size, j });
        size += c_size;
    }
    heavy[i] = h.second;
    return size;
}
int curr_pos;
vector<int> head, pos;
void decompose(int i, int h) {
    pos[i] = curr_pos++;
    head[i] = h;

    if (heavy[i] != -1) decompose(heavy[i], h);
    for (int j : adj[i]) if (j != parent[i] && j != heavy[i]) {
        decompose(j, j);
    }
}

int query(const SegTree &st, int u, int v) {
    int ans = INT32_MIN;
    for (; head[u] != head[v]; v = parent[head[v]]) {
        if (depth[head[u]] > depth[head[v]]) swap(u, v);
        ans = max(ans, st.get(pos[head[v]], pos[v] + 1));
    }

    if (depth[u] > depth[v]) swap(u, v);
    ans = max(ans, st.get(pos[u] + 1, pos[v] + 1));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while (tt--) {
        cin >> n;
        vector<array<int,3>> edges(n-1);
        adj.assign(n, vector<int>());
        for (int i=0; i<n-1; i++) {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
            edges[i][0]--; edges[i][1]--;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
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
        for (auto [ u, v, w ] : edges) {
            if (parent[v] != u) swap(u, v);
            st.set(pos[v], w);
        }
    
        while (1) {
            string op; cin >> op;
            if (op == "DONE") break;
            else if (op == "CHANGE") {
                int i, ti; cin >> i >> ti; i--;
                auto [a, b, _] = edges[i];
                if (parent[b] != a) swap(a, b);
                st.set(pos[b], ti);
            } else {
                int a, b; cin >> a >> b; a--; b--;
                cout << query(st, a, b) << '\n';
            }
        }
    }
}
