#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  int n, t, k, d;
  cin >> n >> t >> k >> d;
  
  int m = (n + k - 1) / k;
  int a = m * t, b;
  
  int done = d / t;
  m -= done;
  if (m % 2) {
    // old oven will finish last
    b = (done+1)*t + m/2*t;
  } else {
    // new ...
    b = d + m/2*t;
  }

  if (b < a) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
    
  precompute();
  solve();
  return 0;
}
