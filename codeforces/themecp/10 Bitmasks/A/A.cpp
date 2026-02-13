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

  if (n == 1) {
    cout << k << '\n';
    return;
  }

  int i=0;
  while (i < k) i = (i<<1)+1;
  i>>=1;

  k -= i;
  cout << i << ' ' << k << ' ';
  for (int i=2; i<n; i++) cout << 0 << ' ';
  cout << '\n';
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
