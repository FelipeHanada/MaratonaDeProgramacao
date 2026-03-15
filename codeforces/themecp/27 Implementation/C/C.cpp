#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second


ll prefix[1001][1001];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
    int tt;
    cin >> tt;

    while (tt--) {
      int n, q;
      cin >> n >> q;
      vector<array<int,2>> rects(n);
      for (int i=0; i<n; i++) cin >> rects[i][0] >> rects[i][1];

      for (int i=0; i<=1000; i++) fill_n(prefix[i], 1001, 0);
      for (int i=0; i<n; i++) {
        prefix[rects[i][0]][rects[i][1]] += rects[i][0] * rects[i][1];
      }
      for (int i=1; i<=1000; i++) {
        for (int j=1; j<=1000; j++) {
          prefix[i][j] = prefix[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
      }

      while (q--) {
        int h1, w1, h2, w2;
        cin >> h1 >> w1 >> h2 >> w2; h2--; w2--;
        cout << prefix[h2][w2] - prefix[h1][w2] - prefix[h2][w1] + prefix[h1][w1] << '\n';
      }
    }
}
