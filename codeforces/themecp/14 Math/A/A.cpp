#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

ll f(ll i) {
  return 2 + 3*(i*(i+1))/2 + 2*i;
}

void solve() {
  int n;
  cin >> n;

  // 2 7 16 
  // 2 + (1+2+3+4+...+i) + (4+6+...+2(i+1)) =
  // = 2 + (1+2+3+4+...+i) + (2+4+...+2i) + 2i
  
  ll ans = 0;
  int R = 100000;
  while (n > 1) {
    int l = 0, r = R;
    while (r - l > 1) {
      int mid = (r + l) / 2;
      if (f(mid) > n) r = mid;
      else l = mid;
    }
    n -= f(l);
    R = r;
    ans++;
  }

  cout << ans << '\n';
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
