#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n), b(n);
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<n; i++) cin >> b[i];


  a[n-1] = max(a[n-1], b[n-1]);
  for (int i=n-2; i>=0; i--) {
    a[i] = max(a[i], max(a[i+1], b[i]));
  }

  a.insert(a.begin(), 0);
  for (int i=1; i<=n; i++) {
    a[i] += a[i-1];
  }

  while (q--) {
    int l, r;
    cin >> l >> r; l--;
    cout << a[r] - a[l] << ' ';
  }
  cout << '\n';
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
