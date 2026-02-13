#include <bits/stdc++.h>
using namespace std;



int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  map<int, int> window;
  for (int i=0; i<k; i++) {
    window[a[i]]++;
  }
  cout << window.size() << ' ';

  for (int i=k; i<n; i++) {
    if (!(--window[a[i-k]])) window.erase(a[i-k]);
    window[a[i]]++;
    cout << window.size() << ' ';
  }
  cout << '\n';
}
