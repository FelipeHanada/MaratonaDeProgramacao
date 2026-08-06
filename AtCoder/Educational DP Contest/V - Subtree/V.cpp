#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> adj;
vector<int> dp, ans;
int add(int a, int b) {
    a += b;
    if (a >= m) a -= m;
    return a;
}
int mult(int a, int b) { return ((ll)a * b) % m; }

void dfs_setup(int curr, int p) {
    dp[curr] = 1;
    for (int neighbor : adj[curr]) if (neighbor != p) {
        dfs_setup(neighbor, curr);
        dp[curr] = mult(dp[curr], add(dp[neighbor], 1));
    }
}

void dfs(int curr, int p, int up=1) {
    ans[curr] = mult(dp[curr], up);

    vector<int> prefix(adj[curr].size()+1), suffix(adj[curr].size()+1);
    prefix.front() = 1;
    suffix.back() = 1;
    for (int j=0; j<adj[curr].size(); j++) {
        int neighbor = adj[curr][j];
        if (neighbor == p) {
            prefix[j+1] = suffix[j] = 1;
        } else {
            prefix[j+1] = suffix[j] = add(dp[adj[curr][j]], 1);
        }
    }
    for (int j=0; j<adj[curr].size(); j++) {
        prefix[j+1] = mult(prefix[j+1], prefix[j]);
        suffix[adj[curr].size()-j-1] = mult(suffix[adj[curr].size()-j], suffix[adj[curr].size()-j-1]);
    }

    for (int j=0; j<adj[curr].size(); j++) {
        int neighbor = adj[curr][j];
        if (neighbor == p) continue;
        dfs(neighbor, curr, add(mult(up, mult(prefix[j], suffix[j+1])), 1));
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n);
    for (int i=0; i<n-1; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dp.resize(n);
    ans.resize(n);

    dfs_setup(0, -1);
    dfs(0, -1);

    for (int x : ans) cout << x << '\n';
}


/*
    o
   / \
  o  o


  o  dp = 3
  |
  o  dp = 2
  |
  o  dp = 1


dp[v] = prod (1 + dp[u]) para todo filho de u
*/