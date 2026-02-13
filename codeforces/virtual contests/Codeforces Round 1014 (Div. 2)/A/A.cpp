#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

/* we need to find max { gcd(a[i] + d, a[j] + d) } (for all a[i] < a[j])
 * since gcd(a[i]+d, a[j]+d) = gcd(a[i]+d, a[j]+d-a[i]-d) = gcd(a[i]+d, a[j]-a[i])
 * we have that max(a)-min(a) is an upper bound for maximum pleasure
 *
 * we can costructively obtain a d such that gcd(min(a)+d, max(a)+d) = max(a) - min(a)
 * let D = max(a) - min(a) = gcd(min(a)+d, max(a)+d)
 *     then D divides both min(a)+d and max(a)+d 
 *     if D divides min(a)+d, then min(a) + d = 0 mod D 
 *                            and  d = -min(a) mod D
 *     alternatively, since max(a) = min(a) + D 
 *                    for D to divide max(a)+d it suffices that 
 *                    max(a) + d = min(a) + D + d = 0 mod D 
 *                               d = -min(a) mod D 
 *     then we just have to prove that always exists a d >= 0 that satisfies d = -min(a) mod D 
 *          it can be d = D - min(a) mod D >= 0
 * 
 * therefore, we can always achieve max(a) - min(a)
 */

void solve() {
  int n;
  cin >> n;
  int small = INT32_MAX, big = INT32_MIN;
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    small = min(small, x);
    big = max(big, x);
  };

  cout << big - small << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
