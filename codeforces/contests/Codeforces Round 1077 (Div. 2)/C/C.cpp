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
  vector<int> a(n), b;
  for (int i=0; i<n; i++) cin >> a[i];
  b = a;
  sort(b.begin(), b.end());

  bool sorted = true;
  for (int i=0; i<n && sorted; i++) {
    if (a[i] != b[i]) sorted = false;
  }
  if (sorted) {
    cout << "-1\n";
    return;
  }

  int ans = INT32_MAX;
  for (int i=0; i<n; i++) {
    if (a[i] == b[i]) continue;
    ans = min(ans, max(a[i] - b[0], b.back() - a[i]));
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
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
