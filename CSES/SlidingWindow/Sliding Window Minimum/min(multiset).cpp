#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int n, k, x, a, b, c;
  cin >> n >> k >> x >> a >> b >> c;

  int ans = 0;
  multiset<int> s; s.insert(x);
  int j=1;
  int first = x, last = x;
  while (j < k) {
    last = ((ll)last*a+b)%c;
    s.insert(last);
    j++;

  }
  ans = *s.begin();

  while (j < n) {
    last = ((ll)last*a+b)%c;
    s.insert(last);
    s.extract(first);
    first = ((ll)first*a+b)%c;
    j++;

    ans ^= *s.begin();
  }

  cout << ans << '\n';
}

