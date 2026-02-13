#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

constexpr int MAX_N = 300;
int grid[MAX_N][MAX_N];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i=0; i<n; i++) fill_n(grid[i], n, 0);

  vector<int> r(n, 0), c(n, 0);
  for (int i=0; k && i<n; i++) {
    for (int j=0; k && j<n; j++) {
      grid[(i+j)%n][j] = 1;

      r[(i+j)%n]++;
      c[j]++;
      k--;
    }
  }
  sort(r.begin(), r.end());
  sort(c.begin(), c.end());

  int dr = r.back() - r.front(), dc = c.back() - c.front();
  cout << dr*dr + dc*dc << '\n';
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cout << grid[i][j];
    }
    cout << '\n';
  }
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
