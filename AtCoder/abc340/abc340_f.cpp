#include <bits/stdc++.h>
using namespace std;

#define ll long long


ll gcd_ext(ll a, ll b, ll &x, ll &y) {
    x = 1; y = 0;
    ll x1 = 0, y1 = 1;

    while (b) {
        ll q = a / b;
        tie(a, b) = make_tuple(b, a - q * b);
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
    }

    return a;
}

bool any_sol(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
    g = gcd_ext(abs(a), abs(b), x, y);

    if (c % g)
        return false;

    x *= c / g;
    y *= c / g;

    if (a < 0) x = -x;
    if (b < 0) y = -y;
    
    return true;
}

int main() {
    ll x, y;
    cin >> x >> y;

    ll a, b, g;
    if (any_sol(x, -y, 2, b, a, g)) {
        cout << a << " " << b << "\n";
    } else {
        cout << -1 << "\n";
    }

    // given X and Y
    // find (A, B) such that the area of a triangle with vertices on
    // (0, 0) (X, Y) (A, B) on the plane is 1
    // det( 0 0 1
    //      x y 1 
    //      a b 1 ) = +- 2
    // xb - ay = +- 1
}
