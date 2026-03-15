#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    
    for (int i=0; i<n; i++) a[i] = a[i] - b[i];
    int big = INT32_MIN;
    for (int i=0; i<n; i++) big = max(big, a[i]);

    vector<int> ans;
    for (int i=0; i<n; i++) {
      if (a[i] == big) ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (int x : ans) {
      cout << x + 1 << ' ';
    }
    cout << '\n';
  }
}
