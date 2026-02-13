#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define first _1
#define second _2

void precompute() {
  
}

/* 2 4 * 8 10 * 14 16 * ...
 * 3   * 9    * 15    * ...
 * let X be the answer
 * let Ci be the amount of number multiple of i from 0 to X
 * it is sufficient for X to be okay that:
 *  - C2 >= n                   floor(X/2) >= n
 *  - C3 >= m                   floor(X/3) >= m
 *  - C2 + C3 - C6 >= m + n     floor(X/2) + floor(X/3) - floor(X/6) >= n + m
 */

void solve() {
  int n, m;
  cin >> n >> m;
  
  for (int x=max(2*n, 3*m); x<=6*(n+m); x++) {
    if (x/2 + x/3 - x/6 >= n + m) {
      cout << x << '\n';
      return;
    }
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    solve();
    return 0;
}
