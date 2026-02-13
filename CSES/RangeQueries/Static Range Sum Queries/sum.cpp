#include <bits/stdc++.h>
using namespace std;


using ll = long long;
int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> prefix(n + 1);
  prefix[0] = 0;
  for (int i=1; i<=n; i++) {
    cin >> prefix[i];
    prefix[i] += prefix[i-1];
  }

  while (q--) {
    int a, b;
    cin >> a >> b; a--;
    cout << prefix[b] - prefix[a] << '\n';
  }
}
