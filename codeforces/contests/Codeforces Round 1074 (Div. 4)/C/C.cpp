#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
  int n;
  cin >> n;
  set<int> s;
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }

  int ans = 0;
  auto it = s.begin();
  while (it != s.end()) {
    int delta = *it;
    int curr = 0;
    while (s.count(curr+delta)) curr++;
    ans = max(ans, curr);
    it++;
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
