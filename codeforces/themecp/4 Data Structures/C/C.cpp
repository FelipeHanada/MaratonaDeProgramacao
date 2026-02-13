#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<n; i++) cin >> b[i];

  map<int, int> m, idx;
  for (int i=0; i<n; i++) m[a[i]] = b[i];
  for (int i=0; i<n; i++) idx[a[i]] = i;

  int mid = -1;
  for (int i=0; i<n; i++) {
    if (m[b[i]] != a[i]) {
      cout << "-1\n";
      return;
    } else if (a[i] == b[i]) {
      if (mid != -1 || !(n % 2)) {
        cout << "-1\n";
        return;
      }
      mid = a[i];
    }
  }

  queue<pair<int, int>> ans;

  auto op = [&](int i, int target) -> void {
    if (idx[target] == i) return;
    ans.push({i, idx[target]});
    int other = a[i];
    swap(a[idx[target]], a[i]);
    idx[other] = idx[target];
    idx[target] = i;
  };

  if (mid != -1) op(n/2, mid);

  for (int i=0; i<n/2; i++) {
    int j = n-i-1;
    op(j, m[a[i]]);
  }

  cout << ans.size() << '\n';
  while (!ans.empty()) {
    cout << ans.front().first + 1 << ' ' << ans.front().second + 1 << '\n';
    ans.pop();
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}
