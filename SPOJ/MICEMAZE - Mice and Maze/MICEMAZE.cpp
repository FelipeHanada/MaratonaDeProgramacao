#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 100;
int n, e, t, m;
int adj[MAX_N][MAX_N];
bool seen[MAX_N];
int ans;

int main() {
    cin >> n >> e >> t >> m;
    
    for (int i=0; i<n; i++)
        fill_n(adj[i], n, -1);
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a-1][b-1] = c;
    }


    fill_n(seen, n, false);
    set<pair<int, int>> pq;
    pq.insert({ 0, e-1 });
    while (!pq.empty()) {
        auto [ d, curr ] = *(pq.begin()); pq.erase(pq.begin());
        if (seen[curr] || d > t) continue;
        seen[curr] = true; ans++;

        for (int i=0; i<n; i++) {
            if (adj[i][curr] < 0) continue;

            pq.emplace(pair<int, int>{ d + adj[i][curr], i });
        }
    }

    cout << ans << "\n";
}
