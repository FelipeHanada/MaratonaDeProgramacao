#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

/* a pair of points (x,y) (a,b) work iff.
 * x = a OR y = b OR (x+k1,y+k2) = (a,b) for k1,k2 in {-1,1}
 *
 * eq. (x-a,y-b) lay on an axis or abs(x-a) = abs(x-b)
 */

void solve() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i]._1 >> a[i]._2;
  }

  map<ll, int> layx1, layx2;
  map<ll, int> cntx, cnty;
  for (int i=0; i<n; i++) {
    cntx[a[i]._1]++;
    cnty[a[i]._2]++;
    layx1[a[i]._1 - a[i]._2]++;
    layx2[a[i]._1 + a[i]._2]++;
  }

  ll ans = 0;
  for (int i=0; i<n; i++) {
    ans += cntx[a[i]._1]-1 + cnty[a[i]._2]-1 + layx1[a[i]._1 - a[i]._2]-1 + layx2[a[i]._1 + a[i]._2]-1;
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
