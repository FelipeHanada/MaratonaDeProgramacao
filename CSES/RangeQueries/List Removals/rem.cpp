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
  int get(int i, int x, int lx, int rx) {
    if (rx - lx == 1) return lx;
    int mid = (lx + rx) / 2;
    if (i <= tree[2*x+1]) return get(i, 2*x+1, lx, mid);
    else return get(i-tree[2*x+1], 2*x+2, mid, rx);
  }
  int get(int i) { return get(i, 0, 0, size); }
};

int main() {
  int n;
  cin >> n;
 
  SegTree segtree(n);
  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
    segtree.add(i, 1);
  }

  for (int i=0; i<n; i++) {
    int x; cin >> x; x--;
    int idx = segtree.get(x+1);
    cout << a[idx] << ' ';
    segtree.add(idx, -1);
  }
  cout << '\n';
}
