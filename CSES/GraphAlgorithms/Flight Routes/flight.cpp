#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> adj(n);
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({ b, c });
    }

    vector<priority_queue<ll>> best(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    best[0].push(0);
    pq.push({ 0, 0 });
    while (!pq.empty()) {
        auto [d, curr] = pq.top(); pq.pop();

        if (d > best[curr].top()) continue;
        for (auto [neighbor, w] : adj[curr]) {
            ll dd = d + w;
            if (best[neighbor].size() < k) {
                best[neighbor].push(dd);
                pq.push({ dd, neighbor });
            } else if (dd < best[neighbor].top()) {
                best[neighbor].pop();
                best[neighbor].push(dd);
                pq.push({ dd, neighbor });
            }
        }
    }

    vector<ll> ans(k);
    for (int i=0; i<k; i++) {
        ans[i] = best[n-1].top();
        best[n-1].pop();
    }

    for (int i=k-1; i>=0; i--) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
