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
  ll t = 0;
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      cin >> grid[i][j];
      t += grid[i][j];
    }
  }

  // its always possible to make one side of the table have exactly floor(n/2) 1's
  ll target = t/2;
  ll curr = t;
  vector<int> ans(m);
  for (int i=0; i<m; i++) {
    int j = n-1;
    for (; curr > target && j >= 0; j--) {
      // we need to leave ones in this col
      curr -= grid[j][i];
    }
    ans[i] = j + 1;
  }

  cout << target * (t - target) << '\n';
  int last = 0;
  for (int i=0; i<m; i++) {
    for (int j=0; j<ans[i]-last; j++) cout << 'D';
    last = ans[i];
    cout << 'R';
  }
  for (int i=0; i<n-last; i++) cout << 'D';
  cout << '\n';
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
