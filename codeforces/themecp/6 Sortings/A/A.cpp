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
  vector<array<int, 3>> a(n);
  int bigR = INT32_MIN;
  for (int i=0; i<n; i++) {
    cin >> a[i][0] >> a[i][1];
    a[i][2] = i;
    bigR = max(bigR, a[i][1]);
    a[i][1] *= -1;
  }
  sort(a.begin(), a.end());

  int r = -a[0][1];
  if (r == bigR) {
    cout << a[0][2] + 1 << '\n';
  } else {
    cout << "-1\n";
  }
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
