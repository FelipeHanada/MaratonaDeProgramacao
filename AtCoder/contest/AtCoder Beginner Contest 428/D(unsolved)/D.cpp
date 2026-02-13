#include <bits/stdc++.h>
using namespace std;


#define ll long long


ll fsqrt(ll x) {
    ll y = sqrt(x);
    while (y*y > x) y--;
    while ((y+1)*(y+1) <= x) y++;
    return y;
}

void solve() {
    ll C, D;
    cin >> C >> D;

    /*
    If C+x has d digits, then x is such that
    1. 0 <= x <= D
    2. 10^(d-1) <= C+x <= 10^d-1
         10^(d-1) - C <= x <= 10^d-1 - C
    let L = max(0, 10^(d-1)-C)
        R = min(D, 10^d-1-C)
    therefore x should lie under [L, R]

    Since C+x has d digits, f(C, C+x) = C*10^d + C+x
        in this case we may compute the number of perfect squares
            inside the the interval [f(C, C+L), f(C, C+R)] = [C*10^d+C+L, C*10^d+C+R] (if L <= R)
        this can be easily computed as sqrt(C*10^d+C+R) - sqrt(C*10^d+C+L-1)
    */

    ll ans = 0;
    ll cx_min = 1, cx_max = 9, shift = 10;
    while (cx_min <= C + D) {
        ll l = max(C, cx_min), r = min(C + D, cx_max);

        if (l <= r) {
            ans += fsqrt(C*shift+r) - fsqrt(C*shift+l-1);
        }

        shift *= 10;
        cx_min *= 10;
        cx_max  = (cx_max+1)*10-1;
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
