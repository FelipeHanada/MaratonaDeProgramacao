#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
  int s, k, m;
  cin >> s >> k >> m;
  int a = m % k;
  if ((m / k) % 2) {
    cout << max(0, min(s, k) - a) << '\n';
  } else {
    cout << max(0, s - a) << '\n';
  }
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
