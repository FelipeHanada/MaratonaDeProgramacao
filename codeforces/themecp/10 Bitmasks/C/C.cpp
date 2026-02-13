#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll
#define pii pair<int, int>
#define _1 first
#define _2 second

void precompute() {
  
}

void solve() {
  int n, k;
  cin >> n >> k;

  set<int> s;
  for (int i=0; i<n; i++) {
    int p = 0;
    for (int j=0; j<k; j++) {
      int x; cin >> x;
      if (x) p |= (1 << j);
    }
    s.insert(p);
  }

  vector<int> problems(s.size());
  int i = 0;
  for (int p : s) problems[i++] = p;

  for (int i=0; i<problems.size(); i++) {
    if (problems[i] == 0) {
      cout << "YES\n";
      return;
    }

    for (int j=i+1; j<problems.size(); j++) {
      if ((problems[i] & problems[j]) == 0) {
        cout << "YES\n";
        return;
      }
    }
  }

  cout << "NO\n";
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
