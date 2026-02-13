#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (int i=0; i<n; i++) cin >> a[i];
  for (int i=0; i<m; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  string s;
  cin >> s;

  b.push_back(INT32_MAX);
  vector<array<int,2>> survive(n);
  
  map<int, vector<int>> dies_at;

  int last_spike = INT32_MIN;
  int j = 0;
  for (int i=0; i<n; i++) {
    while (j < m && b[j] < a[i]) {
      last_spike = b[j++];
    }

    dies_at[last_spike - a[i]].push_back(i);
    dies_at[b[j] - a[i]].push_back(i);
  }


  int delta = 0;
  set<int> dead;
  for (char m : s) {
    if (m == 'R') delta++;
    else delta--;

    for (int r : dies_at[delta]) {
      dead.insert(r);
    }
    dies_at.erase(delta);
    
    cout << n - dead.size() << ' ';
  }
  cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    int tt;
    cin >> tt;
    while (tt--) solve();    
    return 0;
}
