#include <bits/stdc++.h>
using namespace std;


int main() {
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

    queue<int> bfs;
    
    vector<int> dist(n, 0);
    vector<bool> seen(n, 0);
    bool ok = 1;
    for (int i=0; ok && i<n; i++) {
        if (seen[i]) continue;
        bfs.push(i); seen[i] = 1;
        
        while (ok && !bfs.empty()) {
            auto curr = bfs.front(); bfs.pop();
    
            for (int neighbor : adj[curr]) {
                if (seen[neighbor]) {
                    if (dist[curr]%2 == dist[neighbor]%2) {
                        ok = 0;
                        break;
                    }
                } else {
                    seen[neighbor] = 1;
                    dist[neighbor] = dist[curr] + 1;
                    bfs.push(neighbor);
                }
            }
        }
    }

    if (!ok) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i=0; i<n; i++) {
            cout << dist[i]%2 + 1 << ' ';
        }
        cout << '\n';
    }
}