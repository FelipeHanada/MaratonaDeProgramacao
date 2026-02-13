#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define _1 first
#define _2 second

void precompute() {

}

void solve() {
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i=2; i<=n; i++) if (a[i-1] == a[i-2] && a[i-1] == x) {
    stack<pair<int, int>> stk;
    for (int j=0; j<i; j++) {
      if (!stk.empty() && stk.top()._1 == a[j]) stk.push({a[j], stk.top()._2 + 1});
      else stk.push({a[j], 1});
    }
    int j=i; while (j < n && a[j] == x) j++;
    while (!stk.empty() && stk.top()._1 == x) stk.pop();
    while (
        !stk.empty() &&
        ((stk.top()._2 >= 2 && j < n && a[j] == stk.top()._1)
        || (j < n - 1 && a[j] == stk.top()._1 && a[j+1] == stk.top()._1))
      ) {
      int curr = a[j];
      while (!stk.empty() && stk.top()._1 == curr) stk.pop();
      while (j < n && a[j] == curr) j++;
    }
    ans = max(ans, j - (int)stk.size());
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
