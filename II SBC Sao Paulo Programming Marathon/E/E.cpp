#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct SegTree {
    int size;
    vector<ll> sum, curr;
    vector<bool> lazy;
    SegTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        sum.assign(size*2, 0);
        curr.assign(size*2, 0);
        lazy.assign(size*2, 0);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sum[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2*x+1, lx, mid);
        else set(i, v, 2*x+2, mid, rx);
        sum[x] = sum[2*x+1] + sum[2*x+2];
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    void push(int x, int lx, int rx) {
        if (!lazy[x]) return;
        lazy[x] = 0;
        curr[x] = sum[x] - curr[x];
        if (rx - lx > 1) {
            lazy[2*x+1] = !lazy[2*x+1];
            lazy[2*x+2] = !lazy[2*x+2];
        }
    }
    void flip(int l, int r, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= l && rx <= r) {
            lazy[x] = 1;
            push(x, lx, rx);
            return;
        }
        if (lx >= r || rx <= l) return;
        int mid = (lx + rx) / 2;
        flip(l, r, 2*x+1, lx, mid);
        flip(l, r, 2*x+2, mid, rx);
        curr[x] = curr[2*x+1] + curr[2*x+2];
    }
    void flip(int l, int r) { flip(l, r, 0, 0, size); }
    ll get(int l, int r, int x, int lx, int rx) {
        push(x, lx, rx);
        if (lx >= l && rx <= r) return curr[x];
        if (lx >= r || rx <= l) return 0;
        int mid = (lx + rx) / 2;
        return get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx);
    }
    ll get(int l, int r) { return get(l, r, 0, 0, size); }
};

vector<vector<pair<int, int>>> adj;
vector<int> parent, depth, heavy, head, pos;
int dfs(int i) {
    int size = 1;
    pair<int, int> h = { -1, -1 };
    for (auto [ j, _ ] : adj[i]) if (j != parent[i]) {
        parent[j] = i;
        depth[j] = depth[i] + 1;
        int size_j = dfs(j);
        h = max(h, { size_j, j });
        size += size_j;
    }
    heavy[i] = h.second;
    return size;
}
int curr_pos;
void decompose(int i, int h) {
    // h is the current head
    head[i] = h; pos[i] = curr_pos++;
    
    if (heavy[i] != -1) decompose(heavy[i], h);
    for (auto [ j, _ ] : adj[i]) {
        if (j != parent[i] && j != heavy[i]) {
            decompose(j, j);
        }
    }
}

void query(SegTree &st, int i, int j) {
    // must flip entire path from i to j
    for (; head[i] != head[j]; j = parent[head[j]]) {
        if (depth[head[i]] > depth[head[j]]) swap(i, j);
        st.flip(pos[head[j]], pos[j] + 1);
    }

    if (depth[i] > depth[j]) swap(i, j);
    st.flip(pos[i] + 1, pos[j] + 1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    adj.resize(n);
    for (int i=1; i<n; i++) {
        int x, y, w; cin >> x >> y >> w; x--; y--;
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }

    parent.resize(n); parent[0] = -1;
    depth.resize(n); depth[0] = 0;
    heavy.assign(n, -1);
    dfs(0);

    head.resize(n);
    pos.resize(n);
    curr_pos = 0;
    decompose(0, 0);

    SegTree st(curr_pos);
    for (int i=0; i<n; i++) {
        for (auto [ j, w ] : adj[i]) if (depth[i] > depth[j]) {
            st.set(pos[i], w);
        }
    }

    while (q--) {
        int x, y; cin >> x >> y; x--; y--;
        query(st, x, y);
        cout << st.curr[0] << '\n';
    }
}
