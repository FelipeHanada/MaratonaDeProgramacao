#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;

    int big = INT32_MIN;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
      cin >> a[i];
      big = max(big, a[i]);
    }

    int g = a[0];
    for (int i=1; i<n; i++) {
      g = __gcd(g, a[i]);
    }

    cout << big / g << '\n';
  }
}
