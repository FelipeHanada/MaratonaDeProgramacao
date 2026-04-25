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
    }

    vector<bool> seen(n, 0); seen[0] = 1;
    queue<int> q; q.push(0);
    while (!q.empty()) {
        auto curr = q.front(); q.pop();

        for (int neighbor : adj[curr]) {
            if (seen[neighbor]) continue;
            seen[neighbor] = 1;
            q.push(neighbor);
        }
    }

    cout << count(seen.begin(), seen.end(), 1) << '\n';
}
