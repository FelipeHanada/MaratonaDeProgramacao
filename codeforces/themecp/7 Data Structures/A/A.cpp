#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  int n; string s;
  cin >> n >> s;
  stack<int> stk;
  int ans = 0;
  for (int i=0; i<n; i++) {
    if (s[i] == '(') stk.push(i);
    else if (s[i] == ')') {
      ans += i - stk.top();
      stk.pop();
    } else {
      if (stk.empty()) stk.push(i);
      else {
        ans += i - stk.top();
        stk.pop();
      }
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
