#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> cow_coords;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        cow_coords.push_back(make_pair(x, y));
    }

    vector<set<int>> adj(n, set<int>());
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    vector<bool> seen(n, false);
    ll min_perimeter = INT64_MAX;
    for (int i=0; i<n; i++) {
        if (seen[i]) continue;

        tuple<int, int, int, int> fence_boundaries = {INT32_MAX, INT32_MAX, INT32_MIN, INT32_MIN};
        stack<int> dfs; dfs.emplace(i);
        seen[i] = true;

        while (dfs.size() > 0) {
            int curr = dfs.top(); dfs.pop();
            pair<int, int> cow_coord = cow_coords[curr];
            fence_boundaries = {
                min(get<0>(fence_boundaries), cow_coord.first),
                min(get<1>(fence_boundaries), cow_coord.second),
                max(get<2>(fence_boundaries), cow_coord.first),
                max(get<3>(fence_boundaries), cow_coord.second)
            };

            for (int x : adj[curr]) {
                if (!seen[x]) {
                    seen[x] = true;
                    dfs.emplace(x);
                }
            }
        }

        int dx = get<2>(fence_boundaries) - get<0>(fence_boundaries);
        int dy = get<3>(fence_boundaries) - get<1>(fence_boundaries);
        ll perimeter = 2 * (dx + dy);

        min_perimeter = min(min_perimeter, perimeter);
    }

    cout << min_perimeter << endl;
}
