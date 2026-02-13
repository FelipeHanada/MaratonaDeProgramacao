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

  int leafs = 0;
  for (int i=0; i<n; i++) if (adj[i].size() == 1) {
    leafs++;
  }

  cout << (leafs + 1)/2 << '\n';
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
