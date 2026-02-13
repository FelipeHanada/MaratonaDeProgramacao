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
  vector<int> deg(n, 0);
  for (int i=0; i<m; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    deg[x]++;
    deg[y]++;
  }

  int leafs = 0;
  int deg1 = -1, deg2 = -1;
  int cnt1 = 0, cnt2 = 0;
  for (int i=0; i<n; i++) {
    if (deg[i] == 1) leafs++;
    else {
      if (deg1 == -1 || deg1 == deg[i]) {
        deg1 = deg[i];
      } else deg2 = deg[i];

      if (deg[i] == deg1) cnt1++;
      else cnt2++;
    }
  }

  if (cnt2 == 0) {
    cout << deg1 << ' ' << deg1 - 1 << '\n';
    return;
  }

  if (cnt1 > cnt2) swap(deg1, deg2);
  deg2--;

  cout << deg1 << ' ' << deg2 << '\n';
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
