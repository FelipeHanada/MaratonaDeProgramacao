#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  int k;
  cin >> k;
  vector<vector<int>> a(k);

  map<ll, pair<int, int>> m;
  pair<int, int> p = {-1, -1}, q = {-1, -1};
  for (int i=0; i<k; i++) {
    int n;
    cin >> n;
    ll sum = 0;
    for (int j=0; j<n; j++) {
      int x;
      cin >> x;
      a[i].push_back(x);
      sum += x;
    }

    for (int j=0; j<n; j++) {
      if (!m.count(sum - a[i][j])) {
        m[sum - a[i][j]] = { i, j };
      } else if (m[sum - a[i][j]].first != i) {
        p = m[sum - a[i][j]];
        q = { i, j };
      }
    }
  }

  if (p.first == -1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";

    cout << p.first+1 << ' ' << p.second+1 << '\n';
    cout << q.first+1 << ' ' << q.second+1 << '\n';
  }
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
