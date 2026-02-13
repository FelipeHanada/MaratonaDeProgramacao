#include <bits/stdc++.h>
using namespace std;


/*
the answer is the number of perfect squares
between f(c, c) <= X <= d

*/

#define ll long long

void solve() {
    ll c, d;
    cin >> c >> d;

    ll cc = c;
    for (int i=c; i; i /= 10) cc *= 10;
    ll lb = c + cc;
    
    cc = c;
    for (ll i=c+d; i; i/= 10) cc *= 10;
    ll ub = cc+c+d;
    // we need to find the number of perfect squares in [lb*lb, ub*ub] with prefix c

    int ans = 0;
    lb = ceil(sqrt(lb));
    for (ll i = lb; i*i<=ub; i++) {
        ll curr = i*i;
        ll rest = 0;
        ll p = 1;
        bool lzero = false;
        while (curr > c) {
            rest += p * (curr % 10);
            lzero = !(curr % 10);
            curr /= 10;
            p *= 10;
        }
        if (curr == c && c+d >= rest && !lzero) ans++;
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