#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define first _1
#define second _2

void precompute() {
  
}

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int e, f;
  cin >> e >> f;
  int dx = abs(a - c);
  int dy = abs(b - d);
  cout << ((dx % e == 0 && dy % f == 0 && (dx/e)%2 == (dy/f)%2) ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    solve();
    return 0;
}
