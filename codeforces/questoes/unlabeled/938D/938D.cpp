#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y; ll w;
        cin >> x >> y >> w;
        x--; y--;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    priority_queue<pair<ll,int>> pq;
    for (int i=0; i<n; i++) pq.push({-a[i], i});
    vector<ll> ans(n, -1);

    while (!pq.empty()) {
        auto [cost, curr] = pq.top(); pq.pop();
        if (ans[curr] != -1) continue;
        ans[curr] = -cost;
        for (auto [neighbor, w] : adj[curr]) {
            pq.push({cost - 2*w, neighbor});
        }
    }

    for (int i=0; i<n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}