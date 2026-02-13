#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  int m = n;
  int i=0;
  while (i < n && a[i] == m) {
    cout << a[i++] << ' '; m--;
  }
  
  stack<int> stk;
  queue<int> q;
  while (i < n && a[i] != m) stk.push(a[i++]);
  if (i < n) stk.push(a[i++]);
  while (i<n) q.push(a[i++]);

  while (!stk.empty()) {
    cout << stk.top() << ' ';
    stk.pop();
  }
  while (!q.empty()) {
    cout << q.front() << ' ';
    q.pop();
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
