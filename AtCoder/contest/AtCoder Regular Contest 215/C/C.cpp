#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<array<int,3>> a(n);

        priority_queue<pair<int,int>> px, py, pz;
        for (int i=0; i<n; i++) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            px.push({a[i][0], i});
            py.push({a[i][1], i});
            pz.push({a[i][2], i});
        }

        vector<bool> seen(n, 0);
        int minx, miny, minz;
        minx = min(a[py.top().second][0], a[pz.top().second][0]);
        miny = min(a[px.top().second][1], a[pz.top().second][1]);
        minz = min(a[px.top().second][2], a[py.top().second][2]);
        
        seen[px.top().second] = seen[py.top().second] = seen[pz.top().second] = 1;
        px.pop(); py.pop(); pz.pop();

        bool ok = 1;
        while (ok) {
            ok = 0;

            while (!px.empty() && px.top().first >= minx) {
                miny = min(miny, a[px.top().second][1]);
                minz = min(minz, a[px.top().second][2]);
                seen[px.top().second] = 1;
                px.pop();
                ok = 1;
            }

            while (!py.empty() && py.top().first >= miny) {
                minx = min(minx, a[py.top().second][0]);
                minz = min(minz, a[py.top().second][2]);
                seen[py.top().second] = 1;
                py.pop();
                ok = 1;
            }

            while (!pz.empty() && pz.top().first >= minz) {
                minx = min(minx, a[pz.top().second][0]);
                miny = min(miny, a[pz.top().second][1]);
                seen[pz.top().second] = 1;
                pz.pop();
                ok = 1;
            }
        }

        int ans = count(seen.begin(), seen.end(), 1);
        cout << ans << '\n';
    }
}
