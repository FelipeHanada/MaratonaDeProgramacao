#include <bits/stdc++.h>
using namespace std;


struct tower {
    int x, y, d;
    int top() { return y - d; }
    int left() { return x - d; }
    int bottom() { return y + d; }
    int right() { return x + d; }

    bool point_in_radius(const pair<int, int> p) {
        return (abs(p.first - x) + abs(p.second - y) <= d);
    }

    set<pair<int, int>> intersection(tower &t) {
        if (t.point_in_radius({right(), y})) {
            // right corner
            for (int cx=t.left(); cx<=right(); cx++) {
                if (y + ())
            }

        } else if (t.point_in_radius({left(), y})) {
            // left corner
        } else if (t.point_in_radius({x, bottom()})) {
            // bottom corner
        } else {
            // top corner
        }
    }
};

int main() {
    int n; cin >> n;
    array<tower, 3> towers;
    for (int i=0; i<min(n, 3); i++) {
        int x, y, d;
        cin >> x >> y >> d;
        towers[i] = {x, y, d};
    }


}
