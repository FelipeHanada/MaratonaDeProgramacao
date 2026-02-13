#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    deque<int> p(n);
    for (int i=0; i<n; i++) {
        cin >> p[i];
        p[i]--;
    }
    deque<deque<int>> adj(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    deque<int> ans(k, -1);
    queue<pair<int, int>> bfs;
    deque<bool> seen(n, false);
    ans[p[0]] = 0;
    bfs.push({0, 0});
    seen[0] = true;
    while (!bfs.empty()) {
        auto [curr, d] = bfs.front();
        bfs.pop();
        for (int neighbor : adj[curr]) {
            if (seen[neighbor]) continue;
            seen[neighbor] = true;
            ans[p[neighbor]] = max(ans[p[neighbor]], d+1);
            bfs.push({neighbor, d+1});
        }
    }

    for (int i=0; i<k; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}