#include <bits/stdc++.h>
using namespace std;


int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  map<int,int> m;
  set<array<int,2>> s;
  for (int i=0; i<k; i++) {
    if (m.count(a[i])) s.erase({-m[a[i]], a[i]});
    m[a[i]]++;
    s.insert({-m[a[i]], a[i]});
  }
  cout << (*s.begin())[1] << ' ';

  for (int i=k; i<n; i++) {
    if (m.count(a[i-k])) s.erase({-m[a[i-k]], a[i-k]});
    m[a[i-k]]--;
    s.insert({-m[a[i-k]], a[i-k]});

    if (m.count(a[i])) s.erase({-m[a[i]], a[i]});
    m[a[i]]++;
    s.insert({-m[a[i]], a[i]});

    cout << (*s.begin())[1] << ' ';
  }
  cout << '\n';
}
