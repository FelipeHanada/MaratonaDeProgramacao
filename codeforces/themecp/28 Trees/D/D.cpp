#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<int> a;
vector<vector<int>> adj;
vector<ll> sum;
vector<ll> best;


void compute(int r, int last = -1) {
  if (adj[r].size() == 1) {
    best[r] = sum[r] = a[r];
    return;
  }

  for (int child : adj[r]) if (child != last) {
    compute(child, r);
  }

  for (int child : adj[r]) if (child != last) {
    sum[r] += sum[child];
    best[r] = max(best[r], best[child]);
  }
  sum[r] += a[r];
  best[r] = max(best[r], sum[r]);
}

ll solve(int r, int last = -1) {
  ll big1 = INT64_MIN, big2 = INT64_MIN;
  for (int child : adj[r]) if (child != last) {
    if (best[child] >= big1) {
      tie(big1, big2) = make_tuple(best[child], big1);
    } else if (best[child] > big2) {
      big2 = best[child];
    }
  }

  ll ans = INT64_MIN;
  if (big2 != INT64_MIN) ans = big1 + big2;
  for (int child : adj[r]) if (child != last)
    ans = max(ans, solve(child, r));
  return ans;
}

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

  sum.assign(n, 0); best.assign(n, INT64_MIN);
  compute(0);
  ll ans = solve(0);

  if (ans == INT64_MIN) {
    cout << "Impossible\n";
  } else {
    cout << ans << '\n';
  }
}
