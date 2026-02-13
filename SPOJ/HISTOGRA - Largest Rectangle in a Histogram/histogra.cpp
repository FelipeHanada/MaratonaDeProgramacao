#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
  int n;
  cin >> n;
  while (n){
    vector<ll> h(n);
    for (int i=0; i<n; i++) cin >> h[i];
 
    stack<pair<ll, int>> stk;
    ll ans = 0;
    for (int i=0; i<n; i++) {
      int last_pos = i;
      while (!stk.empty() && stk.top().first > h[i]) {
        ans = max(ans, stk.top().first * (i - stk.top().second));
        last_pos = stk.top().second;
        stk.pop();
      }
      stk.push({h[i], last_pos});
    }
    while (!stk.empty()) {
      ans = max(ans, stk.top().first * (n - stk.top().second));
      stk.pop();
    }
    cout << ans << '\n';
    cin >> n;
  }
}
