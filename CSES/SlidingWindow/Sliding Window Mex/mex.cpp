#include <bits/stdc++.h>
using namespace std;



int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  set<int> s; for (int i=0; i<=k; i++) s.insert(i);
  map<int, int> cnt;
  for (int i=0; i<k; i++) {
    if (!cnt[a[i]]++) s.erase(a[i]);
  }

  cout << *s.begin() << ' ';
  for (int i=k; i<n; i++) {
    if (!--cnt[a[i-k]]) s.insert(a[i-k]);
    if (!cnt[a[i]]++) s.erase(a[i]);
    cout << *s.begin() << ' ';
  }
  cout << '\n';
}
