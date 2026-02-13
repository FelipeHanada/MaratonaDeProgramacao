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
  vector<int> a(n);
  int small = INT32_MAX;
  for (int i=0; i<n; i++) {
    cin >> a[i];
    small = min(small, a[i]);
  }

  int last = -1;
  int ans = INT32_MAX;
  for (int i=0; i<n; i++) {
    if (a[i] == small) {
      if (last != -1) {
        ans = min(ans, i - last);
      }
      last = i;
    }
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
  solve();
  return 0;
}
