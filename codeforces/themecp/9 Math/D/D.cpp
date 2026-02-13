#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<n; i++) cin >> b[i];

  ll sum = 0;
  for (int i=0; i<n; i++) sum += a[i] * b[i];

  if (n == 1) {
    cout << sum << '\n';
    return;
  }

  ll ans = sum;
  vector<vector<ll>> dp(n+1, vector<ll>(n)); 
  for (int j=0; j<n; j++) dp[1][j] = sum;
  for (int j=0; j<n-1; j++) {
    dp[2][j] = sum - (a[j]*b[j]) - (a[j+1]*b[j+1]) + (a[j]*b[j+1]) + (a[j+1]*b[j]);
    ans = max(ans, dp[2][j]);
  }

  for (int i=3; i<=n; i++) {
    for (int j=0; j+i-1 < n; j++) {
      dp[i][j] = dp[i-2][j+1] - (a[j]*b[j]) - (a[j+i-1]*b[j+i-1]) + (a[j]*b[j+i-1]) + (a[j+i-1]*b[j]);
      ans = max(ans, dp[i][j]);
    }
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
  solve();
  return 0;
}
