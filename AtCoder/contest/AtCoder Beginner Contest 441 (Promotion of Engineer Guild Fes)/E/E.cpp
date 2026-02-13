#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct SegTree {
  int size;
  vector<int> tree;
  SegTree(int n) {
    size = 1;
    while (size < n) size *= 2;
    tree.assign(size*2, 0);
  }
  void add(int i, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree[x]++;
      return;
    }

    int mid = (lx + rx) / 2;
    if (i < mid) add(i, 2*x+1, lx, mid);
    else add(i, 2*x+2, mid, rx);
    tree[x] = tree[2*x+1] + tree[2*x+2];
  }
  void add(int i) { add(i, 0, 0, size); }
  int get(int l, int r, int x, int lx, int rx) {
    if (lx >= l && rx <= r) return tree[x];
    if (lx >= r || rx <= l) return 0;
    int mid = (lx + rx) / 2;
    return (get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx));
  }
  int get(int l, int r) { return get(l, r, 0, 0, size); }
};

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> prefix(n+1);
  prefix[0] = 0;
  for (int i=1; i<=n; i++) {
    prefix[i] = prefix[i-1];
    if (s[i-1] == 'A') prefix[i]++;
    else if (s[i-1] == 'B') prefix[i]--;
  }

  ll ans = 0;
  SegTree st(2*n+3);
  st.add(n);
  for (int i=1; i<=n; i++) {
    // prefix[i] - prefix[j], we need to find the number of j's 
    // such that prefix[j] < prefix[i]
    ans += st.get(0, n+prefix[i]);
    st.add(n+prefix[i]);
  }

  cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();    
    return 0;
}
