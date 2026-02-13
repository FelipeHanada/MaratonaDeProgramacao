#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  int small = k, big = k;
  while (big < n) {
    small = small * 2 - 1;
    big = big * 2 + 1;
    ans++;
  }

  if (n < small) {
    cout << "-1\n";
    return;
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
