#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 2e5;
vector<int> adj[MAX_N];

int a; int max_depth;
void dfs(int v, int p, int depth) {
    for (int x : adj[v]) {
        if (x == p) continue;
        dfs(x, v, depth + 1);
    }

    if (depth > max_depth) {
        max_depth = depth;
        a = v;
    }
}

int main() {
    int n; cin >> n;

    for (int i=0; i<n-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1, 0);
    dfs(a, -1, 0);
    cout << max_depth << endl;
}