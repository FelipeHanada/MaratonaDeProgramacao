#include <bits/stdc++.h>
using namespace std;


constexpr int md = 998244353;
inline int add(int a, int b) {
    a += b;
    if (a >= md) a-= md;
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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

        vector<int> deg(n, 0);
        queue<int> q; q.push(0);
        vector<bool> seen(n, 0); seen[0] = 1;
        while (!q.empty()) {
            auto curr = q.front(); q.pop();

            for (int neighbor : adj[curr]) {
                deg[neighbor]++;
                if (seen[neighbor]) continue;
                seen[neighbor] = 1;
                q.push(neighbor);
            }
        }

        q.push(0);
        vector<int> dp(n, 0);
        dp[0] = 1;

        while (!q.empty()) {
            int curr = q.front(); q.pop();

            for (int neighbor : adj[curr]) {
                dp[neighbor] = add(dp[neighbor], dp[curr]);

                if (!(--deg[neighbor])) q.push(neighbor);
            }
        }

        cout << dp.back() << '\n';
    }
}