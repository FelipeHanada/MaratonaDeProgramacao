#include <bits/stdc++.h>
using namespace std;


int query(int i, int j) {
  cout << "? " << i+1 << ' ' << j+1 << '\n';
  fflush(stdout);
  int x;
  cin >> x;
  return x;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i=0; i<n-1; i++) {
    int a, b;
    cin >> a >> b; a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  stack<pair<int, int>> dfs;
  dfs.push({0, -1});
  int last = -1;
  pair<int, int> found = {-1, -1};
  while (!dfs.empty() && found.first == -1) {
    auto [curr, p] = dfs.top(); dfs.pop();
    for (int neighbor : adj[curr]) if (neighbor != p) {
      dfs.push({neighbor, curr});
    }

    if (last == -1) {
      last = curr;
    } else {
      int x = query(last, curr);
      if (x) {
        found = {last, curr};
      } else {
        last = -1;
      }
    }
  }

  if (found.first == -1) {
    cout << "! " << last+1 << '\n';
  } else {
    int x = query(found.first, found.first);
    if (x) {
      cout << "! " << found.first+1 << '\n';
    } else {
      cout << "! " << found.second+1 << '\n';
    }
  }
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) solve();
}
