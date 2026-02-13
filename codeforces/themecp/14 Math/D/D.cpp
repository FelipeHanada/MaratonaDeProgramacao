#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i=0; i<n; i++) cin >> a[i];

  // ocurrs that i*j >>> k*(a[i]|a[j]) for large i and j, since a[i],a[j] <= n <= 1e5
  // for some pair (i, j) to be relevant, f(i, j) mus be atleast the minimum value that f(n, n+1) could assume
  //
  // for some i, the maximum value that f(i, j) could possibly assume is i*n - k*0 = i * n
  // alternatively, the minimum value that f(n-1, n) could possibily assume is (n-1)*n - k * 2*n (a[i]|a[j] <= 2*n)
  //
  // that gives us the following inequality:
  //    i * n >= n*n -n - 2*k*n = n*n -(2*k-1)n
  //    i >= n - 2*k - 1
  // therefore, suffices for us to check all pairs of (i, j) with i >= n-2*k-1
  //    there is O(k^2) pairs, that is feasible since k <= 100

  ll ans = INT64_MIN;
  for (ll i=max(0, n-2*k-1-1); i<n; i++) {
    for (ll j=i+1; j<n; j++) {
      ans = max(ans, (i+1)*(j+1)-k*(a[i]|a[j]));
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
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
