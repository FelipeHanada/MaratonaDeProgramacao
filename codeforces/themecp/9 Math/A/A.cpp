#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

// 1 + 3 + 5 + ... + 2*k-1 = k*k
// k*k

void solve() {
  ll n, k;
  cin >> n >> k;

  if ((k%2) != (n%2) || n < k*k) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
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
