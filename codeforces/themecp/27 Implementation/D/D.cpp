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

  ll sizes[64];
  sizes[0] = sizes[1] = 1;
  for (int i=2; i<64; i++) sizes[i] = (sizes[i-1]<<1);

  while (tt--) {
    ll n, k;
    cin >> n >> k; k--;

    int i = n;
    vector<int> ans;
    bool ok = 1;
    int delta = 0;
    int big = 0;
    while (ok && i > 0) {
      big = delta;
      int curr = delta+1, size = i - 1;
      delta++;

      while (curr <= n && size < 64 && k >= sizes[size]) {
        k -= sizes[size];
        curr++;

        size--; i--;
        delta++;
      }

      if (curr > n || size < 0) {
        ok = 0;
        break;
      }

      for (int j=curr; j>big; j--) {
        ans.push_back(j);
      }

      i--;
    }

    if (!ok) {
      cout << "-1\n";
    } else {
      for (int x : ans) cout << x << ' ';
      cout << '\n';
    }
  }
}
