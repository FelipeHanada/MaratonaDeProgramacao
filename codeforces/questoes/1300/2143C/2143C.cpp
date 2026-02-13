#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    int u, v, x, y;
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    for (int i=0; i<n-1; i++) {
        cin >> u >> v >> x >> y;
        u--; v--;
        if (x < y) {
            adj[u].push_back(v);
            indeg[v]++;
        } else {
            adj[v].push_back(u);
            indeg[u]++;
        }
    }

    queue<int> fonts;
    for (int i=0; i<n; i++) if (indeg[i] == 0) {
        fonts.push(i);
    }
    vector<int> ans(n);
    int c = 1;
    while (!fonts.empty()) {
        int curr = fonts.front();
        fonts.pop();
        for (int neighbor : adj[curr]) {
            if (--indeg[neighbor] == 0) {
                fonts.push(neighbor);
            }
        }

        ans[curr] = c++;
    }

    for (int i=0; i<n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}