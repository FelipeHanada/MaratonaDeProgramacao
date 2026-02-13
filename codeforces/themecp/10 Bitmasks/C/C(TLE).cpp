#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> a(n, vector<int>(k));
  for (int i=0; i<n; i++) {
    for (int j=0; j<k; j++) {
      cin >> a[i][j];
    }
  }

  map<vector<int>, int> dp;
  {
    vector<int> x(k,0);
    dp[x] = 0;
  }
  
  for (int i=0; i<n; i++) {
    map<vector<int>, int> next;
    for (auto [x, m] : dp) {
      if (!next.count(x)) next[x] = INT32_MAX;
      
      next[x] = min(next[x], m);

      bool ok = 1, dead = 0;
      vector<int> y = x;
      for (int j=0; j<k; j++) {
        y[j] += a[i][j];
        if (y[j] > (m+1)/2) ok = 0;
        if (y[j] > n/2) dead = 1;
      }
      if (dead) continue;
      
      if (!next.count(y)) next[y] = INT32_MAX;
      next[y] = min(next[y], m + 1);

      if (ok) {
        cout << "YES\n";
        return;
      }
    }

    dp = next;
  }

  cout << "NO\n";
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
