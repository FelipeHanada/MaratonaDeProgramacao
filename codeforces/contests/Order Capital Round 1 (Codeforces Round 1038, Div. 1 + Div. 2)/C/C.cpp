#include <bits/stdc++.h>
using namespace std;


/*
let a optimal solution for each dimension divide the points in
    Xl, Xr and Yl, Yr.

An optimal solution for 2D will be such that each pair of points P1, P2
    satisfies
    P1 in Xl and Yl and P2 in Xr and Yr
    P1 in Xl and Yr and P2 in Xr and Yl

let |Xl and Yl| = a
    |Xr and Yr| = b
    |Xl and Yr| = c
    |Xr and Yl| = d

since all sets are disjoint two by two we have that
|Xl and Yl OR Xl and Yr| = a + c = |Xl| = n/2
|Xr and Yr OR Xr and Yl| = b + d = |Xr| = n/2
|Xl and Yl OR Xr and Yl| = a + d = |Xl| = n/2
|Xr and Yr OR Xl and Yr| = b + c = |Yr| = n/2

from that: a = b and c = d
then its always possible to make this optimal solution
*/

void solve() {
    int n;
    cin >> n;
    set<int> xl, xr, yl, yr;
    vector<pair<int, int>> points(n);
    vector<int> xsort(n), ysort(n);
    iota(xsort.begin(), xsort.end(), 0);
    iota(ysort.begin(), ysort.end(), 0);
    for (int i=0; i<n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    sort(xsort.begin(), xsort.end(), [&](int &a, int &b) { return points[a].first < points[b].first; });
    sort(ysort.begin(), ysort.end(), [&](int &a, int &b) { return points[a].second < points[b].second; });

    for (int i=0; i<n/2; i++) xl.insert(xsort[i]);
    for (int i=n/2; i<n; i++) xr.insert(xsort[i]);
    for (int i=0; i<n/2; i++) yl.insert(ysort[i]);
    for (int i=n/2; i<n; i++) yr.insert(ysort[i]);

    set<int> xlyl, xlyr, xryl, xryr;
    set_intersection(xl.begin(), xl.end(), yl.begin(), yl.end(), inserter(xlyl, xlyl.begin()));
    set_intersection(xl.begin(), xl.end(), yr.begin(), yr.end(), inserter(xlyr, xlyr.begin()));
    set_intersection(xr.begin(), xr.end(), yl.begin(), yl.end(), inserter(xryl, xryl.begin()));
    set_intersection(xr.begin(), xr.end(), yr.begin(), yr.end(), inserter(xryr, xryr.begin()));

    for (auto i=xlyl.begin(), j=xryr.begin(); i!=xlyl.end(); i++, j++) {
        cout << *i + 1 << ' ' << *j + 1 << '\n';
    }
    for (auto i=xlyr.begin(), j=xryl.begin(); i!=xlyr.end(); i++, j++) {
        cout << *i + 1 << ' ' << *j + 1 << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
