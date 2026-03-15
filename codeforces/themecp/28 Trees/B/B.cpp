#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

constexpr int md = int(1e9)+7;

int mult(int a, int b) {
  return ((ll)a * b) % md;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
  int n;
  cin >> n;
  vector<vector<int>> childs(n);
  for (int i=1; i<n; i++) {
    int p;
    cin >> p;
    p--;
    childs[p].push_back(i);
  }

  queue<pair<int, int>> bfs;
  bfs.push({0, 0});
  vector<int> dist(n, 0);
  while (!bfs.empty()) {
    auto [ curr, d ] = bfs.front(); bfs.pop();
    dist[d] = 1 - dist[d];

    for (int child : childs[curr]) {
      bfs.push({ child, d + 1 });
    }
  }

  int ans = 0;
  for (int i=0; i<n; i++) ans += dist[i];
  cout << ans << '\n';
}
