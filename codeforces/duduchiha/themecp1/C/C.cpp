#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  int small = INT32_MAX;
  for (int i=0; i<n-1; i++) {
    if (a[i]%k != a[i+1]%k) {
      cout << "-1\n";
      return 0;
    }

    a[i] = (a[i] - (a[i]%k))/k;
    small = min(small, a[i]);
  }
  a[n-1] = (a[n-1] - (a[n-1]%k))/k;
  small = min(small, a[n-1]);

  ll ans = 0;
  for (int i=0; i<n; i++) {
    ans += a[i] - small;
  }
  cout << ans << '\n';
}
