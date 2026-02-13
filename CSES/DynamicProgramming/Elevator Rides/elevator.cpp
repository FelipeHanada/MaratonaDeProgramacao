#include <bits/stdc++.h>
using namespace std;


int main() {
  int n, k;
  cin >> n >> k;

  vector<int> w(n);
  for (int i=0; i<n; i++) {
    cin >> w[i];
  }

  vector<pair<int, int>> dp(1<<n, { INT32_MAX, 0 });
  // dp[x] = { minimum number of rides, weight of the last ride }

  // O(n * 2^n)

  dp[0] = { 0, k };
  for (int x=1; x<(1<<n); x++) {
    for (int j=0; j<n; j++) if (x & (1<<j)) {
      int y = x&~(1<<j);

      dp[x] = min(dp[x], (dp[y].second + w[j] <= k ?
          make_pair(dp[y].first, dp[y].second + w[j]) :
          make_pair(dp[y].first + 1, w[j])));
    }
  }

  cout << dp[(1<<n)-1].first << '\n';
}

