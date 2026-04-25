#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    int n, m;
    cin >> n >> m;
    vector grid(n, vector<char>(m));
    vector seen(n, vector<bool>(m, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') seen[i][j] = 1;
        }
    }

    auto valid = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) if (!seen[i][j]) {
            stack<pair<int,int>> dfs; dfs.push({i, j});

            int t = 1;
            while (!dfs.empty()) {
                auto [x, y] = dfs.top(); dfs.pop();
                if (x == 0 || x == n-1 || y == 0 || y == m-1) t = 0;
                for (int k=0; k<4; k++) {
                    int nx = x+dx[k], ny = y+dy[k];
                    if (valid(nx, ny) && !seen[nx][ny]) {
                        seen[nx][ny] = 1;
                        dfs.push({nx, ny});
                    }
                }
            }

            ans += t;
        }
    }

    cout << ans << '\n';
}
