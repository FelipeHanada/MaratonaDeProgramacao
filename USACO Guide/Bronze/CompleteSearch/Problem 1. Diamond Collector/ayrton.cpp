#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  int v[n];

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v, v + n);

  int sets[n];
  fill_n(sets, n, 0);

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (abs(v[i] - v[j]) <= k) {
        sets[i]++;
      }
    }
  }

  int maximum = 0;

  for (int i = 0; i < n; i++) {
    maximum = max(sets[i], maximum);
  }

  cout << maximum;

  return 0;
}