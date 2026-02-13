#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  int n, k;
  cin >> n >> k;
  deque<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  if (find(a.begin(), a.end(), k) == a.end()) {
    a.push_back(k);
    ans++;
  }
  sort(a.begin(), a.end());

  auto lb = lower_bound(a.begin(), a.end(), k), ub = upper_bound(a.begin(), a.end(), k);
  int l = distance(a.begin(), lb), r = distance(a.begin(), ub);

  if (l > n / 2) {
    while (a[(a.size()-1)/2] != k) {
      a.push_back(0);
      ans++;
    }
  } else {
    while (a[(a.size()-1)/2] != k) {
      a.push_front(0);
      ans++;
    }
  }

  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
    
  precompute();
  solve();
  return 0;
}
