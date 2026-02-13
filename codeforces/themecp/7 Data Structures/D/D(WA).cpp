#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

struct SegTree {
  int size;
  vector<ll> tree;
  SegTree(int n) {
    size = 1;
    while (size < n) size *= 2;
    tree.assign(size * 2, 0);
  }
  void add(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree[x] += v;
      return;
    }
    int mid = (lx + rx) / 2;
    if (i < mid) add(i, v, 2*x+1, lx, mid);
    else add(i, v, 2*x+2, mid, rx);
    tree[x] = tree[2*x+1] + tree[2*x+2];
  }
  void add(int i, int v) { add(i, v, 0, 0, size); }
  ll get(int l, int r, int x, int lx, int rx) {
    if (lx >= l && rx <= r) return tree[x];
    if (lx >= r || rx <= l) return 0;
    int mid = (lx + rx) / 2;
    return get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx);
  }
  ll get(int l, int r) { return get(l, r, 0, 0, size); }
};

constexpr int MAX_N = 5010;
int grid[MAX_N][MAX_N];
int n, m;
void solve() {
  cin >> n >> m;

  for (int i=0; i<n; i++) {
    int last = 0;
    for (int j=0; j<m; j++) {
      char c;
      cin >> c;
      grid[i][j] = (c == '1');
    }
  }

  map<array<int,2>, int> intervals;
  set<int> ys;
  for (int i=0; i<n; i++) {
    int j=0;
    while (j < m) {
      while (j < m && !grid[i][j]) j++;

      int start = j;
      while (j < m && grid[i][j]) j++;
      if (j - start) {
        ys.insert(start);
        intervals[{j, -start}]++;
      }
    }
  }
  
  map<int, int> comp;
  {
    int i=0;
    for (int y : ys) comp[y] = i++;
  }

  deque<array<int,2>> q;
  for (int i=0; i<m; i++) for (int j=i+1; j<=m; j++) q.push_back({j, -i});
  sort(q.begin(), q.end());

  SegTree segtree(ys.size()+5);
  map<array<int,2>, ll> cont;
  for (auto it = intervals.rbegin(); it!=intervals.rend(); it++) {
    while (q.back() > it->first) {
      auto [ x, y ] = q.back();
      cont[{-y, x}] = segtree.get(0, comp[-y] + 1);
      q.pop_back();
    }
    
    auto [ x, y ] = it->first;
    segtree.add(comp[-y], it->second);
    cont[{-y, x}] = segtree.get(0, comp[-y] + 1);
    if (q.back() == it->first) q.pop_back();
  }

  while (!q.empty()) {
    auto [ x, y ] = q.back();
    cont[{-y, x}] = segtree.get(0, comp[-y] + 1);
    q.pop_back();
  }

  ll ans = 0;
  for (auto it = cont.begin(); it != cont.end(); it++) {
    ans = max(ans, (it->first[1] - it->first[0]) * it->second);
  }

  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
    
  precompute();
  solve();
  return 0;
}
