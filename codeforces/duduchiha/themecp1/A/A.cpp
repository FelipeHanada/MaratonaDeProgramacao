#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
  int tt;
  cin >> tt;

  while (tt--) {
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = 0;
    ll i = min(max(0LL, b-a+1), n); // b-i+1 = a iff. i = b-a+1

    ans += (b+1)*i - (1+i)*i/2;
    ans += (n-i)*a;

    cout << ans << '\n';
  }
}
