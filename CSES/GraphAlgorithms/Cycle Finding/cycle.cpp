#include <bits/stdc++.h>
using namespace std;


using ll = long long;
constexpr ll INF = INT64_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<array<int,3>> edges(m);
  for (int i=0; i<m; i++) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    edges[i][0]--;
    edges[i][1]--;
  }

  vector<pair<ll, int>> bf(n, {0, -1});
  for (int i=0; i<n-1; i++) {
    for (auto [a, b, x] : edges) {
      if (bf[a].first == INF) continue;
      bf[b] = min(bf[b], {bf[a].first + x, a});
    }
  }

  int s = -1;
  for (auto [a, b, x] : edges) {
    if (bf[a].first == INF) continue;
    if (bf[a].first + x < bf[b].first) {
      bf[b] = {bf[a].first + x, a};
      s = b;
      break;
    }
  }

  if (s == -1) {
    cout << "NO\n";
    return 0;
  }

  set<int> curr;
  while (!curr.count(s)) {
    curr.insert(s);
    s = bf[s].second;
  }

  cout << "YES\n";
  stack<int> cycle; cycle.push(s);
  for (int i = bf[s].second; i != s; i = bf[i].second) {
    cycle.push(i);
  } cycle.push(s);

  while (!cycle.empty()) {
    cout << cycle.top() + 1 << ' ';
    cycle.pop();
  }
  cout << '\n';
}

