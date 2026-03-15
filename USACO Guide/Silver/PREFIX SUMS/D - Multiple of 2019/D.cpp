#include <bits/stdc++.h>
using namespace std;

/*
 * 1817181712114
 *
 * 1 18 181 1817 
 */

using ll = long long;

constexpr int md = 2019;
int add(int a, int b) {
  a += b;
  if (a > md) a -= md;
  return a;
}
int sub(int a, int b) {
  a -= b;
  if (a < 0) a += md;
  return a;
}
int mult(int a, int b) {
  return ((ll)a * b) % md;
}

int main() {
  string s;
  cin >> s;
  const int n = s.size();
  int sum = 0;
  for (int i=0; i<n; i++) {
    sum = mult(sum, 10);
    sum = add(sum, s[i] - '0');
  }

  reverse(s.begin(), s.end());
  vector<int> cnt(md, 0);
  cnt[sum]++;
  int p = 1;
  for (int i=0; i<n; i++) {
      sum = sub(sum, mult(p, s[i] - '0'));
      cnt[sum]++;
      p = mult(p, 10);
  }

  int ans = 0;
  for (int i=0; i<md; i++) {
    if (cnt[i] < 2) continue;
    ans += (cnt[i] * (cnt[i] - 1)) / 2;
  }

  cout << ans << '\n';
}
