#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr);



int main() {
    // ll N = 10;
    // for (ll b=1; b<=N; b++) {
    //     cout << "b = " << b << '\n';
    //     for (ll a=1; a<=N; a++){
    //         for (ll c=1; c<=N; c++){
    //             if (gcd(lcm(a, b), lcm(b, c)) == gcd(a, c)) {
    //                 cout << "(" << a << ", " << b << ", " << c << ")\n";
    //             }
    //         }        
    //     }

    // }

    ll tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;

        ll ans = 0;
        for (ll b=1; b<=n; b++) {
            ll cand = n/b;
            ans += cand * cand;
        }

        cout << ans << '\n';
    }
}

/*
gcd(lcm(a, b), lcm(b, c)) = gcd(a, c)

lcm(a, b) = a*b/gcd(a, b)

gcd(a  *  b/gcd(a, b), c  *  b/gcd(b, c)) = gcd(a, c)

b * gcd(a/gcd(a, b), c/gcd(b, c)) = gcd(a, c)

se b compartilha um divisor d com a e com c ao mesmo tempo então não tem como funcionar


*/