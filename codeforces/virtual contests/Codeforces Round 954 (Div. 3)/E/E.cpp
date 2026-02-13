#include <bits/stdc++.h>
using namespace std;


#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    multiset<ll> ms;
    for (int i=0; i<n; i++) {
        ll x;
        cin >> x;
        if (ms.count(x)) {
            ms.extract(x);
        } else {
            ms.insert(x);
        }
    }


    /* for a pair p = a[i] and q = [n-i-1]
    min x + y such that p+x*k = q+y*k
        p-q = y*k-x*k = (y-x)*k
        min x + y = abs(p - q) iff. p-q is divisible by k
        that means p mod k = q mod k
    */

  
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}