#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  ll n, x, y;
  cin >> n >> x >> y;
  ll total = 0;
  vector<ll> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
    total += a[i] / x;
  }

  ll ans = 0;
  for (int i=0; i<n; i++) {
    ll curr = total - a[i]/x;
    ans = max(ans, a[i] + curr * y);
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
