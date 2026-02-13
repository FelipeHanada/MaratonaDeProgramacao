#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

/*
 * 0 -> 9
 * 1 -> 0
 * 2 -> 1
 * 3 -> 2
 *
 * digito vira (d-1+10) mod 10
 * dá pra ver pra cada dígito qual é a melhor solução
 */

void solve() {
  int n;
  cin >> n;

  vector<int> num;
  while (n) {
    num.push_back(n % 10);
    n /= 10;

    if (num.back() == 7) {
      cout << 0 << '\n';
      return;
    }
  }

  array<int,10> carry; fill(carry.begin(), carry.end(), 0);
  array<int,10> next_carry;
  array<int,10> curr;

  int ans = INT32_MAX;
  for (int i=0; i<=num.size(); i++) {
    if (i) {
      curr[0] = (i < num.size() ? num[i] : 0);
      for (int k=1; k<10; k++) { // k is the number of increments only on the previous digit
        for (int j=1; j<=k; j++) {
          curr[j] = curr[j-1] + carry[j];
          if (curr[j] > 9) curr[j] -= 10;
        }
        for (int j=k+1; j<10; j++) {
          curr[j] = curr[j-1] + carry[j] + 9;
          if (curr[j] > 9) curr[j] -= 10;
        }
        for (int j=0; j<10; j++) if (curr[j] == 7)
          ans = min(ans, j);
      }
    }

    curr[0] = (i < num.size() ? num[i] : 0);
    next_carry[0] = 0;
    for (int j=1; j<10; j++) {
      curr[j] = curr[j-1] + carry[j] + 9;
      next_carry[j] = 0;
      if (curr[j] > 9) {
        curr[j] -= 10;
        next_carry[j]++;
      }
    }
    for (int j=0; j<10; j++) if (curr[j] == 7)
      ans = min(ans, j);

    swap(carry, next_carry);
  }

  cout << ans << '\n';
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
