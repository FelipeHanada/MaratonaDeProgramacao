#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define first _1
#define second _2

void precompute() {
  
}
 
void solve() {
  int r, c;
  cin >> r >> c;

  if (r == c && r == 1) {
    cout << "0\n";
    return;
  }

  if (r <= c) {
    for (int i=1; i<=r; i++) {
      for (int j=1; j<=c; j++) {
        cout << i * (r + j) << ' ';
      }
      cout << '\n';
    }
  } else {
   for (int j=1; j<=r; j++) {
      for (int i=1; i<=c; i++) {
        cout << i * (c + j) << ' ';
      }
      cout << '\n';
    } 
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    precompute();
    solve();
    return 0;
}
