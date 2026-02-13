#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
  int n, k, x, a, b, c;
  cin >> n >> k >> x >> a >> b >> c;

  ll ans = 0, sum = x;
  deque<ll> window = {x};
  int j=1;
  while (j < k) {
    window.push_back(((ll)a*window.back()+b)%c);
    sum += window.back();
    j++;
  }
  ans ^= sum;

  while (j < n) {
    window.push_back(((ll)a*window.back()+b)%c);
    sum += window.back() - window.front();
    window.pop_front();
    ans ^= sum;
    j++;
  }

  cout << ans << '\n';
}

