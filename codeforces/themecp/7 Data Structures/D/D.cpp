#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 5000;
int grid[MAX_N][MAX_N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      char c;
      cin >> c;
      grid[i][j] = (c == '1');
    }
  }

  int ans = 0;
  vector<int> right(n, 0);
  vector<int> cnt(m+1, 0); cnt[0] = n;
  for (int j=m-1; j>=0; j--) {
    for (int i=0; i<n; i++) {
      cnt[right[i]]--;
      if (grid[i][j]) right[i]++;
      else right[i] = 0;
      cnt[right[i]]++;
    }

    int seen = 0;
    for (int i=m; i>=0; i--) {
      seen += cnt[i];
      ans = max(ans, i * seen);
    }
  }

  cout << ans << '\n';
}
