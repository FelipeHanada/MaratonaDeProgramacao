#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define first _1
#define second _2

void precompute() {
  
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  map<int, int> idx;
  for (int i=0; i<n; i++) {
    cin >> a[i];
    idx[a[i]] = i;
  }

  ll ans = 0;
  while (m--) {
    int b; cin >> b;
    ans += 1 + (idx[b] / k);

    // swap a[idx[b]] with a[idx[b]-1];
    if (idx[b] == 0) continue;
    idx[a[idx[b]-1]]++;
    idx[b]--;
    swap(a[idx[b]], a[idx[b]+1]);
  }

  cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    solve();
    return 0;
}
