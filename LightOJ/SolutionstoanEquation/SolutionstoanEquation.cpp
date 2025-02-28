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

bool anysol(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
    g = gcd_ext(abs(a), abs(b), x, y);
    if (c % g)
        return false;
    
    x *= c / g;
    y *= c / g;

    if (a < 0) x = -x;
    if (b < 0) y = -y;

    return true;
}

void shiftsol(ll a, ll b, ll &x, ll &y, ll k) {
    x += b * k;
    y -= a * k;
}

ll countsol(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {
    ll x, y, g;
    if (!anysol(a, b, c, x, y, g))
        return 0;

    a /= g; b /= g;

    ll sign_a = (a > 0) ? +1 : -1;
    ll sign_b = (b > 0) ? +1 : -1;

    ll lx1, rx1, lx2, rx2;

    shiftsol(a, b, x, y, (minx - x) / b);
    if (x < minx)
        shiftsol(a, b, x, y, sign_b);
    if (x > maxx)
        return 0;
    lx1 = x;

    shiftsol(a, b, x, y, (maxx - x) / b);
    if (x > maxx)
        shiftsol(a, b, x, y, -sign_b);
    rx1 = x;

    shiftsol(a, b, x, y, (y - miny) / a);
    if (y < miny)
        shiftsol(a, b, x, y, -sign_a);
    if (y > maxy)
        return 0;
    lx2 = x;

    shiftsol(a, b, x, y, (y - maxy) / a);
    if (y > maxy)
        shiftsol(a, b, x, y, sign_a);
    rx2 = x;

    if (rx2 < lx2) swap(lx2, rx2);

    ll lx = max(lx1, lx2), rx = min(rx1, rx2);

    return (rx - lx) / abs(b) + 1;
}

ll solve(ll a, ll b, ll c, ll x1, ll x2, ll y1, ll y2) {
    return countsol(a, b, -c, x1, x2, y1, y2);
}

int main() {
    ll t;
    ll a, b, c, x1, x2, y1, y2;
    cin >> t;

    for (int i=0; i<t; i++) {
        cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
        cout << "Case " << i + 1 << ": ";
        cout << solve(a, b, c, x1, x2, y1, y2) << "\n";
    }
}
