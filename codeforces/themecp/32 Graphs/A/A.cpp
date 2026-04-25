#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;

int main() { _
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    vector<bool> a(n, 0);
    for (int i=0; i<k; i++) {
        int x;
        cin >> x; x--;
        a[x] = 1;
    }

    priority_queue<pair<int,int>> pq;
    for (int i=0; i<n; i++) if (!a[i]) pq.push({0, i});
    vector<bool> seen(n, 0);
    int ans = -1;
    while (!pq.empty() && ans == -1) {
        auto [d, curr] = pq.top(); pq.pop();
        if (a[curr]) {
            ans = d;
            break;
        }
        seen[curr] = 1;
        for (auto [neighbor, w] : adj[curr]) {
            if (seen[neighbor]) continue;
            pq.push({d-w, neighbor});
        }
    }

    cout << ans << '\n';
}
