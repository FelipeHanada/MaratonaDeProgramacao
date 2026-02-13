#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define first _1
#define second _2

void precompute() {
  
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int small = INT32_MAX, big = INT32_MIN;
  vector<int> pre(n), suff(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
    pre[i] = a[i];
    suff[i] = a[i];
    small = min(small, a[i]);
    big = max(big, a[i]);
  }

  for (int i=1; i<n; i++) {
    pre[i] = min(pre[i], pre[i-1]);
    suff[n-i-1] = max(suff[n-i-1], suff[n-i]);
  }

  cout << 1;
  for (int i=1; i<n-1; i++) {
    if (a[i] == pre[i] || a[i] == suff[i]) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}
