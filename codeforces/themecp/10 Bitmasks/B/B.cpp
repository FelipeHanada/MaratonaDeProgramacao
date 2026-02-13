#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

int flog2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// cost 1 to make best solution
// (2<<flog2(n))-1
//
// n = 10101010010100101
// a = 01111111111111111
// b = 10000000000000000
//a^b =11111111111111111 

void solve() {
  ll n, k;
  cin >> n >> k;

  if (k == 1) {
    cout << n << '\n';
    return;
  }

  cout << (2LL<<flog2(n))-1 << '\n';
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
