#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    set<int> cities, towers;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        cities.insert(a);
    }

    for (int i=0; i<m; i++) {
        int b;
        cin >> b;
        towers.insert(b);
    }

    int max_r = INT32_MIN;
    for (int city : cities) {
        int dist = INT32_MAX;
        auto tower = towers.upper_bound(city);
        if (tower != towers.end()) {
            dist = min(dist, *tower - city);
        }
        if (tower != towers.begin()) {
            tower--;
            dist = min(dist, city - *tower);
        }

        max_r = max(max_r, dist);
    }

    cout << max_r << endl;
}
