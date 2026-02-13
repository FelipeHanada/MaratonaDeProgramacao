#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    int a, b, c;
    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        adj[a-1].push_back(make_pair(c, b-1));
    }

    vector<ll> dist(n, INT64_MAX);
    dist[0] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push(make_pair(0, 0));
    vector<bool> seen(n, false);
    while (!pq.empty()) {
        auto [d, curr] = pq.top(); pq.pop();
        if (seen[curr]) continue;
        seen[curr] = true;

        for (auto [c, neighbor] : adj[curr]) {
            if (dist[curr] + c < dist[neighbor]) {
                dist[neighbor] = dist[curr] + c;
                pq.emplace(make_pair(d - c, neighbor));
            }
        }
    }

    for (int i=0; i<n; i++) {
        cout << dist[i] << ' ';
    }
    cout << '\n';
}
