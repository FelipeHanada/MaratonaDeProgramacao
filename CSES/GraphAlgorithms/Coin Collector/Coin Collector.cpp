#include <bits/stdc++.h>
using namespace std;
using ll = long long;


     dfs()

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
    }

    vector<bool> seen(n, 0);
    ll ans = 0;
    for (int i=0; i<n; i++) if (!seen[i]) {
        stack<int> dfs; dfs.push(i);
        seen[i] = 1;
        ll score = 0;
        while (!dfs.empty()) {
            int curr = dfs.top(); dfs.pop();
            score += a[curr];
            for (int neighbor : adj[curr]) if (!seen[curr]) {
                seen[curr] = 1;
                dfs.push(neighbor);
            }
        }

        ans = max(ans, score);
    }

    cout << ans << '\n';
}
