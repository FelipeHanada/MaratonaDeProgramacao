#include <bits/stdc++.h>
using namespace std;


using ll = long long;

struct SegTree {
  int size;
  vector<int> tree;
  SegTree(int n) {
    size = 1;
    while (size < n) size *= 2;
    tree.assign(2*size, 0);
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
  int get(int l, int r, int x, int lx, int rx) {
    if (lx >= l && rx <= r) return tree[x];
    if (lx >= r || rx <= l) return 0;
    int mid = (lx + rx) / 2;
    return get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx);
  }
  int get(int l, int r) { return get(l, r, 0, 0, size); }
};

int main() {
  int n, k;
  cin >> n >> k;
  set<int> s;
  map<int, int> comp;
  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  int i=0;
  for (int x : s) {
    comp[x] = i++;
  }
  for (int i=0; i<n; i++) a[i] = comp[a[i]];

  SegTree st(2e5+1);
  ll curr = 0;
  for (int i=0; i<k; i++) {
    st.add(a[i], 1);
    curr += st.get(a[i]+1, 2e5+1);
  }

  cout << curr << ' ';
  for (int i=k; i<n; i++) {
    curr -= st.get(0, a[i-k]);
    st.add(a[i-k], -1);
    st.add(a[i], 1);
    curr += st.get(a[i]+1, 2e5+1);

    cout << curr << ' ';
  }
  cout << '\n';
}

