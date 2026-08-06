#include <bits/stdc++.h>
using namespace std;


struct SegTree {
    int size;
    vector<int> tree, lazy;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, 0);
        lazy.assign(size*2, 0);
    }
    void push(int x, int lx, int rx) {
        if (!lazy[x]) return;
        tree[x] += lazy[x];
        if (rx - lx > 1) {
            lazy[2*x+1] += lazy[x];
            lazy[2*x+2] += lazy[x];
        }
        lazy[x] = 0;
    }
    void add(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= l && rx <= r) {
            lazy[x] += v;
            push(x, lx, rx);
            return;
        }
        if (lx >= r || rx <= l) return;

        int mid = (lx + rx) / 2;
        add(l, r, v, 2*x+1, lx, mid);
        add(l, r, v, 2*x+2, mid, rx);
    }
    void add(int l, int r, int v) { add(l, r, v, 0, 0, size); }
    int get(int i, int x, int lx, int rx) {
        push(x, lx, rx);
        if (rx - lx == 1) return tree[x];
        int mid = (lx + rx) / 2;
        if (i < mid) return get(i, 2*x+1, lx, mid);
        else return get(i, 2*x+2, mid, rx);
    }
    int get(int i) { return get(i, 0, 0, size); }
};

int n, m;
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
    head[i] = h, pos[i] = curr_pos++;
    if (heavy[i] != -1) decompose(heavy[i], h);
    for (int j : adj[i]) if (j != parent[i] && j != heavy[i]) {
        decompose(j, j);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
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

    SegTree st(n);
    for (int i=0; i<m; i++) {
        int x, y; cin >> x >> y; x--; y--;

        for (; head[x] != head[y]; y = parent[head[y]]) {
            if (depth[head[x]] > depth[head[y]]) swap(x, y);
            st.add(pos[head[y]], pos[y]+1, 1);
        }

        if (depth[x] > depth[y]) swap(x, y);
        st.add(pos[x], pos[y]+1, 1);
    }

    for (int i=0; i<n; i++)
        cout << st.get(pos[i]) << ' ';
    cout << '\n';
}
