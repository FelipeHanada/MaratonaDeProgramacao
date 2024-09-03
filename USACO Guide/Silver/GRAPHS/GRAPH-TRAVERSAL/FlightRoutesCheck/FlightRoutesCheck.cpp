// exists a city with the following properties:
// 1. it can reach any other city
// 2. it can BE reacher from any other city
// then and only then, every city can reach any other city

#include <bits/stdc++.h>
using namespace std;


void dfs(const vector<set<int>> &adj, vector<bool> &seen, int start) {
    seen[start] = true;
    stack<int> dfs; dfs.emplace(start);
    while (dfs.size() > 0) {
        int curr = dfs.top(); dfs.pop();
        for (int x : adj[curr]) {
            if (!seen[x]) {
                seen[x] = true;
                dfs.emplace(x);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<set<int>> adj(n, set<int>()), inverse_adj(n, set<int>());
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        inverse_adj[b].insert(a);
    }

    vector<bool> seen(n, false);
    dfs(adj, seen, 0);
    for (int i=0; i<n; i++) {
        if (!seen[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i + 1 << endl;
            return 0;
        }
    }

    seen.assign(n, false);
    dfs(inverse_adj, seen, 0);
    for (int i=0; i<n; i++) {
        if (!seen[i]) {
            cout << "NO" << endl;
            cout << i + 1 << " " << 1 << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}
