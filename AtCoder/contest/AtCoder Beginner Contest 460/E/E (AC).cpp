#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll md = 998244353;
inline ll add(ll a, ll b, ll m) { return ((a%m) + (b%m)) % m; }
inline ll sub(ll a, ll b, ll m) { return (((a%m) - (b%m))%m + m) % m; }
inline ll mult(ll a, ll b, ll m) { return (ll(a%m) * (b%m)) % m; }
inline ll add(ll a, ll b) { return add(a, b, md); }
inline ll sub(ll a, ll b) { return sub(a, b, md); }
inline ll mult(ll a, ll b) { return mult(a, b, md); }

/*
x * 10^d + y = x + y mod M
x * 10^d = x mod M
x * 10^d - x = 0 mod M
x * (10^d - 1) = 0 mod M

all the solutions satisfy M | (x * (10^d - 1))

let g = gcd(M, 10^d - 1), a = M/g and b = (10^d - 1)/g
we have (g * a) | (x * g * b)
    then a | (x * b)

since we took g as the gcd a and b are coprime
by the Euclid's Lemma, a | x,
    that is x = 0 mod a = 0 mod M/g

therefore, there are N/(M/g) solutions for this congruence
*/


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, m;
        cin >> n >> m;

        int d = 0;
        for (ll i = n; i; i /= 10) d++;

        ll ans = 0;
        ll d10 = 10;
        ll p = 10, q = 1;
        for (int i=0; i<d-1; i++) {
            ll g = gcd(m, sub(d10, 1, m));
            ll x = n/(m/g);
            ll y = sub(p, q);
            ans = add(ans, mult(x, y));

            d10 = mult(d10, 10, m);
            p = mult(p, 10);
            q = mult(q, 10);
        }

        ll g = gcd(m, sub(d10, 1, m));
        ll x = n/(m/g);
        ll y = add(sub(n, q), 1);
        ans = add(ans, mult(x, y));

        cout << ans << '\n';
    }
}
