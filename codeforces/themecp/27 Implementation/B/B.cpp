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
  int tt;
  cin >> tt;

  array<int,int(1e5)+1> ans;
  ans[0] = 1;
  for (int i=1; i<=int(1e5); i++) ans[i] = mult(ans[i-1], 2);

  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), d(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    for (int i=0; i<n; i++) cin >> d[i];

    set<int> ds;
    for (int i=0; i<n; i++) ds.insert(d[i]-1);

    vector<vector<int>> adj(n);
    for (int i=0; i<n; i++) {
      if (a[i] == b[i]) continue;
      adj[a[i]-1].push_back(b[i]-1);
      adj[b[i]-1].push_back(a[i]-1);
    }

    int comps = 0, dcomps = 0;
    vector<bool> seen(n, 0);
    vector<bool> marked(n, 0);
    for (int i=0; i<n; i++) if (!seen[i]) {
      seen[i] = 1;
      if (adj[i].empty()) continue;

      stack<int> stk;
      stk.push(i);
      comps++;

      while (!stk.empty()) {
        auto curr = stk.top(); stk.pop();

        if (ds.count(curr) && !marked[i]) {
          marked[i] = 1;
          dcomps++;
        }
        ds.erase(curr);

        for (int neighbor : adj[curr]) {
          if (seen[neighbor]) continue;
          seen[neighbor] = 1;
          stk.push(neighbor);
        }
      }
    }

    cout << ans[comps - dcomps] << '\n';
  }
}
