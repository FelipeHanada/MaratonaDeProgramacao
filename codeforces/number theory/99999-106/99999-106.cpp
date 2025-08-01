#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    x = 1; y = 0;
    ll x1 = 0, y1 = 1;
    while (b) {
        ll q = a / b;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a, b) = make_tuple(b, a - q * b);
    }
    return a;
}

bool find_any_solution(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
    g = extended_gcd(abs(a), abs(b), x, y);

    if (c % g)
        return false;

    x *= c / g;
    y *= c / g;

    if (a < 0) x *= -1;
    if (b < 0) y *= -1;

    return true;
}

void shift_solution(ll &x, ll &y, ll a, ll b, ll k) {
    x += k * b;
    y -= k * a;
}

ll n_solutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    if (a == 0 && b == 0) {
        if (c != 0)
            return 0;

        return (maxx - minx + 1) * (maxy - miny + 1);
    }

    ll g, x, y;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;

    if (a == 0) {
        if (y < miny || y > maxy)
            return 0;
        return maxx - minx + 1;
    }

    if (b == 0) {
        if (x < minx || x > maxx)
            return 0;
        return maxy - miny + 1;
    }
    
    a /= g;
    b /= g;

    ll sign_a = (a > 0) ? +1 : -1;
    ll sign_b = (b > 0) ? +1 : -1;

    ll lx1, rx1, lx2, rx2;
    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;  // there is no x that satisfies the x interval constraint
    lx1 = x;  // minimum x that satisfies the x interval constraint

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    rx1 = x;  // maximum x that satisfies the x interval constraint

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;  // there is no y that satisfies the y interval constraint
    lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    ll lx = max(lx1, lx2), rx = min(rx1, rx2);

    if (lx > rx)
        return 0;

    return (rx - lx) / abs(b) + 1;
}

int main() {
    ll a, b, c, x1, x2, y1, y2;
    cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;

    cout << n_solutions(a, b, -c, x1, x2, y1, y2) << "\n";
}
