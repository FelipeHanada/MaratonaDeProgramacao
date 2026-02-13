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
bool times[MAX_N];
set<pair<int, ll>> possible;
map<pair<int, ll>, int> inv;

int solve2(int time, int target) {
  int best = target;
  for (int j=0; j<n; j++) if (possible.count({j, target}) && !chosen[j] && !times[inv[{j, target}]]) {
    if (target + time + 1 <= current_best) break;
    chosen[j] = 1;
    times[inv[{j, target}]] = 1;
    best = max(best, solve2(time -1, target + 1));
    times[inv[{j, target}]] = 0;
    chosen[j] = 0;
  }
  current_best = max(current_best, best);
  return best;
}

void solve() {
  cin >> n;
  fill_n(sum, n, 0);
  for (int j=0; j<n; j++) {
    cin >> a[0][j];
    sum[j] += a[0][j];
    for (int i=1; i<n; i++) {
      cin >> a[i][j];
      sum[j] += a[i][j];
      a[i][j] += a[i-1][j];
    }
  }

  possible.clear(); inv.clear();
  for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
    possible.insert({j, sum[j] - a[i][j]});
    inv[{j, sum[j] - a[i][j]}] = i;
  }
  
  // we need to choose some queue to be 0, 1, 2, ...
  //
  current_best = 0;
  fill_n(chosen, n, 0);
  fill_n(times, n, 0);
  cout << solve2(n-1, 0) << '\n';
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
