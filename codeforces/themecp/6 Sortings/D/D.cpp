#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve2(set<ll> &s, const vector<int>& a, const vector<ll>& prefix, int i, int j) {
  if (i >= j) return;

  s.insert(prefix[j] - prefix[i]);
  if (a[i] == a[j-1]) return;

  int midi = (a[i] + a[j-1]) / 2;
  int mid = i;
  while (a[mid] <= midi) mid++;
  solve2(s, a, prefix, i, mid);
  solve2(s, a, prefix, mid, j);
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  vector<ll> prefix(n+1);
  prefix[0] = 0;
  for (int i=1; i<=n; i++) {
    prefix[i] = prefix[i-1] + a[i-1];
  }

  set<ll> possible;
  solve2(possible, a, prefix, 0, n);

  while (q--) {
    ll x; cin >> x;
    if (possible.count(x)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
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
