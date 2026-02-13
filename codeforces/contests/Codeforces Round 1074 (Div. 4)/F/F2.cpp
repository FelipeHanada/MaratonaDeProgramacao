#include <bits/stdc++.h>
using namespace std;


constexpr int MAX_N = (1<<18);
int prefix[MAX_N+1];

int solve(int i, int v, int l, int r) {
  if (r - l == 1) return 0;
  int mid = (l + r) / 2;
  
  int ans = 0;
  int left = prefix[mid] ^ prefix[l],
      right = prefix[r] ^ prefix[mid];
  if (i < mid) {
    left ^= v ^ prefix[i+1] ^ prefix[i];
    if (left < right) ans += r - mid;
    ans += solve(i, v, l, mid);
  } else {
    right ^= v ^ prefix[i+1] ^ prefix[i];
    if (left >= right) ans += mid - l;
    ans += solve(i, v, mid, r);
  }
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    n = 1<<n;
    prefix[0] = 0;
    for (int i=1; i<=n; i++) {
      cin >> prefix[i];
      prefix[i] ^= prefix[i-1];
    }

    while (q--) {
      int b, c;
      cin >> b >> c;
      b--;
      cout << solve(b, c, 0, n) << '\n';
    }
  }
}
