#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int small = INT32_MAX, big = INT32_MIN;
    for (int i=0; i<n; i++) {
      cin >> a[i];
      small = min(small, a[i]);
      big = max(big, a[i]);
    }

    int p = small;

    bool ok = 1;
    while (ok) {
      ok = 0;
      for (int i=0; i<n; i++) {
        if ((a[i]%p)) {
          p = a[i]%p;
          ok = 1;
        }
      }
    }

    cout << big / p << '\n';
  }
}

/* the answer is always max(a[i]) OR max(a[i])/min(a[i])
 *
 * 3 9 12
 * 3 6 9 12
 *
 * 6 14
 * 2 6 8 14
 *
 * 6 17 -> 
 *
 */
