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
    vector<int> childs(n, 0);
    for (int i=0; i<n-1; i++) {
      int p;
      cin >> p; p--;
      childs[p]++;
    }

    auto check = [&](int time) -> bool {
      priority_queue<int> pq; pq.push(1);
      for (int i=0; i<n; i++) if (childs[i]) pq.push(childs[i]);
      int rem = time;
      int sub = 0;
      while (rem && !pq.empty()) {
        auto curr = pq.top(); pq.pop();
        curr--;
        rem--;

        curr -= rem;
        if (curr > 0) sub += curr;
      }

      rem -= sub;
      return rem >= 0 && pq.empty();
    };

    int l = 0, r = n;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }

    cout << r << '\n';
  }
}
