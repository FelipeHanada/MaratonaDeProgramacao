#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() { _
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (n != m) {
        cout << "NO\n";
        return 0;
    }

    stack<int> dfs; dfs.push(0);
    vector<bool> seen(n, 0); seen[0] = 1;
    while (!dfs.empty()) {
        auto curr = dfs.top(); dfs.pop();

        for (int neighbor : adj[curr]) {
            if (seen[neighbor]) continue;
            seen[neighbor] = 1;
            dfs.push(neighbor);
        }
    }

    if (count(seen.begin(), seen.end(), 0)) {
        cout << "NO\n";
        return 0;
    }

    cout << "FHTAGN!\n";
}
