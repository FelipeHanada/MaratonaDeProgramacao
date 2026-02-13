#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
  int n, k, x, a, b, c;
  cin >> n >> k >> x >> a >> b >> c;

  deque<int> window(k);
  deque<int> dq;
  window[0] = x; dq.push_back(x);
  for (int i=1; i<k; i++) {
    window[i] = ((ll)window[i-1]*a+b)%c;
    while (!dq.empty() && dq.back() > window[i]) dq.pop_back();
    dq.push_back(window[i]);
  }
  int ans = dq.front();
  
  for (int j=k; j<n; j++) {
    if (dq.front() == window.front()) dq.pop_front();

    window.push_back(((ll)window.back()*a+b)%c);
    window.pop_front();
    
    while (!dq.empty() && dq.back() > window.back()) dq.pop_back();
    dq.push_back(window.back());

    ans ^= dq.front();
  }

  cout << ans << '\n';
}
