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
  vector<int> a(n);
  for (int i=0; i<n; i++) cin >> a[i];

  ll ans = INT64_MIN;
  vector<ll> b(n);
  for (int i=n-1; i>=0; i--) {
    if (i + a[i] >= n) b[i] = a[i];
    else {
      b[i] = a[i] + b[i+a[i]];
    }
    ans = max(ans, b[i]);
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
