#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  int n; string s;
  cin >> n >> s;

  set<char> cand;
  for (char i = 'a'; i <= 'z'; i++) cand.insert(i);

  map<char, char> m;
  vector<char> head(26, -1);
  string t;
  for (int i=0; i<n; i++) {
    if (m.count(s[i])) {
      t.push_back(m[s[i]]);
    } else {
      char choice;
      for (char c : cand) {
        if (c == s[i]) continue;
        
        char p = c;
        while (head[p - 'a'] != -1) p = head[p - 'a'];
        if (p != c) head[c - 'a'] = p;
        if (cand.size() > 1 && head[c - 'a'] == s[i]) continue;

        choice = c;
        break;
      }
      
      cand.erase(choice);
      m[s[i]] = choice;
      head[s[i] - 'a'] = choice;
      t.push_back(choice);
    }
  }

  cout << t << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
#endif
    
  precompute();
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
