#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        for (int i=0; i<m; i++) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
        }

        vector<int> d(n, -1);
        d[0] = 0;
        queue<int> q; q.push(0);
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            for (int neighbor : adj[curr]) {
                if (d[neighbor] != -1) continue;
                d[neighbor] = d[curr] + 1;
                q.push(neighbor);
            }
        }

        vector<int> dp(n);
        for (int i=0; i<n; i++) {
            dp[i] = d[i];
        }

        vector<pair<int, int>> ord(n);
        for (int i=0; i<n; i++) ord[i] = { d[i], i };
        sort(ord.rbegin(), ord.rend());

        for (auto [_, i] : ord) {
            for (int j : adj[i]) {
                if (d[i] < d[j]) dp[i] = min(dp[i], dp[j]);
                else dp[i] = min(dp[i], d[j]);
            }
        }

        for (int i=0; i<n; i++) cout << dp[i] << ' ';
        cout << '\n';
    }
}

/*
dp[i] = min(dp[j] : j s.t. d[i] < d[j])

*/