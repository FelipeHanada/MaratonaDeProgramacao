#include <bits/stdc++.h>
using namespace std;


int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i=0; i<m; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<array<int,2>> parent(n, {-1, 0});
  vector<bool> seen(n, 0);
  int a = -1, b = -1;
  
  for (int i=0; i<n && a == -1; i++) {
    if (seen[i]) continue;
    seen[i] = 1;
    stack<int> stk;
    stk.push(i);
    while (!stk.empty() && a == -1) {
      auto curr = stk.top();
      stk.pop();

      for (int neighbor : adj[curr]) {
        if (neighbor == parent[curr][0]) continue;
        if (seen[neighbor]) {
         a = neighbor;
          b = curr;
          break;
        } else {
          seen[neighbor] = 1;
          parent[neighbor] = {curr, parent[curr][1]+1};
          stk.push(neighbor);
        }
      }
    }
  }

  if (a == -1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  // we have to print a path form a to b

  vector<int> pa, pb;
  while (parent[a][1] < parent[b][1]) {
    swap(a, b);
  }
  
  int curra = a, currb = b;
  while (parent[curra][1] > parent[currb][1]) {
    pa.push_back(curra);
    curra = parent[curra][0];
  }

  while (curra != currb) {
    pa.push_back(curra);
    pb.push_back(currb);
    curra = parent[curra][0];
    currb = parent[currb][0];
  }
  pa.push_back(curra);

  cout << pa.size() + pb.size() + 1 << '\n';
  for (int i=0; i<pa.size(); i++) cout << pa[i] + 1 << ' ';
  for (int i=pb.size()-1; i>=0; i--) cout << pb[i] + 1 << ' ';
  cout << a + 1 << " \n";
}

