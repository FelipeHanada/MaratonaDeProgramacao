#include <bits/stdc++.h>
using namespace std;


using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<array<int,3>> edges(m);
  for (int i=0; i<m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--; b--;
    edges[i] = { a, b, w };
    adj[a].push_back(b);
  }

  vector<ll> score(n, INT64_MIN);
  score[0] = 0;
  for (int i=0; i<n-1; i++) {
    for (auto [a, b, w] : edges) if (score[a] != INT64_MIN) {
      score[b] = max(score[b], score[a] + w);
    }
  }

  set<int> s;
  for (auto [a, b, w] : edges) if (score[a] != INT64_MIN) {
    if (score[a] + w > score[b] ) {
      score[b] = score[a] + w;
      s.insert(a);
      s.insert(b);
    }
  }

  vector<bool> seen(n, 0);
  queue<int> bfs;
  for (int x : s) {
    seen[x] = 1;
    bfs.push(x);
  }
  while (!bfs.empty()) {
    auto curr = bfs.front(); bfs.pop();
    for (int neighbor : adj[curr]) {
      if (seen[neighbor]) continue;
      seen[neighbor] = 1;
      bfs.push(neighbor);
    }
  }

  if (seen[n-1]) {
    cout << "-1\n";
  } else {
    cout << score[n-1] << '\n';
  }
}

