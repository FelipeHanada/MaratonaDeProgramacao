#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        indeg[y]++;
    }

    queue<int> q, next;
    for (int i=0; i<n; i++) if (indeg[i] == 0) {
        q.push(i);
    }

    int ans = 0;
    while (!q.empty()) {
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            for (int neighbor : adj[curr]) {
                indeg[neighbor]--;
                if (indeg[neighbor] == 0) next.push(neighbor);
            }
        }
        swap(q, next);
        ans++;
    }

    cout << ans - 1 << '\n';
}
