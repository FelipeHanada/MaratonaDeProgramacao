#include <bits/stdc++.h>
using namespace std;
 
 
using ll = long long;
 
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> grid(n, vector<ll>(m));
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        cin >> grid[i][j];
      }
    }
 
    vector<pair<int, int>> path;
    ll path_cost;
    {
      vector<vector<ll>> dp(n, vector<ll>(m));
      dp[0][0] = grid[0][0];
      for (int i=1; i<n; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
      for (int i=1; i<m; i++) dp[0][i] = dp[0][i-1] + grid[0][i];
      for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
      }
 
      pair<int, int> curr = {n-1, m-1};
      path.push_back(curr);
      while (curr.first != 0 && curr.second != 0) {
        auto [i, j] = curr;
        if (dp[i-1][j] == dp[i][j] - grid[i][j]) curr = {i-1, j};
        else curr = {i, j-1};
        path.push_back(curr);
      }
      while (curr.first != 0) {
        curr.first--;
        path.push_back(curr);
      }
      while (curr.second != 0) {
        curr.second--;
        path.push_back(curr);
      }
      path_cost = dp[n-1][m-1];
    }
 
    vector<vector<ll>> dp(n, vector<ll>(m));
    ll ans = path_cost; // if all cells on the path have neg value,
                        // we can change some other cell with pos value (it always exists)
    for (auto [x, y] : path) {
      grid[x][y] = -grid[x][y];
 
      dp[0][0] = grid[0][0];
      for (int i=1; i<n; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
      for (int i=1; i<m; i++) dp[0][i] = dp[0][i-1] + grid[0][i];
      for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
      }
 
      ans = min(ans, dp[n-1][m-1]);
 
      grid[x][y] = -grid[x][y];
    }
 
    cout << ans << '\n';
  }
}