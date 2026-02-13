#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

struct DSU {
  vector<int> rank;
  vector<int> parent;
  DSU(int n) {
    rank.assign(n, 0);
    parent.assign(n, -1);
  }
  int find(int i) {
    if (parent[i] == -1) return i;
    return parent[i] = find(parent[i]);
  }
  bool merge_set(int i, int j) {
    int pi = find(i), pj = find(j);
    if (pi == pj) return 0;
    if (rank[pi] < rank[pj]) swap(pi, pj);
    parent[pj] = pi;
    if (rank[pi] == rank[pj]) rank[pi]++;
    return 1;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  DSU dsu(n);
  int comps = n;
  int nocycles = 0;
  for (int i=0; i<n; i++) {
    cin >> a[i];
    if (dsu.merge_set(i, a[i]-1)) {
      comps--;
    } else if (i+1 == a[a[i]-1]) {
      nocycles++;
    }
  }

  int l = 0, r = 0;
  l += comps - nocycles;
  r += comps - nocycles;
  if (nocycles) l++;
  r += nocycles;

  cout << l << ' ' << r << '\n';  
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
    
  precompute();
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
