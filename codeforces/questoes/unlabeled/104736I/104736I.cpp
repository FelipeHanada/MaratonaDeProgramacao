#include <bits/stdc++.h>
using namespace std;


#define ll long long
constexpr int MOD = 1e9+7;

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
    tree[x] = (tree[2*x+1] + tree[2*x+2]) % MOD;
  }
  void add(int i) { add(i, 0, 0, size); }
  int get(int l, int r, int x, int lx, int rx) {
    if (lx >= l && rx <= r) return tree[x];
    if (lx >= r || rx <= l) return 0;
    int mid = (lx + rx) / 2;
    return (get(l, r, 2*x+1, lx, mid) + get(l, r, 2*x+2, mid, rx)) % MOD;
  }
  int get(int l, int r) { return get(l, r, 0, 0, size); }
};


int main() {
  string s;
  cin >> s;
  ll n;
  cin >> n;

  vector<int> a(s.size()), b(s.size());
  SegTree st(26);
  for (int i=0; i<s.size(); i++) {
    st.add((int)(s[i]-'a'));
    a[i] = st.get((int)(s[i]-'a'+1), 26);
  }
  for (int i=0; i<s.size(); i++) {
    b[i] = st.get((int)(s[i]-'a'+1), 26);
  }

  int ans = 0;
  for (int i=0; i<s.size(); i++) {
    int q = ((ll)(((n-1)%MOD)*(n%MOD)/2)%MOD * b[i])%MOD;
    int r = (n*a[i])%MOD;
    ans = (ans + (q + r)%MOD) % MOD;
  }

  cout << ans << '\n';
}
