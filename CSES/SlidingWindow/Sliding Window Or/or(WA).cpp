#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main() {
  int n, k, x, a, b, c;
  cin >> n >> k >> x >> a >> b >> c;

  deque<int> window = {x};
  array<int,32> cnt; int curr = x;
  fill(cnt.begin(), cnt.end(), 0);
  for (int i=0; i<32; i++) if (x&(1<<i)) cnt[i]++;

  while (window.size() < k) {
    window.push_back(((ll)window.back()*a+b)%c);
    for (int i=0; i<32; i++) if (x&(1<<i)) {
      if (!cnt[i]) curr += (1<<i);
      cnt[i]++;
    }
  }

  int ans = curr;
  for (int j=k; j<n; j++) {
    window.push_back(((ll)window.back()*a+b)%c);
    for (int i=0; i<32; i++) if (window.back()&(1<<i)) {
      if (!cnt[i]) curr += (1<<i);
      cnt[i]++;
    }

    for (int i=0; i<32; i++) if (window.front()&(1<<i)) {
      cnt[i]--;
      if (!cnt[i]) curr -= (1<<i);
    }
    window.pop_front();

    ans ^= curr;
  }

  cout << ans << '\n';
}
