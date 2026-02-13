#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  array<map<int, int>, 32> b;
  for (int i=0; i<n; i++) {
    cin >> a[i];
    int j=0;
    int x = a[i];
    while (x) {
      if (x & 1) b[j][a[i]]++;
      x >>= 1;
      j++;
    }
  }

  int curr = 0;
  int i=0, j=31;
  while (i < n) {
    while (j >= 0 && (curr & (1 << j) || b[j].empty())) j--;
    if (j < 0) break;

    int best = b[j].begin()->first;
    for (auto [k, v] : b[j]) {
      if ((curr|k) > (curr|best)) {
        best = k;
      }
    }

    cout << best << ' ';
    int x = best, k = 0;
    while (x) {
      if (x & 1) if (!(--b[k][best])) b[k].erase(best);
      x >>= 1; k++;
    }

    i++;
    curr |= best; j--;
  }

  j = 31;
  while (i < n) {
    while (b[j].empty()) j--;
    int best = b[j].begin()->first;
    cout << best << ' ';

    int x = best, k = 0;
    while (x) {
      if (x & 1) if (!(--b[k][best])) b[k].erase(best);
      x >>= 1; k++;
    }
    i++;
  }
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
    
  precompute();
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
