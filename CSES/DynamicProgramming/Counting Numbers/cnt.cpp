#include <bits/stdc++.h>
using namespace std;

using ll = long long;

map<tuple<string, int, bool, int>, ll> memo;
ll solve(const string &a, int n, bool tight, int last) {
  if (memo.count(make_tuple(a, n, tight, last))) return memo[make_tuple(a, n, tight, last)];

  if (n == 0) return 0;
  if (n == 1) {
    ll ans = (tight ? a[a.size()-n]-'0'+1 : 10);
    if (last <= ans - 1) ans--;
    return ans;
  }
 
  ll ans = 0;
  if (tight) {
    if (last == 10) ans += solve(a, n-1, 0, 10);
    else if (last != 0 && a[a.size()-n] != '0') ans += solve(a, n-1, 0, 0);

    for (int i=1; i<a[a.size()-n]-'0'; i++) if (i != last) ans += solve(a, n-1, 0, i);

    if (a[a.size()-n]-'0' != last) ans += solve(a, n-1, 1, a[a.size()-n]-'0');
  } else {
    if (last == 10) ans += solve(a, n-1, 0, 10);
    else if (last != 0) ans += solve(a, n-1, 0, 0);
    for (int i=1; i<10; i++) if (i != last) ans += solve(a, n-1, 0, i);
  }

  memo[make_tuple(a, n, tight, last)] = ans;
  return ans;
}

int main() {
  ll a, b;
  cin >> a >> b;
  string sa, sb;
  
  a--;
  if (a != -1) {
    while (a) {
      sa.insert(sa.begin(), '0' + a % 10);
      a /= 10;
    }
    if (sa.empty()) sa.push_back('0');
  }
  while (b) {
    sb.insert(sb.begin(), '0' + b % 10);
    b /= 10;
  }
  if (sb.empty()) sb.push_back('0');

  cout << solve(sb, sb.size(), 1, 10) - solve(sa, sa.size(), 1, 10) << '\n';
}
