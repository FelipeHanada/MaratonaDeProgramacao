#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int a = 0, b = 0;
  for (int i=0; i<n; i++) {
    if (i % 2) {
      if (s[i] == '0') b++;
      if (t[i] == '0') a++;
    } else {
      if (s[i] == '0') a++;
      if (t[i] == '0') b++;
    }
  }

  cout << (a >= (n+1)/2 && b >= n/2 ? "yes" : "no") << '\n';
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
