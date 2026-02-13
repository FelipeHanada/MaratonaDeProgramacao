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
  string s;
  cin >> s;
  vector<int> v;
  int last = 0;
  ll cnt = 0;
  for (int i=0; i<n; i++) {
    if (s[i] == '1') {
      cnt++;
      if (i - last) v.push_back(i - last);
      last = i + 1;
    }
  }
  if (n - last) v.push_back(n - last);

  if (s[0] != '1' && cnt) v.front()--;
  if (s.back() != '1' && cnt) v.back()--;
  for (int i=1 - (s[0] == '1'); i<v.size() - (s.back() == '0'); i++) {
    v[i] -= 2;
  }

  ll ans = cnt;
  for (int x : v) {
    ans += (x + 2) / 3;
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
