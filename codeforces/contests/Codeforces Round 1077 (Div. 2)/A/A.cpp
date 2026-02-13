#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {

}

void solve() {
  int n;
  cin >> n;
  int x = (n+1)/2;
  int p = 0;
  for (int i=0; i<n; i++) {
    cout << x + p << ' ';
    if (p > 0) p *= -1;
    else p = -p + 1;
  }
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
