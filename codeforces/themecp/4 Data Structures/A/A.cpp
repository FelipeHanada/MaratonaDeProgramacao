#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define first _1
#define second _2

void precompute() {
  
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> m;
  for (int i=0; i<n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  int ans = 0;
  int j = n - 1;
  while (j >= 0) {
    set<int> s;
    int curr = m.size();
    while (j >= 0 && s.size() < curr) {
      s.insert(a[j]);
      if (!(--m[a[j]])) m.erase(a[j]);
      j--;
    }
    ans++;
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
    
  precompute();
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
