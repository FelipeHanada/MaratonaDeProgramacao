#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define first _1
#define second _2

void precompute() {
  
}

void solve() {
  int n, m;
  cin >> n >> m;

  if (n <= 2) {
    cout << 3 * m << '\n';
    return;
  } else if (m <= 1) {
    cout << 2 * n << '\n';
    return;
  }

  int ans = INT32_MAX;
  int lastn = 2 * (n + min(n/3, m/2)), lastm = 3 * m;
  int k = min(min(n/3, m/2), (lastn-lastm-1)/8);
  if (lastn > lastm) {
    lastn -= 2 * k; lastm -= 6 * k;
    ans = min(ans, max(lastn, lastm));
  }

  lastn = 2 * n, lastm = 3 * (m + min(n/3, m/2));
  // k = min(min(n/3, m/2), (lastm-lastn-1)/7);
  // lastn += 4 * k; lastm -= 3 * k;

  if (lastn % 6 == 2) {
    int x = (lastm - lastn - 7 - 1) / 18;
    ans = min(ans, max(lastn + 12*x + 4, lastm - 6 * x - 3));
    x = (lastm - lastn - 1 - 1) / 18;
    ans = min(ans, max(lastn + 12*x -1 + 2, lastm - 6 * x));
  } else {
    int x = (lastm - lastn + 2 - 1) / 18;
    ans = min(ans, max(lastn + 12*x - 6 + 4, lastm - 6*x));
    x = (lastm - lastn - 5 - 1) / 18;
    ans = min(ans, max(lastn + 12*x + 2, lastm - 6*x - 3));
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
