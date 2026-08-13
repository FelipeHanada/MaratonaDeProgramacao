#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define point pair<ll, ll>
#define X first
#define Y second
point add(point a, point b) { return { a.X + b.X, a.Y + b.Y }; }
point sub(point a, point b) { return { a.X - b.X, a.Y - b.Y }; } 
point rot(point a) { return { a.Y, -a.X }; }
ll dot(point a, point b) { return a.X*b.X + a.Y*b.Y; }
ll signal(ll k) {
    if (k > 0) return 1;
    else if (k < 0) return -1;
    else return 0;
}


int main() {
    int tt; cin >> tt;
    while (tt--) {
        point a, b, c, d;
        cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y >> d.X >> d.Y;

        if (
            min(a.X, b.X) > max(c.X, d.X)
            || max(a.X, b.X) < min(c.X, d.X)
            || min(a.Y, b.Y) > max(c.Y, d.Y)
            || max(a.Y, b.Y) < min(c.Y, d.Y)
        ) {
            cout << "NO\n";
        } else {
            ll dot1 = signal(dot(sub(b, a), rot(sub(c, a)))),
               dot2 = signal(dot(sub(b, a), rot(sub(d, a)))),
               dot3 = signal(dot(sub(d, c), rot(sub(a, c)))),
               dot4 = signal(dot(sub(d, c), rot(sub(b, c))));

            if (dot1 * dot2 > 0 || dot3 * dot4 > 0) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}
