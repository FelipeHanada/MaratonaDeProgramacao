#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
  int n, m;
  cin >> n >> m;
  int l = n+1, r = 0;
  string trash, side; int x;
  for (int i=0; i<m; i++) {
    cin >> trash >> trash >> side >> trash >> x;
    if (side == "right") {
      r = max(r, x);
    } else {
      l = min(l, x);
    }
  }

  if (l - r - 1 <= 0) cout << "-1\n";
  else cout << l - r - 1 << '\n';
}
