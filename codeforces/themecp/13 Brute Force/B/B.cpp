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
  int neg = 0, pos = 0;
  map<int, int> a;
  for (int i=0; i<n; i++) {
    int x; cin >> x;
    if (x < 0) neg++;
    else if (x > 0) pos++;
    a[x]++;
  }
  if (neg > 2 || pos > 2) {
    cout << "NO\n";
    return;
  }

  bool ok = 1;
  for (auto [k1, v1] : a) {
    for (auto [k2, v2] : a) {
      int cnt2 = 1 + (k1 == k2);
      if (cnt2 > v2) continue;
      for (auto [k3, v3] : a) {
        int cnt3 = 1 + (k1 == k3) + (k2 == k3);
        if (cnt3 > v3) continue;

        int target = k1 + k2 + k3;
        if (!a.count(target)) {
          ok = 0;
          break;
        }
      }
      if (!ok) break;
    }
    if (!ok) break;
  }

  cout << (ok ? "YES\n" : "NO\n");
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
