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


struct SegTreeNode {
    int l, r;
    int left, right;
    int val;
    SegTreeNode(int l, int r) : l(l), r(r), left(-1), right(-1), val(1) {}
};
struct SegTree {
    vector<SegTreeNode> tree;
    SegTree(int l, int r) {
        tree.push_back(SegTreeNode(l, r));
    }
    void expand(int curr) {
        if (tree[curr].left != -1) return;
        if (tree[curr].r - tree[curr].l <= 1) return;
        int mid = (tree[curr].l + tree[curr].r) / 2;
        tree[curr].left = tree.size();
        tree.push_back(SegTreeNode(tree[curr].l, mid));
        tree[curr].right = tree.size();
        tree.push_back(SegTreeNode(mid, tree[curr].r));
    }
    void set(int curr, int i, int v) {
        if (tree[curr].r - tree[curr].l == 1) {
            tree[curr].val = v;
            return;
        }
        expand(curr);
        int mid = (tree[curr].l + tree[curr].r) / 2;
        if (i < mid) set(tree[curr].left, i, v);
        else set(tree[curr].right, i, v);
        tree[curr].val = mult(tree[tree[curr].left].val, tree[tree[curr].right].val);
    }
    void set(int i, int v) { set(0, i, v); }
    int get(int curr, int ll, int rr) {
        if (tree[curr].l >= ll && tree[curr].r <= rr) return tree[curr].val;
        if (tree[curr].l >= rr || tree[curr].r <= ll) return 1;
        expand(curr);
        return mult(get(tree[curr].left, ll, rr), get(tree[curr].right, ll, rr));
    }
    int get(int ll, int rr) { return get(0, ll, rr); }
    int get(int i) { return get(i, i+1); }
    int get() { return tree[0].val; }
};

vector<vector<int>> adj;
vector<SegTree> dp;
vector<int> ans;
void dfs_setup(int curr, int p) {
    for (int neighbor : adj[curr]) if (neighbor != p) {
        dfs_setup(neighbor, curr);
        dp[curr].set(neighbor, add(dp[neighbor].get(), 1));
    }
}
void dfs(int curr, int p) {
    ans[curr] = dp[curr].get();

    for (int neighbor : adj[curr]) if (neighbor != p) {
        // set neighbor to be the new root
        int prev_neighbor = dp[curr].get(neighbor);

        dp[curr].set(neighbor, 1);
        dp[neighbor].set(curr, add(1, dp[curr].get()));

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

    dp.assign(n, SegTree(0, n+5));
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