#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<array<int,4>> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i][1] >> a[i][2] >> a[i][0];
    a[i][3] = i;
  }
  sort(a.begin(), a.end());

  bool up = 1; int curr = 1; int time = 0;
  map<int, vector<int>> to_pick;
  map<int, vector<int>> el; // ev[floor] = { start, finish, i }
 
  vector<int> ans(n);
  int i = 0;
  int w = 0;
  while (w < n) {
    while (i < n && a[i][0] <= time) {
      if (a[i][1] == a[i][2]) {
        ans[a[i][3]] = a[i][0];
        w++;
      } else {
        to_pick[a[i][1]].push_back(i);
      }
      i++;
    }

    int next_floor;
    if (up) {
      next_floor = m;
      auto lb = to_pick.lower_bound(curr);
      if (lb != to_pick.end()) next_floor = min(next_floor, lb->first);
      lb = el.lower_bound(curr);
      if (lb != el.end()) next_floor = min(next_floor, lb->first);
      if (i < n) next_floor = min(next_floor, curr + a[i][0] - time);

      time += next_floor - curr;
      curr = next_floor;
      if (curr == m) up = 0;
    } else {
      next_floor = 1;
      auto ub = to_pick.upper_bound(curr);
      if (ub != to_pick.begin()) next_floor = max(next_floor, (--ub)->first);
      ub = el.upper_bound(curr);
      if (ub != el.begin()) next_floor = max(next_floor, (--ub)->first);
      if (i < n) next_floor = max(next_floor, curr - (a[i][0] - time));

      time += curr - next_floor;
      curr = next_floor;
      if (curr == 1) up = 1;
    }

    for (int x : to_pick[curr]) {
      el[a[x][2]].push_back(x);
    }
    to_pick.erase(curr);

    for (int x : el[curr]) {
      ans[a[x][3]] = time;
      w++;
    }
    el.erase(curr);
  }

  for (int x : ans) {
    cout << x << '\n';
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
