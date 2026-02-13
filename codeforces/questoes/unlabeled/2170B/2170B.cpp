#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    ll sum = 0, cnt = 0;
    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      if (x) cnt++;
      sum += x;
    }

    cout << min(cnt, sum - n + 1) << '\n';
  }
}

