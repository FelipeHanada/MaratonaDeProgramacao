#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int n, m;
int add(int a, int b) {
    a += b;
    if (a >= m) a -= m;
    return a;
}
int mult(int a, int b) { return ((ll)a * b) % m; }


struct SegTree {
    int size;
    vector<int> tree;
    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size*2, 1);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2*x+1, lx, mid);
        else set(i, v, 2*x+2, mid, rx);
        tree[x] = mult(tree[2*x+1], tree[2*x+2]);
    }
    void set(int i, int v) { set(i, v, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= l && rx <= r) return tree[x];
        if (lx >= r || rx <= l) return 1;
        int mid = (lx + rx) / 2;
        return mult(get(l, r, 2*x+1, lx, mid), get(l, r, 2*x+2, mid, rx));
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
    int get(int i) { return get(i, i+1); }
};

vector<vector<int>> adj;
vector<SegTree> dp;
vector<int> ans;
void dfs_setup(int curr, int p) {
    for (int neighbor : adj[curr]) if (neighbor != p) {
        dfs_setup(neighbor, curr);
        dp[curr].set(neighbor, add(dp[neighbor].tree[0], 1));
    }
}
void dfs(int curr, int p) {
    ans[curr] = dp[curr].tree[0];

    for (int neighbor : adj[curr]) if (neighbor != p) {
        // set neighbor to be the new root
        int prev_neighbor = dp[curr].get(neighbor);

        dp[curr].set(neighbor, 1);
        dp[neighbor].set(curr, add(1, dp[curr].tree[0]));

        dfs(neighbor, curr);

        // unset neighbor
        dp[curr].set(neighbor, prev_neighbor);
        dp[neighbor].set(curr, 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n, vector<int>());
    for (int i=0; i<n-1; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dp.assign(n, SegTree(n));
    dfs_setup(0, -1);

    ans.resize(n);
    dfs(0, -1);

    for (int i=0; i<n; i++) cout << ans[i] << '\n';
}


/*
  o
 /
o
*/