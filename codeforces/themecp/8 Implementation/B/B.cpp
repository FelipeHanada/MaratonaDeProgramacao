#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  string s;
  cin >> s;

  int i=0;
  set<int> seen;
  for (; i<s.size(); i++) {
    int curr = 0;
    while (i < s.size() && s[i] != ',') {
      curr *= 10;
      curr += s[i] - '0';
      i++;
    }
    seen.insert(curr);
  }


  vector<vector<int>> ans;
  int last = -1;
  for (int x : seen) {
    if (last + 1 != x) {
      ans.push_back({x});
    } else {
      ans.back().push_back(x);
    }
    last = x;
  }

  for (int i=0; i<ans.size()-1; i++) {
    cout << ans[i].front();
    if (ans[i].back() != ans[i].front()) cout << '-' << ans[i].back();
    cout << ',';
  }
  cout << ans.back().front();
  if (ans.back().back() != ans.back().front()) cout << '-' << ans.back().back();
  cout << '\n';
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
