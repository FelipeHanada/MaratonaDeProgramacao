#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  int n;
  cin >> n;
  map<string, int> cnt;
  for (int i=0; i<n; i++) {
    string s; cin >> s;

    if (!cnt[s]) {
      cout << "OK\n";
    } else {
      cout << s << cnt[s] << '\n';
    }
    cnt[s]++;
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
    
  solve();
  return 0;
}
