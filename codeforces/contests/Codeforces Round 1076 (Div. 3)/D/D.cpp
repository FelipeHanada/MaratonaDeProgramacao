#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<n; i++) cin >> b[i];
  sort(a.begin(), a.end());
  for (int i=1; i<n; i++) b[i] += b[i-1];

  map<int, int> cnt1;
  for (int i=0; i<n; i++) cnt1[a[i]]++;

  ll ans = 0;
  int z = n;
  for (auto [x, y] : cnt1) {
    auto ub = upper_bound(b.begin(), b.end(), z);
    ans = max(ans, x * (ll)distance(b.begin(), ub));
    z -= y;
  }

  cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
