#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> grid(n, vector<ll>(m));
        for (int i=0; i<n; i++) for (int j=0; j<m; j++)
            cin >> grid[i][j];

        vector<vector<ll>> dp1(n, vector<ll>(m));
        dp1[0][0] = grid[0][0];
        for (int i=1; i<n; i++) dp1[i][0] = dp1[i-1][0] + grid[i][0];
        for (int j=1; j<m; j++) dp1[0][j] = dp1[0][j-1] + grid[0][j];
        for (int i=1; i<n; i++) for (int j=1; j<m; j++) {
            dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]) + grid[i][j];
        }

        deque<pair<int, int>> path;
        path.push_back({n-1, m-1});
        while (path.back().first != 0 || path.back().second != 0) {
            auto [i, j] = path.back();
            if (i == 0) {
                path.push_back({0, j-1});
            } else if (j == 0) {
                path.push_back({i-1, 0});
            } else {
                if (dp1[i][j] - grid[i][j] == dp1[i-1][j]) {
                    path.push_back({i-1, j});
                } else {
                    path.push_back({i, j-1});
                }
            }
        }
        path.pop_back();
        if (!path.empty()) path.pop_front();
        
        vector<vector<ll>> dp2(n, vector<ll>(m));
        dp2[n-1][m-1] = grid[n-1][m-1];
        for (int i=n-2; i>=0; i--) dp2[i][m-1] = dp2[i+1][m-1] + grid[i][m-1];
        for (int j=m-2; j>=0; j--) dp2[n-1][j] = dp2[n-1][j+1] + grid[n-1][j];
        for (int i=n-2; i>=0; i--) {
            for (int j=m-2; j>=0; j--) {
                dp2[i][j] = max(dp2[i+1][j], dp2[i][j+1]) + grid[i][j];
            }
        }


        vector<pair<ll, ll>> dp3(n+m, {INT64_MIN, INT64_MIN});
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                ll val = dp1[i][j] + dp2[i][j] - grid[i][j];
                if (val > dp3[i+j].first) {
                    if (val > dp3[i+j].second) {
                        dp3[i+j].second = dp3[i+j].first;
                    }
                    dp3[i+j].first = val;
                } else if (val > dp3[i+j].second) {
                    dp3[i+j].second = val;
                }
            }
        }

        ll ans = dp1[n-1][m-1] - max(0LL, 2*max(grid[0][0], grid[n-1][m-1]));
        for (auto [x, y] : path) {
            ll curr = dp1[n-1][m-1] - 2 * grid[x][y];

            if (dp1[x][y] + dp2[x][y] - grid[x][y] != dp3[x+y].first) {
                curr = max(curr, dp3[x+y].first);
            } else {
                curr = max(curr, dp3[x+y].second);
            }

            ans = min(ans, curr);
        }

        cout << ans << '\n';
    }
}
