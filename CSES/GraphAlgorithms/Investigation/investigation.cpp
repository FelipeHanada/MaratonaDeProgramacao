#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n);
    for (int i=0; i<m; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        adj[u].push_back({ v, w });
    }

    vector<ll> min_price(n, INT64_MAX),
                n_routes(n, 0),
                min_size(n, INT64_MAX),
                max_size(n, INT64_MIN);
    min_price[0] = 0;
    n_routes[0] = 1;
    min_size[0] = 0;
    max_size[0] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({ 0, 0 });
    vector<bool> seen(n, 0);
    while (!pq.empty()) {
        auto [ d, curr ] = pq.top(); pq.pop();
        d = -d;

        if (d > min_price[curr]) continue;
        if (seen[curr]) continue;
        seen[curr] = 1;

        for (auto [ neighbor, w ] : adj[curr]) {
            if (d + w < min_price[neighbor]) {
                min_price[neighbor] = d + w;
                n_routes[neighbor] = n_routes[curr];
                min_size[neighbor] = min_size[curr] + 1;
                max_size[neighbor] = max_size[curr] + 1;
            } else if (d + w == min_price[neighbor]) {
                n_routes[neighbor] = (n_routes[neighbor] + n_routes[curr]) % (int(1e9)+7);
                min_size[neighbor] = min(min_size[neighbor], min_size[curr] + 1);
                max_size[neighbor] = max(max_size[neighbor], max_size[curr] + 1);
            } else continue;

            pq.push({ -(d+w), neighbor });
        }
    }

    cout << min_price[n-1] << ' '
         << n_routes[n-1] << ' '
         << min_size[n-1] << ' '
         << max_size[n-1] << '\n';
}