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
  ll grid[n][m];
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin >> grid[i][j];
    }
  }

  ll dp1[n][m], dp2[n][m];
  dp1[0][0] = grid[0][0];
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (i == 0 && j == 0) continue;

      dp1[i][j] = INT64_MIN;
      if (i) dp1[i][j] = max(dp1[i][j], dp1[i-1][j] + grid[i][j]);
      if (j) dp1[i][j] = max(dp1[i][j], dp1[i][j-1] + grid[i][j]);
    }
  }

  dp2[n-1][m-1] = grid[n-1][m-1];
  for (int i=n-1; i>=0; i--) {
    for (int j=m-1; j>=0; j--) {
      if (i == n-1 && j == m-1) continue;

      dp2[i][j] = INT64_MIN;
      if (i<n-1) dp2[i][j] = max(dp2[i][j], dp2[i+1][j] + grid[i][j]);
      if (j<m-1) dp2[i][j] = max(dp2[i][j], dp2[i][j+1] + grid[i][j]);
    }
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) cout << dp1[i][j] << ' ';
    cout << '\n';
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) cout << dp2[i][j] << ' ';
    cout << '\n';
  }

  ll ans = INT64_MAX;

  for (int i=0; i<n; i++) {
    int j=0;
    ll big1 = INT64_MIN, big2 = INT64_MAX;
    for (int k=0; i+k<n && j-k>=0; k++) {
      ll val = dp1[i+k][j-k] + dp2[i+k][j-k] - grid[i+k][j-k];
      if (val > big1) {
        tie(big1, big2) = make_tuple(val, big1);
      } else if (val > big2) big2 = val;
    }

    ll curr = INT64_MIN;
    for (int k=0; i+k<n && j-k>=0; k++) {
      curr = max(curr, dp1[i+k][j-k] + dp2[i+k][j-k] - 3 * grid[i+k][j-k]);
    }
    ans = min(ans, max(curr, big2));
  }

  for (int j=1; j<m; j++) {
    int i=n-1;

    ll big1 = INT64_MIN, big2 = INT64_MAX;
    for (int k=0; i-k>=0 && j+k<m; k++) {
      ll val = dp1[i-k][j+k] + dp2[i-k][j+k] - grid[i-k][j+k];
      if (val > big1) {
        tie(big1, big2) = make_tuple(val, big1);
      } else if (val > big2) big2 = val;
    }

    ll curr = INT64_MIN;
    for (int k=0; i+k<n && j-k>=0; k++) {
      curr = max(curr, dp1[i-k][j+k] + dp2[i-k][j+k] - 3 * grid[i-k][j+k]);
    }
    ans = min(ans, max(curr, big2));
  }

  cout << ans << '\n';
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
