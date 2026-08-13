#include <bits/stdc++.h>
using namespace std;


int main() {
  int n; cin >> n;
  map<int, int> cnt;
  for (int i=0; i<n; i++) {
    int x; cin >> x;
    cnt[x]++;
  }

  int big = 0;
  for (int i=1; i<=n; i++) {
    big = max(big, cnt[i]);
  }

  cout << n - big << '\n';
}