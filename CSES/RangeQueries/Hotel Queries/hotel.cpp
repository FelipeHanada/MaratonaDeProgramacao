#include <bits/stdc++.h>
using namespace std;


struct SegTree {
  int size;
  vector<int> tree;
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
    if (i < mid) {
      set(i, v, 2*x+1, lx, mid);
    } else {
      set(i, v, 2*x+2, mid, rx);
    }
    tree[x] = max(tree[2*x+1], tree[2*x+2]);
  }
  void set(int i, int v) { set(i, v, 0, 0, size); }
  int op(int v, int x, int lx, int rx) {
    if (tree[x] < v) return 0;
    if (rx - lx == 1) {
      tree[x] -= v;
      return 1 + (lx + rx) / 2;
    }
    
    int mid = (lx + rx) / 2;
    int ans;
    if (tree[2*x+1] >= v) ans = op(v, 2*x+1, lx, mid);
    else ans = op(v, 2*x+2, mid, rx);
    tree[x] = max(tree[2*x+1], tree[2*x+2]);
    return ans;
  }
  int op(int v) { return op(v, 0, 0, size); }
};

int main() {
  int n, m;
  cin >> n >> m;
  SegTree st(n);
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    st.set(i, x);
  }

  for (int i=0; i<m; i++) {
    int r;
    cin >> r;
    cout << st.op(r) << ' ';
  }
  cout << '\n';
}
