#include <bits/stdc++.h>
using namespace std;

#define ll long long

void precompute() {

}

void solve() {
  int n, m, h;
  cin >> n >> m >> h;
  vector<int> v(n), u(n);
  for (int i=0; i<n; i++) {
    cin >> v[i];
    u[i] = v[i];
  }
  vector<int> last_op(n, -1);
  int last_reset = -1;

  for (int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b; a--;

    if (last_reset > last_op[a]) u[a] = v[a];

    u[a] += b;
    if (u[a] > h) {
      last_reset = i;
      u[a] = v[a];
    }

    last_op[a] = i;
  }

  for (int i=0; i<n; i++) {
    if (last_reset > last_op[i]) u[i] = v[i];
  }
  
  for (int x : u) {
    cout << x << ' ';
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
