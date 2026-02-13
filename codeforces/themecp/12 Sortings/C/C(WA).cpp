#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

/*
 * a pair (x, y) is accurate iff.
 * WLOG |x| <= |y|
 * (1) |x-y| <= |x| AND |x+y| >= |y|
 * or (2) |x+y| <= |x| AND |x-y| >= |y|
 * 
 * (1) only ocurrs when x and y share the same signal
 * (2) 
 */

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  int neg = 0;
  for (int x : a) {
    if (x < 0) neg++;
  }

  ll ans = neg * (neg-1) / 2;
  for (int i=0; i<n; i++) {
    if (a[i] >= 0) {
      auto l = lower_bound(a.begin(), a.end(), a[i]);
      auto r = upper_bound(a.begin(), a.end(), 2*a[i]);
      ans += distance(l, r) - 1 + neg;
    }
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
  solve();
  return 0;
}
