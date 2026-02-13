#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n*2, vector<pair<int, int>>());
    int a, b, c;
    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        adj[a-1].push_back(make_pair(b-1, c));
        adj[a-1].push_back(make_pair(n+b-1, c/2));
        adj[n+a-1].push_back(make_pair(n+b-1, c));
    }

    // running dijkstra
    vector<ll> dist(2*n, INT64_MAX >> 1);
    priority_queue<pair<ll, int>> pq;
    vector<bool> seen(2*n, false);

    dist[0] = 0;
    pq.emplace(make_pair(0, 0));
    while (!pq.empty()) {
        auto [d, curr] = pq.top();
        pq.pop();
        if (seen[curr]) continue;
        seen[curr] = true;

        for (auto [neighbor, c] : adj[curr]) {
            if (dist[curr] + c < dist[neighbor]) {
                dist[neighbor] = dist[curr] + c;
                pq.emplace(make_pair(d - c, neighbor));
            }
        }
    }

    cout << dist[2*n-1] << '\n';
}
