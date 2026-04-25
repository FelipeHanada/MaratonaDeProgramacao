#include <bits/stdc++.h>
using namespace std;


#define node(x, y) (x*m+y)

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n*m, vector<int>());
    vector<vector<int>> adj_inv(n*m, vector<int>());
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    auto valid = [&](int i, int j)->bool {
        if (i < 0 || j < 0 || i >= n || j >= m) return false;
        return true;
    };

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<8; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (valid(ni, nj) && grid[ni][nj] == grid[i][j] + 1) {
                    adj[node(i, j)].push_back(node(ni, nj));
                    adj_inv[node(ni, nj)].push_back(node(i, j));
                }
            }
        }
    }

    vector<int> deg(n*m, 0);
    queue<int> q;
    for (int i=0; i<n*m; i++) {
        deg[i] = adj[i].size();
        if (deg[i] == 0) q.push(i);
    }

    int ans = 1;
    vector<int> dp(n*m, 1);
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        ans = max(ans, dp[curr]);

        for (int neighbor : adj_inv[curr]) {
            dp[neighbor] = max(dp[neighbor], dp[curr] + 1);

            if (!(--deg[neighbor])) {
                q.push(neighbor);
            }
        }
    }

    cout << ans << '\n';
}