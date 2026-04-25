#include <bits/stdc++.h>
using namespace std;

#define _ ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using ll = long long;


int main() { _
    int n;
    cin >> n; n--;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    vector<array<int,3>> edges;

    for (int i=0; i<n; i++) {
        if (i + a[i] < n) edges.push_back({2*(i+a[i]), i, a[i]});
        else edges.push_back({2*n, i, a[i]});
    }
    for (int i=n; i<2*n; i++) {
        if (i - a[i-n] >= 0) edges.push_back({i-n - a[i-n], i, a[i-n]});
        else edges.push_back({2*n, i, a[i-1]});
    }

    vector<ll> dist(2*n+1, INT64_MAX);
    dist[2*n] = 0;
    for (int i=0; i<2*n; i++) {
        for (auto [x, y, w] : edges) {
            if (dist[x] == INT64_MAX) continue;
            dist[y] = min(dist[y], dist[x] - w);
        }
    }

    vector<ll> ans(n);
    for (int i=n; i<2*n; i++) ans[i] = -dist[i] + i - n;
    for (int i=0; i<2*n; i++) {
        for (auto [x, y, w] : edges) {
            if (dist[x] == INT64_MAX) continue;
            if (dist[x] - w < dist[y] && y >= n && y < 2*n) ans[y] = -1;
            dist[y] = min(dist[y], dist[x] - w);
        }
    }

    for (int i=0; i<n; i++) {
        cout << ans[i] << '\n';
    }
}
