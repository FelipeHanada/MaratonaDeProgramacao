#include <bits/stdc++.h>
using namespace std;


using ll = long long;

constexpr int MOD = 1e9+7;

int exp(int a, int b, int m) {
  int p = a;
  int ans = 1;
  while (b) {
    if (b & 1) ans = ((ll)ans * p) % m;
    p = ((ll)p * p) % m;
    b >>= 1;
  }
  return ans;
}

/* IDEA: using Fermat's Little Theorem
 * a^(b^c) mod P (for P = 1e9+7)
 *
 * we can compute some k mod P such that
 *  a^k = a^(b^c) mod P
 * 
 * since P is prime, by Fermat's Little Theorem
 *  a^(P-1) = 1 mod P, then a^i = a^j mod P for every pair i = j mod P
 *  therefore, we can take k = b^c mod (P-1)
 *
 * both k = b^c mod (P-1)
 *  and a^k mod P
 * can be computed in O(logn) using binary exponentiation
 */

int main() {
  int n;
  cin >> n;

  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;

    cout << exp(a, exp(b, c, MOD-1), MOD) << '\n';
  }
}
