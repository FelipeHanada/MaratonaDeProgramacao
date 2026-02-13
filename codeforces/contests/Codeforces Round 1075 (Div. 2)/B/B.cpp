#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
  ll n; ll x;
  cin >> n >> x;
  vector<ll> a(n), b(n), c(n);
  ll jumps2 = 0;
  for (ll i=0; i<n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    jumps2 = max(jumps2, a[i]*b[i]-c[i]);
  }

  ll big = 0;
  for (ll i=0; i<n; i++) {
    big += (ll)a[i]*(b[i]-1);
  }

  if (big >= x) {
    cout << "0\n";
    return;
  }

  if (jumps2 <= 0) {
    cout << "-1\n";
    return;
  }

  ll delta = x - big;
  ll ans = (delta + jumps2 - 1) / jumps2;

  cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    ll tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
