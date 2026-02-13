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
  deque<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int small = a.front(), big = a.back();
  a.pop_front(); a.pop_back();

  cout << big << ' ';
  for (int x : a) cout << x << ' ';
  cout << small << '\n';
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
