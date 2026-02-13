#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

constexpr int MAX_N = 300;
int n;
ll a[MAX_N][MAX_N];
ll sum[MAX_N];
int current_best;
bool chosen[MAX_N];
unordered_set<ll> possible;

void solve2(int time, int target) {
  if (time < 0 || !possible.count(target)) {
    current_best = max(current_best, target);
    return;
  }

  if (time < n - 1) solve2(time-1, target);
  if (target + time < current_best) return;
  for (int j=0; j<n; j++) if (!chosen[j]) {
    chosen[j] = 1;
    if (sum[j] - a[time][j] == target) solve2(time-1, target+1);
    else solve2(time-1, target);
    chosen[j] = 0;
  }
}

void solve() {
  cin >> n;
  fill_n(sum, n, 0);
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin >> a[j][i];
      sum[i] += a[j][i];
    }
  }

  for (int i=1; i<n; i++) {
    for (int j=0; j<n; j++) a[i][j] += a[i-1][j];
  }

  possible.clear();
  for (int i=0; i<n; i++) for (int j=0; j<n; j++)
      possible.insert(sum[j] - a[i][j]);
  
  // we need to choose some queue to be 0, 1, 2, ...
  //
  current_best = 0;
  fill_n(chosen, n, 0);
  solve2(n-1, 0);
  cout << current_best << '\n';
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
