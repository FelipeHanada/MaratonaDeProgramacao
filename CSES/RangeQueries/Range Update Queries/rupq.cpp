#include <bits/stdc++.h>
using namespace std;


using ll = long long;

struct SegTree {
  int size;
  vector<ll> tree;
  vector<bool> lazy;
  SegTree(int n) {
    size = 1;
    while (size < n) size *= 2;
    tree.assign(size * 2, 0);
    lazy.assign(size * 2, 0);
  }
  void push(int x) {
    if (!lazy[x]) return;
    tree[2*x+1] += tree[x];
    tree[2*x+2] += tree[x];
    tree[x] = 0;
    lazy[2*x+1] = 1;
    lazy[2*x+2] = 1;
    lazy[x] = 0;
  }
  void add(int l, int r, int v, int x, int lx, int rx) {
    if (lx >= l && rx <= r) {
      tree[x] += v;
      lazy[x] = 1;
      return;
    }
    if (lx >= r || rx <= l) return;

    push(x);
    int mid = (lx + rx) / 2;
    add(l, r, v, 2*x+1, lx, mid);
    add(l, r, v, 2*x+2, mid, rx);
  }
  void add(int l, int r, int v) { add(l, r, v, 0, 0, size); }
  ll get(int i, int x, int lx, int rx) {
    if (rx - lx == 1) return tree[x];
    push(x);
    int mid = (lx + rx) / 2;
    if (i < mid) return get(i, 2*x+1, lx, mid);
    else return get(i, 2*x+2, mid, rx);
  }
  ll get(int i) { return get(i, 0, 0, size); }
};


int main() {
  int n, q;
  cin >> n >> q;
  SegTree st(n);
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    st.add(i, i+1, x);
  }

  while (q--) {
    int t, a, b, u, k;
    cin >> t;
    if (t == 1) {
      cin >> a >> b >> u;
      st.add(a-1, b, u);
    } else {
      cin >> k;
      cout << st.get(k-1) << '\n';
    }
  }
}
