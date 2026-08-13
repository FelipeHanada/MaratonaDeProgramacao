#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<pair<int,int>>> a(1000);
    for (int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        a[min(x/1000, 999)].push_back({ y, i });
    }

    for (int i=0; i<1000; i++) sort(a[i].begin(), a[i].end());

    vector<int> ans(n);
    int id = 0;
    for (int i=0; i<1000; i++) {
        if (i & 1) {
            for (int j=a[i].size()-1; j>=0; j--)
                ans[id++] = a[i][j].second;
        } else {
            for (int j=0; j<a[i].size(); j++)
                ans[id++] = a[i][j].second;
        }
    }

    for (int x : ans) cout << x + 1 << ' ';
    cout << '\n';
}

/*
let split the plane in sqrt(width) vertical rectangles
    that is, 10^3 rectangles of 10^3 x 10^6


we will make a run a path rectangle by rectangle

for a rectangle, we will path its points ordered by y
    upwards if its a odd rectangle
    downwards else

the worst path length is:
    1. 10^3*10^6            (upward/downward movement)
    2. (n-1) * 1000         (zig-zag pathing)
    3. (1000 - 1) * 2000    (rectangle transition)

path length <= 10^3 * 10^6 +  10^6 * 10^3 + 10^3 * 2*10^3
             = 10^9 + 10^9 + 2*10^6
             = 2*10^9 + 2*10^6 <= 2.5 * 10^9 its safe.
*/
