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
  m += 2;
  int grid[n][m];

  int last = -1;
  for (int i=0; i<n; i++) {
    string s;
    cin >> s;
    for (int j=0; j<m; j++) {
      grid[i][j] = (s[j] == '1');
      if ((s[j] == '1') && last == -1) last = i;
    }
  }

  if (last == -1) {
    cout << "0\n";
    return;
  }

  ll bestL = 0, bestR = INT32_MAX;
  for (int i=n-1; i>last; i--) {
    int l = 0, r = m-1;
    while (l < m && !grid[i][l]) l++;
    while (r >= 0 && !grid[i][r]) r--;
    if (l == m) continue;

    tie(bestL, bestR) = make_tuple(
      min(bestL + 2*r, bestR + m - 1),
      min(bestR + 2*(m-l-1), bestL + m - 1)
    );
  }
  int l = 0, r = m-1;
  while (l < m && !grid[last][l]) l++;
  while (r >= 0 && !grid[last][r]) r--;
  tie(bestL, bestR) = make_tuple(bestL + r, bestR + (m-l-1));
  bestL += n-1-last; bestR += n-1-last;

  cout << min(bestL, bestR) << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
    
  precompute();
  int tt;
  solve();
  return 0;
}
