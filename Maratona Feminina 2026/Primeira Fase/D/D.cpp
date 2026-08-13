#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    ll g = a[0];
    for (int i=1; i<n; i++) g = __gcd(g, a[i]);

    ll ans = 0;
    for (int i=0; i<n; i++) ans += a[i] / g;
    cout << ans << '\n';
}