#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> next(n+1);
  vector<int> suffix(n+1);
  next[n] = n;
  suffix[n] = 0;
  for (int i=n-1; i>=0; i--) {
    if (s[i] == '(') next[i] = i;
    else next[i] = next[i+1];
    suffix[i] = suffix[i+1];
    if (s[i] == '(') suffix[i]++;
  }

  int ans = -1;
  for (int i=0; i<n; i++) if (s[i] == ')') {
    // we can greedily choose the first ( to take place at t[i]
    // let next[i] be the position of such bracket
    // since we skipped (next[i]-i) )'s, to make t a RBS we need to skip the next (next[i]-i) ('s after next[i]
    if (next[i]+1 <= n && suffix[next[i]+1] >= next[i]-i)
      ans = max(ans, n - 2*(next[i]-i));
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
