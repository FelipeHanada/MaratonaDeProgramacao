#include <bits/stdc++.h>
using namespace std;


using ll = long long;

struct SegTree {
  int size;
  vector<ll> tree;
  SegTree(int n) {
    size = 1;
    while (size < n) size *= 2;
    tree.assign(size * 2, 0);
  }
  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree[x] = v;
      return;
    }
    int mid = (lx + rx) / 2;
    if (i < mid) set(i, v, 2*x+1, lx, mid);
    else set(i, v, 2*x+2, mid, rx);
    tree[x] = tree[2*x+1] + tree[2*x+2];
  }
  void set(int i, int v) { set(i, v, 0, 0, size); }
  ll get(int l, int r, int x, int lx, int rx) {
    if (lx >= l && rx <= r) return tree[x];
    if (lx >= r || rx <= l) return 0;
    int mid = (lx + rx) / 2;
    return get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx);
  }
  ll get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
  int n, q;
  cin >> n >> q;
  SegTree st(n);
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    st.set(i, x);
  }

  while (q--) {
    int t, k, u, a, b;
    cin >> t;
    if (t == 1) {
      cin >> k >> u;
      st.set(k-1, u);
    } else {
      cin >> a >> b;
      cout << st.get(a-1, b) << '\n';
    }
  }
}

