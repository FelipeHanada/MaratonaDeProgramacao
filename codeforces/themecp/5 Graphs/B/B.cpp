#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}


constexpr int MAX_N = 100;
bool grid[MAX_N][MAX_N];
bool seen[MAX_N][MAX_N];
void solve() {
  int n, m;
  cin >> n >> m;
  
  queue<pair<int, int>> blacks;
  for (int i=0; i<n; i++) {
    fill_n(seen[i], m, 0);
    for (int j=0; j<m; j++) {
      char c;
      cin >> c;
      grid[i][j] = c == '1';
      if (c == '1') {
        blacks.push({i, j});
      }
    }
  }

  bool good = 1;
  while (!blacks.empty() && good) {
    auto [ x, y ] = blacks.front();
    blacks.pop();
    if (seen[x][y]) continue;

    if ((x - 1 >= 0 && seen[x-1][y]) ||
        (x + 1 < n && seen[x+1][y]) ||
        (y - 1 >= 0 && seen[x][y-1]) ||
        (y + 1 < m && seen[x][y+1])) {
      good = 0;
    }
    
    int width = 1, height = 1;
    while (x+width < n && grid[x+width][y]) width++;
    while (y+height < m && grid[x][y+height]) height++;

    for (int i=x; i<width+x && good; i++) {
      for (int j=y; j<height+y && good; j++) {
        if (!grid[i][j] || seen[i][j]) good = 0;
        seen[i][j] = 1;
      }
    }
  }

  cout << (good ? "YES" : "NO") << '\n';
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
