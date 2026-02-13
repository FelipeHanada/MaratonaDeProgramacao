#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
  int n;
  cin >> n;
  vector<int> a, b;
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    if (x % 2) b.push_back(x);
    else a.push_back(x);
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  
  if (a.empty()) {
    cout << b[0] << '\n';
    return;
  }
  if (b.empty()) {
    cout << a[0] << '\n';
    return;
  }

  long long ans = b[0];
  for (int i=1; i<b.size(); i++) ans += b[i] - 1;
  for (int x : a) ans += x;
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
