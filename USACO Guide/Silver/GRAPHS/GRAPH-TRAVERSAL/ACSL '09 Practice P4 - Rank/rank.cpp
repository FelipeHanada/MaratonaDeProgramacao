#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y, sx, sy;
        cin >> x >> y >> sx >> sy;
        x--; y--;
        if (sx > sy) adj[x].push_back(y);
        else adj[y].push_back(x);
    }

    vector<bool> incycle(n, 0);
    for (int i=0; i<n; i++) {
        stack<int> dfs; dfs.push(i);
        vector<bool> seen(n, 0); seen[i] = 1;

        while (!dfs.empty()) {
            auto curr = dfs.top(); dfs.pop();
            for (int neighbor : adj[curr]) {
                if (neighbor == i) incycle[curr] = 1;
                if (seen[neighbor]) continue;
                seen[neighbor] = 1;
                dfs.push(neighbor);
            }
        }
    }

    cout << count(incycle.begin(), incycle.end(), 1) << '\n';
}
