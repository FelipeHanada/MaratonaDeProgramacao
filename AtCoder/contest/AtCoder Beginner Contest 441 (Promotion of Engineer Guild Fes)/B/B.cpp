#include <bits/stdc++.h>
using namespace std;

#define ll long long


void solve() {
  int n, m;
  string s, t;
  int q;
  cin >> n >> m >> s >> t >> q;
  array<int,26> scnt, tcnt, wcnt;
  fill(scnt.begin(), scnt.end(), 0);
  fill(tcnt.begin(), tcnt.end(), 0);
  for (char c : s) scnt[c-'a']++;
  for (char c : t) tcnt[c-'a']++;
  while (q--) {
    string w;
    cin >> w;
    fill(wcnt.begin(), wcnt.end(), 0);
    for (char c : w) wcnt[c-'a']++;
    
    bool sok = 1, tok = 1;
    for (int i=0; i<26; i++) {
      if (wcnt[i] && !scnt[i]) sok = false;
      if (wcnt[i] && !tcnt[i]) tok = false;
    }

    if (sok && tok) {
      cout << "Unknown\n";
    } else if (sok) {
      cout << "Takahashi\n";
    } else {
      cout << "Aoki\n";
    }
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();    
    return 0;
}
