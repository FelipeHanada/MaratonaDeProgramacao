#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  int n, k;
  cin >> n >> k;
  map<int, int> cnt;
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }

  ll ans = INT64_MIN;
  auto it = cnt.begin();
  while (it != cnt.end()) {
    queue<int> q; q.push(it->second);
    ll curr = it->second; ans = max(ans, curr);
    int last = it->first;
    it++;
    while (it != cnt.end() && it->first == last + 1) {
      q.push(it->second);
      curr += it->second;
      last = it->first;
      if (q.size() > k) {
        curr -= q.front();
        q.pop();
      }

      ans = max(ans, curr);
      it++;
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
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
