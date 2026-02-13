#include <bits/stdc++.h>
using namespace std;


#define ll long long

/*
since the least number of deals is made, we can take the ternary representation of x
and sum its componentes with its associate cost
*/

void solve() {
    int n;
    cin >> n;

    ll p=1;
    ll ans = 0;
    for (int i=0; n; i++) {
        ans += (n % 3) * (p*3 + i*p/3);
        n /= 3;
        p *= 3;
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}