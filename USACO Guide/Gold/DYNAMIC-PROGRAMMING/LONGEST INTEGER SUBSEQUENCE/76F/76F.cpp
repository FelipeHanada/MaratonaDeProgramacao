#include <bits/stdc++.h>
using namespace std;


#define pii pair<int, int>
#define f first
#define s second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, v;
    cin >> n;
    vector<pii> points(n);
    for (int i=0; i<n; i++) {
        cin >> points[i].f >> points[i].s;
    }
    cin >> v;

    /*
    Let (xi,ti) and (xj,tj) be two events with ti<tj
    The tourist can only visit (xj,tj) given that he visited (xi,ti)
    iff. |xj-xi| <= |tj-ti|*V = (tj-ti)*V
    since (tj-ti)*V > 0 and therefore |(tj-ti)*V| >= |xj-xi|
    we have the following inequality -(tj-ti)*V <= xj-xi <= (tj-ti)*V
    rearranging terms:
        1) -(tj-ti)*V <= xj-xi  ===  xi + ti*V  <= xj + tj*V
        2) xj-xi <= (tj-ti)*V   ===  -xi + ti*V <= -xj + tj*V
    let (pi,qi) = (xi + ti*V, -xi + ti*V) for every event
        we can conclude that, if we visited (xi,ti), we can only visit (xj,tj)
            iff. (pi,qi) <= (pj,qj)
    Then the maximum amount of events that we can visit is given by
        the Longest non-decreasing Subsequence of pairs (pi,qi)
    */

    for (int i=0; i<n; i++) {
        points[i] = make_pair(-points[i].f + points[i].s * v, points[i].f + points[i].s * v);
    }

    sort(points.begin(), points.end());

    // run LIS for points
    vector<int> dp0, dpAny;
    dp0.push_back(INT32_MIN);
    dpAny.push_back(INT32_MIN);
    for (auto point : points) {
        auto it = upper_bound(dpAny.begin(), dpAny.end(), point.s);
        if (it == dpAny.end()) {
            dpAny.push_back(point.s);
        } else {
            *it = point.s;
        }

        if (point.f < 0 || point.s < 0) continue;
        it = upper_bound(dp0.begin(), dp0.end(), point.s);
        if (it == dp0.end()) {
            dp0.push_back(point.s);
        } else {
            *it = point.s;
        }
    }

    cout << dp0.size() - 1 << ' ' << dpAny.size() - 1 << '\n';
}
