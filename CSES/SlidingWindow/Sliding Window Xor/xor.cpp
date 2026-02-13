#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
  int n, k, x, a, b, c;
  cin >> n >> k >> x >> a >> b >> c;

  int ans = 0;
  deque<int> window = {x};
  int curr = x;
  int j = 1;
  while (j < k) {
    window.push_back(((ll)window.back()*a+b)%c);
    curr ^= window.back();
    j++;
  }
  ans ^= curr;

  while (j < n) {
    window.push_back(((ll)window.back()*a+b)%c);
    curr ^= window.front() ^ window.back();
    window.pop_front();
    j++;
    ans ^= curr;
  }

  cout << ans << '\n';
}
