#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, c, k;
        cin >> n >> c >> k;
        vector<ll> a(n);
        for (int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
    
        for (int i=0; i<n && c >= a[i]; i++) {
            ll flips = min(c - a[i], k);
            c += a[i] + flips;
            k -= flips;
        }
    
        cout << c << '\n';
    }
}
