#include <bits/stdc++.h>
using namespace std;


#define ll long long

int solve(const vector<int> &s, int n, int x, bool tight) {
  int ans = 0;
  if (n == 1) {
    ans = tight ? s[0] + 1 : 10;
    if (x < ans) ans--;
    return ans;
  }

  if (tight) {
    if (x == -1) ans += solve(s, n-1, -1, !s[n-1]);
    else if (x != 0) ans += solve(s, n-1, 0, !s[n-1]);

    for (int i=1; i<s[n-1]; i++) if (i != x) {
      ans += solve(s, n-1, i, 0);
    }

    if (s[n-1] && s[n-1] != x)
      ans += solve(s, n-1, s[n-1], 1);
    
      return ans;
  }

  for (int i=0; i<10; i++) if (i != x) {
    ans += solve(s, n-1, i, 0);
  }

  return ans;
}

int main() {
  ll a, b;
  cin >> a >> b;
  a--;
  vector<int> anum, bnum;
  while (a) {
    anum.push_back(a % 10);
    a /= 10;
  }
  if (anum.empty()) anum.push_back(0);
  while (b) {
    bnum.push_back(b % 10);
    b /= 10;
  }
  if (bnum.empty()) bnum.push_back(0);

  int low = solve(anum, anum.size(), -1, 1),
      high = solve(bnum, bnum.size(), -1, 1);

  cout << high - low << '\n';
}
