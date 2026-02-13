#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  map<string, vector<string>> m;
  int n; cin >> n;
  for (int i=0; i<n; i++) {
    string name; int k;
    cin >> name >> k;
    for (int j=0; j<k; j++) {
      string s;
      cin >> s;
      m[name].push_back(s);
    }
  }

  cout << m.size() << '\n';

  for (auto it = m.begin(); it != m.end(); it++) {
    vector<vector<string>> sorted(11);
    for (string s : it->second) {
      sorted[s.size()].push_back(s);
    }

    vector<string> ans;
    set<string> suffs;
    for (int i=10; i>=1; i--) {
      for (string s : sorted[i]) {
        if (suffs.count(s)) continue;
        
        ans.push_back(s);
        for (int j=0; j<s.size(); j++) {
          suffs.insert(s.substr(j, s.size()));
        }
      }
    }

    cout << it->first << ' ' << ans.size() << ' ';
    for (string s : ans) {
      cout << s << ' ';
    }
    cout << '\n';
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
