#include <bits/stdc++.h>
using namespace std;


int main() {
    int tt;
    cin >> tt;
    while (tt--) {
    int n;
    cin >> n;
    vector<set<int>> adj(n);
    for (int i=0; i<n; i++) {
      int x;
      cin >> x; x--;
      adj[i].insert(x);
      adj[x].insert(i);
    }

    vector<bool> seen(n, 0);
    int cycles = 0, bamboos = 0;
    for (int i=0; i<n; i++) {
      if (seen[i]) continue;

      queue<int> bfs; bfs.push(i);
      seen[i] = true;
      bool bamboo = 0;
      while (!bfs.empty()) {
        auto curr = bfs.front(); bfs.pop();
        bamboo = bamboo || (adj[curr].size() == 1);
        
        for (int neighbor : adj[curr]) {
          if (seen[neighbor]) continue;
          seen[neighbor] = 1;
          bfs.push(neighbor);
        }
      }

      if (bamboo) bamboos++;
      else cycles++;
    }

    cout << cycles + min(bamboos, 1) << ' ' << cycles + bamboos << '\n';
  }
}
