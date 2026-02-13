#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
  int n;
  cin >> n;
  set<int> s;
  map<int, int> red, blue;
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    if (i % 2) red[x]++;
    else blue[x]++;
    s.insert(x);
  }
  
  bool ok = true;
  auto it = s.begin();
  bool red_next = true;
  while (ok && it != s.end()) {
    if (abs(red[*it] - blue[*it]) > 1) ok = false;
    if (red_next && red[*it] < blue[*it]) ok = false;
    if (!red_next && red[*it] > blue[*it]) ok = false;
    if (red[*it] != blue[*it]) red_next = !red_next;
    it++;
  }
  if (ok) {
    cout << "YES\n";
    return;
  }

  ok = true;
  red_next = false;
  it = s.begin();
  while (ok && it != s.end()) {
    if (abs(red[*it] - blue[*it]) > 1) ok = false;
    if (red_next && red[*it] < blue[*it]) ok = false;
    if (!red_next && red[*it] > blue[*it]) ok = false;
    if (red[*it] != blue[*it]) red_next = !red_next;
    it++;
  }
  if (ok) {
    cout << "YES\n";
    return;
  }

  cout << "NO\n";
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
