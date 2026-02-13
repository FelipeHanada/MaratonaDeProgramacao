#include <bits/stdc++.h>
using namespace std;

#define ll long long


void solve() {
    int n, m, l, s, t;
    cin >> n >> m >> l >> s >> t;
    vector<vector<array<int,2>>> adj(n);
    for (int i=0; i<m; i++) {
      int x, y, c;
      cin >> x >> y >> c;
      x--; y--;
      adj[x].push_back({y, c});
    }

    set<int> ans;
    queue<array<int,3>> bfs;
    bfs.push({0, 0, 0});
    while (!bfs.empty()) {
      auto [curr, cost, edges] = bfs.front();
      bfs.pop();

      if (edges == l) {
        if (cost >= s && cost <= t) ans.insert(curr);
        continue;
      }

      for (auto [neighbor, c] : adj[curr]) {
        if (cost + c > t) continue;
        bfs.push({neighbor, cost+c, edges+1});
      }
    }

    for (int x : ans) {
      cout << x + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();    
    return 0;
}
