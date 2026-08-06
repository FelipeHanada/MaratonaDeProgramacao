#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define point pair<ll, ll>
#define X first
#define Y second
point add(point a, point b) { return { a.X + b.X, a.Y + b.Y }; }
point sub(point a, point b) { return { a.X - b.X, a.Y - b.Y }; }
point mult(point a, int k) { return { a.X * k, a.Y * k }; }
ll dot(point a, point b) { return a.X*b.X + a.Y*b.Y; }
point rot90(point a) { return { a.Y, -a.X }; }


int main() {
    int tt; cin >> tt;
    while (tt--) {
        point a, b, c;
        cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y;

        ll d = dot(sub(b, a), rot90(sub(c, a)));
        if (d < 0) {
            cout << "RIGHT\n";
        } else if (d > 0) {
            cout << "LEFT\n";
        } else {
            cout << "TOUCH\n";
        }
    }
}