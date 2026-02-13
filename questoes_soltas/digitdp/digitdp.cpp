#include <bits/stdc++.h>
using namespace std;

// problem: find the count of numbers in the [L, R] interval which have a sum of digits equal to X

int solve(int n, int x) {
  if (n == 1) return x < 10;

  int ans = 0;
  for (int i=0; i<10; i++) {
    ans += solve(n-1, x-i);
  }

  return ans;
}

int main() {
  int l, r, x;
  cin >> l >> r >> x;
  
  cout << solve((int)log10(r) + 1, x) << '\n';
}

