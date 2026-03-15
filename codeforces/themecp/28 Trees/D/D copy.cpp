#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<int> a;
vector<vector<int>> adj;
vector<ll> sum;
vector<ll> best;



int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif

  cin >> n;
  a.resize(n);
  adj.assign(n, vector<int>());
  for (int i=0; i<n; i++) cin >> a[i];

  for (int i=1; i<n; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<int> parent(n, -1);

  sum.assign(n, 0); best.assign(n, INT64_MIN);
  stack<array<int,3>> stk; stk.push({ 0, 1, -1 });
  while (!stk.empty()) {
    auto [curr, state, p] = stk.top(); stk.pop();

    if (state) {
      parent[curr] = p;

      stk.push({ curr, 0, p });
      for (int child : adj[curr]) if (child != p) {
        stk.push({ child, 1, curr });
      }
    } else {
      sum[curr] = a[curr];
      for (int child : adj[curr]) if (child != p) {
        sum[curr] += sum[child];
        best[curr] = max(best[curr], best[child]);
      }
      best[curr] = max(best[curr], sum[curr]);
    }
  }

  ll ans = INT64_MIN;
  for (int i=0; i<n; i++) {
    ll big1 = INT64_MIN, big2 = INT64_MIN;
    for (int child : adj[i]) if (child != parent[i]) {
      if (best[child] >= big1) {
        tie(big1, big2) = make_tuple(best[child], big1);
      } else if (best[child] > big2) {
        big2 = best[child];
      }
    }

    if (big2 == INT64_MIN) continue;
    ans = max(ans, big1 + big2);
  }

  if (ans == INT64_MIN) {
    cout << "Impossible\n";
  } else {
    cout << ans << '\n';
  }
}
