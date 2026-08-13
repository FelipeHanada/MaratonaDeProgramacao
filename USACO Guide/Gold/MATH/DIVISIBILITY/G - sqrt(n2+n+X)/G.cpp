#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
find all n s.t. n^2 + n + x is a perfect square

n^2 + n + x = m^2
n^2 + n - m^2 = -x
m^2 - n^2 - n = x

since (m - n - 1/2)(m + n + 1/2) = m^2 - n^2 - n - 1/4

(m - n - 1/2)(m + n + 1/2) + 1/4 = x
(m - n - 1/2)(m + n + 1/2) = x - 1/4
4(m - n - 1/2)(m + n + 1/2) = 4x - 1
(2m - 2n - 1)(2m + 2n + 1) = 4x - 1

let A = (2m - 2n - 1), B = (2m + 2n + 1) and C = 4x - 1
we have AB = C
since A, B and C are all integers
    A,B divides C

let A = d for some divisor of C
    then dB = C => B = C/d

from the system of equations
    A = d       2m - 2n - 1 = d
    B = C/d     2m + 2n + 1 = C/d

we have
    4n + 2 = C/d - d
    4n = C/d - d - 2 (since n is an integer, the right side must be divisible by 4)
    n = (C/d - d - 2) / 4
*/

int main() {
    ll x; cin >> x;
    ll c = 4*x - 1;

    set<ll> ans;
    auto add = [&](ll d) {
        ll rh = c/d - d - 2;
        if (rh % 4) return;
        ans.insert(rh / 4);
    };

    ll d;
    for (d=1; d*d<abs(c); d++) if (!(c % d)) {
        add(d); add(-d);
        add(c/d); add(-c/d);
    }
    if (d * d == abs(c)) {
        add(d); add(-d);
    }

    cout << ans.size() << '\n';
    for (ll n : ans) {
        cout << n << ' ';
    }
    cout << '\n';
}