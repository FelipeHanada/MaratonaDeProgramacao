#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int n, m, Y;
    cin >> n >> m >> Y;
    vector<vector<pair<int, ll>>> adj(n+1);
    for (int i=0; i<m; i++) {
        int x, y; ll w;
        cin >> x >> y >> w;
        x--; y--;
        adj[x].push_back(make_pair(y, w));
        adj[y].push_back(make_pair(x, w));
    }
    vector<ll> X(n);
    for (int i=0; i<n; i++) {
        cin >> X[i];
    }

    for (int i=0; i<n; i++) {
        adj[i].push_back(make_pair(n, X[i] + Y));
        adj[n].push_back(make_pair(i, X[i]));
    }

    vector<ll> dist(n+1, INT64_MAX);
    priority_queue<pair<int, int>> pq;
    dist[0] = 0; pq.push({ 0, 0 });
    while (!pq.empty()) {
        auto [ minusd, curr ] = pq.top(); pq.pop();
        if (-minusd > dist[curr]) continue;

        for (auto [ neighbor, w ] : adj[curr]) {
            ll d = dist[curr] + w;
            if (d < dist[neighbor]) {
                dist[neighbor] = d;
                pq.push({ -d, neighbor });
            }
        }
    }

    for (int i=1; i<n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
}
