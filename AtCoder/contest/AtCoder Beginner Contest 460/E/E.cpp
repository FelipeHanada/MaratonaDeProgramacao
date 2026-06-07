#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
constexpr ll md = 998244353;
ll add(ll a, ll b, ll m) { return ((a%m) + (b%m)) % m; }
ll sub(ll a, ll b, ll m) { return ((a%m) - (b%m) + m) % m; }
ll mult(ll a, ll b, ll m) { return ((ll)a * b) % m; }
ll add(ll a, ll b) { return add(a, b, md); }
ll sub(ll a, ll b) { return sub(a, b, md); }
ll mult(ll a, ll b) { return mult(a, b, md); }


signed main() { _
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n, m;
        cin >> n >> m;

        ll digitn = 0;
        {
            ll x = n;
            while (x) {
                digitn++;
                x /= 10;
            }
        }

        vector<ll> mod10k(digitn+1); // 10^k mod M
        mod10k[0] = 1;
        for (ll i=1; i<mod10k.size(); i++)
            mod10k[i] = mult(mod10k[i-1], 10, m);

        ll ans = 0, p = 10, q = 1;
        for (ll i=1; i<digitn; i++) {
            ll g = gcd<ll>(sub(mod10k[i], 1, m), m);
            ll candx = (n/(m/g)) % md;
            ll candy = sub(p, q);

            ans = add(ans, mult(candy, candx));
            p = mult(p, 10);
            q = mult(q, 10);
        }

        {
            ll g = gcd<ll>(sub(mod10k[digitn], 1, m), m);
            ll candx = (n/(m/g)) % md;
            ll candy = add(sub(n % md, q), 1);

            ans = add(ans, mult(candy, candx));
        }

        cout << ans << '\n';
    }
}


/*
4
3 2

1 2 3

11 mod 2 = 1        1 + 1 mod 2 = 0
12 mod 2 = 0        1 + 2 mod 2 = 1
13 mod 2 = 1        1 + 3 mod 2 = 0
21 mod 2 = 1        2 + 1 mod 2 = 1         O
22 mod 2 = 0        2 + 2 mod 2 = 0         O
23 mod 2 = 1        2 + 3 mod 2 = 1         O
31 mod 2 = 1        3 + 1 mod 2 = 0
32 mod 2 = 0        3 + 2 mod 2 = 1
33 mod 2 = 1        3 + 3 mod 2 = 0


x * 10^k + y = x + y mod m
x * 10^k = x mod m

se 10^k = 1 mod m => N-1 possíveis x's
c.c. x = 0 mod m => floor(n/m)

*/