#include <bits/stdc++.h>
using namespace std;


using ll = long long;

/*
a[i] * a[j] = j - i < n

a[i] * a[j] < n (para todo par válido)

a[i] * v + i < n  é mais restritiva do que a[i] * a[j] < n

se j > i, então 
    a[i] * a[j] = j - i
        j = a[i] * a[j] + i

*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i=0; i<n; i++) cin >> a[i];

        ll ans = 0, j;
        for (int i=0; i<n; i++) {
            // a[j] = v > a[i]

            for (int v=a[i]; (j = a[i] * v + i) < n; v++) {
                ans += a[j] == v;
            }

            for (int v=a[i]+1; (j = i - a[i] * v) >= 0; v++) {
                ans += a[j] == v;
            }
        }

        cout << ans << '\n';
    }
}