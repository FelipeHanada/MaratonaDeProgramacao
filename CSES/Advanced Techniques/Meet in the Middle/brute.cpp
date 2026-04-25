#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    ll ans = 0;
    for (ll i=0; i<(1LL<<n); i++) {
        ll sum = 0;
        for (int j=0; j<n; j++) if (i & (1 << j)) {
            sum += a[j];
        }

        if (sum == x) ans++;
    }

    cout << ans << '\n';
}