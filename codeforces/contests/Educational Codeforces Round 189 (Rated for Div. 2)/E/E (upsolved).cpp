#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, r;
    cin >> n >> r;
    vector<pair<int, int>> points(n);
    for (int i=0; i<n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end());

    /*[
    let the lattice becomes at (x0, y0)
    the center of each circle will be given as
        cx(x, y) = x0 + 2r * x + (y mod 2)r
        cy(x, y) = y0 + sqrt(3)r * y

    since cx and cy need to be integers,
        it suffices to take sqrt(3)r as ceil(sqrt(3)r)
    */

    auto seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    uniform_int_distribution<int> dist(-r, r);
    int x0 = dist(rng), y0 = dist(rng);
    int w = 2 * r, h = ceil(sqrt(3) * r);

    set<pair<int, int>> ans;
    for (auto [px, py] : points) {
        int y = (py - y0) / h;
        int x = (px - x0 - (y % 2) * r) / w;

        for (int i=x-2; i<=x+2; i++) {
            for (int j=y-2; j<=y+2; j++) {
                // checks if circle centered in (cx(i, j), cy(i, j))
                // contains this point, if so, it belongs to ans

                int cx = x0 + w*i + ((j%2+2)%2)*r,
                    cy = y0 + h*j;
                
                int dx = abs(px - cx), dy = abs(py - cy);
                if (dx*dx + dy*dy <= r*r) ans.insert(make_pair(cx, cy));
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto [cx, cy] : ans) {
        cout << cx << ' ' << cy << '\n';
    }
}