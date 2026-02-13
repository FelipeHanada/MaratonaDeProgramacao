#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

bool solve2(vector<int>& a, int i, int curr) {
  if (i == a.size()) return curr % 360 == 0;
  
  return solve2(a, i+1, curr + a[i]) || solve2(a, i+1, curr - a[i]);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0; i<n; i++) cin >> a[i];

  cout << (solve2(a, 0, 0) ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    solve();    
    return 0;
}
