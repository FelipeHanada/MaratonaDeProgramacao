#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = 2e5;
int st[25][MAX_N];


int flog2(int x) {
  return __builtin_clz(1) - __builtin_clz(x);
}

int main() {
  int n, q;
  cin >> n >> q;
  for (int i=0; i<n; i++) {
    cin >> st[0][i];
  }

  for (int j=1; j<=flog2(n); j++) {
    for (int i=0; i<=n-(1<<j); i++) {
      st[j][i] = min(st[j-1][i], st[j-1][i+(1<<(j-1))]);
    }
  }

  while (q--) {
    int a, b;
    cin >> a >> b;

    int size = flog2(b-a+1);
    cout << min(st[size][a-1], st[size][b-(1<<size)]) << '\n';
  }
}
