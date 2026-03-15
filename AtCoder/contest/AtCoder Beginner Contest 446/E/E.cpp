#include <bits/stdc++.h>
using namespace std;


int main() {
    int m, a, b;
    cin >> m >> a >> b;

    vector<vector<int>> adj(m*m);
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            // (i, j) -> (j, a*j + b*i)
            int curr = i*m + j;
            int next = j*m + ((a*j + b*i)%m);
            adj[next].push_back(curr);
        }
    }

    vector<bool> seen(m*m, 0);
    queue<int> bfs;
    bfs.push(0);
    seen[0] = 1;
    for (int i=1; i<m; i++) {
        bfs.push(i);
        bfs.push(i*m);
        seen[i] = seen[i*m] = 1;
    }

    while (!bfs.empty()) {
        auto curr = bfs.front(); bfs.pop();
        for (int neighbor : adj[curr]) {
            if (seen[neighbor]) continue;
            seen[neighbor] = 1;
            bfs.push(neighbor);
        }
    }

    int ans = 0;
    for (int i=0; i<m*m; i++) {
        if (!seen[i]) ans++;
    }

    cout << ans << '\n';
}
