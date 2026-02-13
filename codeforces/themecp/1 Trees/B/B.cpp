#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i=0; i<n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  queue<int> q;
  vector<int> s(n, 0);
  vector<int> deg(n, -1); deg[0]++;
  for (int i=0; i<n; i++) {
    deg[i] += adj[i].size();
    if (deg[i] == 0) {
      q.push(i);
      s[i] = 1;
    }
  }

  while (!q.empty()) {
    auto curr = q.front(); q.pop();
    for (int neighbor : adj[curr]) if (deg[neighbor]) {
      if (!(--deg[neighbor])) q.push(neighbor);
      s[neighbor] += s[curr];
    }
  }

  int queries;
  cin >> queries;
  while (queries--) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << (ll)s[x] * s[y] << '\n';
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
