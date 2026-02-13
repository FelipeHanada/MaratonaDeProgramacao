#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  int small = INT32_MAX;
  while (a.size()) {
    if (a.back() > small) {
      // a.back must be splitted
      while (a.back()) {
        if (a.back() % 10 > small) {
          cout << "NO\n";
          return;
        } else {
          small = a.back() % 10;
          a.back() /= 10;
        }
      }
    } else {
      small = a.back();
    }
    a.pop_back();
  }

  cout << "YES\n";
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
