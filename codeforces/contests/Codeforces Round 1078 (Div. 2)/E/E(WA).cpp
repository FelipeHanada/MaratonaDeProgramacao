#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  int n, m;
  cin >> n >> m;
  int grid[n][m];
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin >> grid[i][j];
    }
  }

  ll dp1[n][m], dp2[n][m];
  dp1[0][0] = grid[0][0];
  dp2[0][0] = -grid[0][0];

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (i == 0 && j == 0) continue;

      dp1[i][j] = INT64_MIN;
      if (i) dp1[i][j] = max(dp1[i][j], dp1[i-1][j]) + grid[i][j];
      if (j) dp1[i][j] = max(dp1[i][j], dp1[i][j-1]) + grid[i][j];

      dp2[i][j] = INT64_MIN;
      if (i) dp2[i][j] = max(dp2[i][j], dp2[i-1][j]) + grid[i][j];
      if (j) dp2[i][j] = max(dp2[i][j], dp2[i][j-1]) + grid[i][j];
      dp2[i][j] = min(dp2[i][j], dp1[i][j] - 2 * grid[i][j]);
    }
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) cout << dp1[i][j] << ' ';
    cout << '\n';
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) cout << dp2[i][j] << ' ';
    cout << '\n';
  }

  cout << dp2[n-1][m-1] << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
    
  precompute();
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
