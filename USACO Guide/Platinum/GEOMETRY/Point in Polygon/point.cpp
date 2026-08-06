#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define point pair<ll, ll>
#define X first
#define Y second
istream& operator>>(istream& in, point& p) {
    in >> p.X >> p.Y;
    return in;
}
point sub(point a, point b) { return { a.X - b.X, a.Y - b.Y }; }
point rot(point a) { return { a.Y, -a.X }; }
ll dot(point a, point b) { return a.X*b.X + a.Y*b.Y; }


int main() {
    int n, m; cin >> n >> m;
    vector<point> points(n);
    for (int i=0; i<n; i++) cin >> points[i];

    while (m--) {
        point p; cin >> p;

        int cnt = 0;
        bool boundary = 0;
        for (int i=0; !boundary && i<n; i++) {
            point a = points[i], b = points[(i+1)%n];

            boundary = p.X >= min(a.X, b.X)
                        && p.X <= max(a.X, b.X)
                        && p.Y >= min(a.Y, b.Y)
                        && p.Y <= max(a.Y, b.Y)
                        && (dot(sub(b, a), rot(sub(p, a))) == 0);

            if (p.Y>=min(a.Y, b.Y) && p.Y<max(a.Y, b.Y)) {
                /*
                ray intersects segment at point (x, p.Y) where
                x = a.X + (b.X - a.X)/(b.Y - a.Y) * (p.Y - a.Y)
                if x > p.X we count the collision
                that is, if
                    a.X + (b.X - a.X)/(b.Y - a.Y) * (p.Y - a.Y) > p.X
                    (b.X - a.X)/(b.Y - a.Y)*(p.Y - a.Y) > p.X - a.X
                */

                if (p.Y == min(a.Y, b.Y)) {
                    if ((p.Y == a.Y && p.X < a.X) || (p.Y == b.Y && p.X < b.X)) {
                        cnt += p.Y < max(a.Y, b.Y);
                    }
                } else if (p.Y - a.Y > 0) {
                    cnt += (b.X - a.X)*(p.Y - a.Y) >= (p.X - a.X)*(b.Y - a.Y);
                } else {
                    cnt += (b.X - a.X)*(p.Y - a.Y) <= (p.X - a.X)*(b.Y - a.Y);
                }
            }
        }

        if (boundary) {
            cout << "BOUNDARY\n";
        } else if (cnt & 1) {
            cout << "INSIDE\n";
        } else {
            cout << "OUTSIDE\n";
        }
    }
}