#include <bits/stdc++.h>
using namespace std;


/* for each command x, suppose that the probability of the robot be in pos i is P 
 * I) x = i 
 *    chance of being in i: P*0.5 + 0.5 = 0.5 (P + 1)
 *    expected: P*0.5*x
 * II) x != i
 *    chance of being in i: P*0.5
 *    expected: P*0.5*x
 */

#define ll long long
constexpr int mod = 1e9+7;
constexpr int inv2 = (mod+1)/2;
int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(q);
  for (int i=0; i<q; i++) cin >> a[i];

  vector<int> prefix(q+1), pow2(q+1), powinv2(q+1);
  prefix[0] = 0; pow2[0] = 1; powinv2[0] = 1;
  int pinv2 = 1;
  for (int i=1; i<=q; i++) {
    prefix[i] = (prefix[i-1] + (ll)a[i-1] * powinv2[i-1]) % mod;
    pow2[i] = ((ll)pow2[i-1] * 2) % mod;
    powinv2[i] = ((ll)powinv2[i-1] * inv2) % mod;
  }

  vector<vector<int>> ops(n+1);
  for (int i=0; i<q; i++) ops[a[i]].push_back(i+1);

  vector<int> ans(n+1, 0);
  vector<int> p(n+1, 0);
  p[1] = 1;
  for (int i=1; i<=n; i++) {
    int last = 0;
    for (int j : ops[i]) {
      int sum = ((ll)((ll)(((prefix[j-1] - prefix[last])%mod+mod)%mod) * pow2[last])%mod * inv2) % mod; 
      ans[i] = (ans[i] + (ll)p[i] * sum) % mod;
      p[i] = ((ll)p[i] * powinv2[j-last-1]) % mod;

      ans[i] = (ans[i] + (ll)(((ll)p[i] * inv2)%mod) * i) % mod;
      p[i] = ((ll)inv2 * (p[i] + 1)) % mod;

      last = j;
    }

    int j = q + 1;
    int sum = ((ll)((ll)(((prefix[j-1] - prefix[last])%mod+mod)%mod) * pow2[last])%mod * inv2) % mod; 
    ans[i] = (ans[i] + (ll)p[i] * sum) % mod;
  }

  for (int i=1; i<=n; i++) {
    cout << ans[i] << '\n';
  }
}
